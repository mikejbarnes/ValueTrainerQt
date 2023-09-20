#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include "colorhandler.h"

class AppManager : public QObject
{
    Q_OBJECT

public:
    explicit AppManager(ColorHandler& colorHandler, QObject *parent = nullptr);

    Q_INVOKABLE int roundsPerSession();

    Q_INVOKABLE void setRoundsPerSession(int rounds);
    Q_INVOKABLE void prepareQuestion();

public slots:
    void onAnswerSelected(int selection);
    void onPrepareSession();

signals:
    void answerSelected(int selection);
    void askQuestion();
    void showAnswer();

private:
    bool m_sessionIsInProgress;
    int m_correctGuesses;
    int m_totalGuesses;

    int m_roundsPerSession;

    ColorHandler& m_colorHandler;
};

#endif // APPMANAGER_H
