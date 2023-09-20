#include "appmanager.h"
#include <QDebug>

AppManager::AppManager(ColorHandler& colorHandler, QObject *parent)
    : QObject{parent}
    , m_sessionIsInProgress{ false }
    , m_correctGuesses{ 0 }
    , m_totalGuesses{ 0 }
    , m_roundsPerSession{ 25 }
    , m_colorHandler{ colorHandler }
{


    connect(this, &AppManager::answerSelected, this, &AppManager::onAnswerSelected);

}

int AppManager::roundsPerSession()
{
    return m_roundsPerSession;
}

void AppManager::setRoundsPerSession(int rounds)
{
    m_roundsPerSession = rounds;
    qDebug() << m_roundsPerSession;
}

void AppManager::prepareQuestion()
{
    m_colorHandler.chooseSessionColors();

    emit askQuestion();
}

void AppManager::onAnswerSelected(int selection)
{

}

void AppManager::onPrepareSession()
{

}
