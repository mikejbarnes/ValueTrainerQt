#ifndef SESSIONHANDLER_H
#define SESSIONHANDLER_H

#include <QObject>

class SessionHandler
{
    Q_OBJECT
    Q_PROPERTY(bool backgroundIsRandom READ backgroundIsRandom WRITE setBackgroundIsRandom NOTIFY backgroundIsRandomChanged FINAL)
    Q_PROPERTY(bool saturationIsRandom READ saturationIsRandom WRITE setSaturationIsRandom NOTIFY saturationIsRandomChanged FINAL)
    Q_PROPERTY(int saturationMin READ saturationMin WRITE setSaturationMin NOTIFY saturationMinChanged FINAL)
    Q_PROPERTY(int saturationMax READ saturationMax WRITE setSaturationMax NOTIFY saturationMaxChanged FINAL)
public:
    SessionHandler();

    bool backgroundIsRandom();
    bool saturationIsRandom();

    void setBackgroundIsRandom(bool backgroundIsRandom);
    void setSaturationIsRandom(bool saturationIsRandom);


public slots:


signals:
    void backgroundIsRandomChanged();
    void saturationIsRandomChanged();
    void saturationIsMinChagned();
    void saturationIsMaxChanged();


private:
    bool m_backgroundIsRandom;
    bool m_hueIsRandom;
    int m_hueMin;
    int m_hueMax;
    bool m_saturationIsRandom;
    int m_saturationMin;
    int m_saturationMax;
    int selections;
};

#endif // SESSIONHANDLER_H
