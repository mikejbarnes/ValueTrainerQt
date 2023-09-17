#include "sessionhandler.h"

sessionhandler::sessionhandler()
{

}

bool sessionhandler::backgroundIsRandom()
{
    return m_backgroundIsRandom;
}

bool sessionhandler::saturationIsRandom()
{
    return m_saturationIsRandom;
}

void sessionhandler::setBackgroundIsRandom(bool backgroundIsRandom)
{
    if(m_backgroundIsRandom != backgroundIsRandom)
    {
        m_backgroundIsRandom = backgroundIsRandom;
        emit backgroundIsRandomChanged
    }
}

void sessionhandler::setSaturationIsRandom(bool saturationIsRandom)
{
    if(m_saturationIsRandom != saturationIsRandom)
    {
        m_saturationIsRandom = saturationIsRandom;
        emit saturationIsRandomChanged;
    }
}

