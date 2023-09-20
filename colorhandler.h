#ifndef COLORHANDLER_H
#define COLORHANDLER_H

#include <QObject>

class ColorHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString targetColor READ targetColor NOTIFY targetColorChanged FINAL)
    Q_PROPERTY(QString backgroundColor READ backgroundColor  NOTIFY backgroundColorChanged FINAL)
    Q_PROPERTY(QStringList colorSelections READ colorSelections NOTIFY colorSelectionsChanged FINAL)
    //Q_PROPERTY(int colorSections READ colorSections WRITE setColorSections)

public:
    explicit ColorHandler(QObject *parent = nullptr);

    QString targetColor();
    QString backgroundColor();
    QStringList colorSelections();
    Q_INVOKABLE int colorSections();
    Q_INVOKABLE int saturationMin();
    Q_INVOKABLE int saturationMax();

    Q_INVOKABLE void setColorSections(int sections);

    void chooseSessionColors();

public slots:
    void onStartSession();

    void onBackgroundIsRandom();
    void onHueIsRandom();
    void onSaturationIsRandom();
    void onSaturationMinChanged(int value);
    void onSaturationMaxChanged(int value);

signals:
    void startSession();

    void targetColorChanged();
    void backgroundColorChanged();
    void colorSelectionsChanged();

    void backgroundIsRandom();
    void hueIsRandom();
    void saturationIsRandom();

private:
    typedef struct hslStruct {
        hslStruct(double h, double s, double l)
        {
            this->h = h;
            this->s = s;
            this->l = l;
        }

        double h;
        double s;
        double l;
    } hsl;

    typedef struct rgbStruct {
        rgbStruct(int r, int g, int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        int r;
        int g;
        int b;
    } rgb;

    hsl m_targetColorHSL;
    QString m_targetColorHex;
    QString m_backgroundColorHex;
    QStringList m_colorSelectionsHex;

    int m_sections;

    bool m_backgroundIsRandom;
    bool m_hueIsRandom;
    double m_hueMin;
    double m_hueMax;
    bool m_saturationIsRandom;
    double m_saturationMin;
    double m_saturationMax;

    hsl chooseColor();
    void calculateColorSelections();
    rgb convertToRGB(hsl colorHSL);
    QString convertToHex(hsl colorHSL);
};

#endif // COLORHANDLER_H
