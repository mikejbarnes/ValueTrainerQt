#include "appmanager.h"
#include <QDebug>

AppManager::AppManager(QObject *parent)
    : QObject{parent}
    , m_swatches{ 13 }
    , m_correctMatches{ 0 }
    , m_totalMatches{ 0 }
    , m_roundsPerSession{ 25 }
{
    connect(this, &AppManager::answerSelected, this, &AppManager::onAnswerSelected);

}

int AppManager::swatches()
{
    return m_swatches;
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

void AppManager::onAnswerSelected(int selection)
{

}

void AppManager::onPrepareSession()
{

}
