#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int swatches READ swatches NOTIFY swatchesChanged FINAL)

public:
    explicit AppManager(QObject *parent = nullptr);
    int swatches();
    QStringList swatchColors();

    void setSwatches(int tiles);

    Q_INVOKABLE int roundsPerSession();

    Q_INVOKABLE void setRoundsPerSession(int rounds);

public slots:
    void onAnswerSelected(int selection);
    void onPrepareSession();

signals:
    void swatchesChanged(int swatches);

    void answerSelected(int selection);
    void prepareSession();
    void startSession();

private:
    int m_swatches;
    int m_correctMatches;
    int m_totalMatches;

    int m_roundsPerSession;


};

#endif // APPMANAGER_H
