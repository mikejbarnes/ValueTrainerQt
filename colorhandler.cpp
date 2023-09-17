#include "colorhandler.h"
#include <Random>
#include <QDebug>

ColorHandler::ColorHandler(QObject *parent)
    : QObject{parent}
    , m_targetColorHSL{ hsl(0.0, 0.0, 0.0) }
    , m_targetColorHex{ QString() }
    , m_colorSelectionsHex{ QStringList() }
    , m_sections{ 7 }
    , m_backgroundIsRandom{ false }
    , m_hueIsRandom{ false }
    , m_hueMin{ 0.0 }
    , m_hueMax{ 360.0 }
    , m_saturationIsRandom{ false }
    , m_saturationMin{ 0.0 }
    , m_saturationMax{ 1.0 }
{
    connect(this, &ColorHandler::backgroundIsRandom, this, &ColorHandler::onBackgroundIsRandom);
    connect(this, &ColorHandler::hueIsRandom, this, &ColorHandler::onHueIsRandom);
    connect(this, &ColorHandler::saturationIsRandom, this, &ColorHandler::onSaturationIsRandom);
}

QString ColorHandler::targetColor()
{
    return m_targetColorHex;
}

QString ColorHandler::backgroundColor()
{
    return m_backgroundColorHex;
}

QStringList ColorHandler::colorSelections()
{
    return m_colorSelectionsHex;
}

int ColorHandler::colorSections()
{
    return m_sections;
}

void ColorHandler::setColorSections(int sections)
{
    qDebug() << sections;
    m_sections = sections;
}

void ColorHandler::onStartSession()
{

}

void ColorHandler::onBackgroundIsRandom()
{
    m_backgroundIsRandom = !m_backgroundIsRandom;
}

void ColorHandler::onHueIsRandom()
{
    m_hueIsRandom = !m_hueIsRandom;
}

void ColorHandler::onSaturationIsRandom()
{
    m_saturationIsRandom = !m_saturationIsRandom;
}

void ColorHandler::onSaturationMinChanged(int value)
{
    m_saturationMin = value;
    qDebug() << m_saturationMin;
}

void ColorHandler::onSaturationMaxChanged(int value)
{
    m_saturationMax = value;
    qDebug() << m_saturationMax;
}

void ColorHandler::calculateColorSelections(int selections)
{
    m_colorSelectionsHex = QStringList();

    double lInterval = 1.0 / (selections - 1);
    qDebug() << lInterval;
    for(int i{ 0 }; i < selections; ++i)
    {
        QString colorHex = convertToHex(hsl(m_targetColorHSL.h, m_targetColorHSL.s, 1 - i*lInterval));
        m_colorSelectionsHex.append(colorHex);
    }
}

ColorHandler::hsl ColorHandler::chooseColor(int selections)
{
    std::random_device rd;
    std::mt19937 generator;
    generator.seed(rd());

    std::uniform_int_distribution<int> hGenerator(m_hueMin, m_hueMax);
    std::uniform_int_distribution<int> sGenerator(0, selections);
    std::uniform_int_distribution<int> lGenerator(0, selections);

    double h = static_cast<double>(hGenerator(generator));
    double s = (static_cast<double>(sGenerator(generator)) / selections);
    double l = static_cast<double>(lGenerator(generator)) / selections;

    return hsl(h, s, l);
}

void ColorHandler::chooseSessionColors(int selections)
{
    m_targetColorHSL = chooseColor(selections);
    m_targetColorHex = convertToHex(m_targetColorHSL);

    if(m_backgroundIsRandom)
    {
        do
        {
            m_backgroundColorHex = convertToHex(chooseColor(selections));
        }
        while(m_backgroundColorHex == m_targetColorHex);
    }
    else
    {
        m_backgroundColorHex = "#FFFFFF";
    }

    calculateColorSelections(selections);
}

ColorHandler::rgb ColorHandler::convertToRGB(hsl colorHSL)
{
    double c = (1 - std::abs(2*colorHSL.l - 1)) * colorHSL.s;
    double hPrime = colorHSL.h / 60;
    double x = c * (1 - std::abs((static_cast<int>(hPrime) % 2) - 1));

    int hFloor = std::floor(hPrime);

    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    switch(hFloor)
    {
        case 0:
            r = c;
            g = x;
            break;
        case 1:
            r = x;
            g = c;
            break;
        case 2:
            g = c;
            b = x;
            break;
        case 3:
            g = x;
            b = c;
            break;
        case 4:
            r = x;
            b = c;
            break;
        case 5:
            r = c;
            b = x;
            break;
    }

    double m = colorHSL.l - (c / 2);

    int finalR = static_cast<int>(round(255 * (r + m) / 2) * 2);
    int finalG = static_cast<int>(round(255 * (g + m) / 2) * 2);
    int finalB = static_cast<int>(round(255 * (b + m) / 2) * 2);

    return rgb(finalR, finalG, finalB);
}

QString ColorHandler::convertToHex(hsl colorHSL)
{
    rgb colorRGB = convertToRGB(colorHSL);

    QString rHex = QString("%1").arg(colorRGB.r, 2, 16);
    QString gHex = QString("%1").arg(colorRGB.g, 2, 16);
    QString bHex = QString("%1").arg(colorRGB.b, 2, 16);

    return QString("#%1%2%3").arg(rHex, gHex, bHex);
}
