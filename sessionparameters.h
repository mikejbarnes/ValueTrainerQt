#ifndef SESSIONPARAMETERS_H
#define SESSIONPARAMETERS_H


typedef struct params {
    params(
        bool hueRandom,
        int hueMin,
        int mueMax,
        bool saturationRandom,
        int saturationMin,
        int saturationMax,
        bool backgroundRandom,
        int selections):
        saturationRandom{ saturationRandom }
        , saturationMin{ saturationMin }
        , saturationMax{ saturationMax }
        , backgroundRandom{ backgroundRandom }
        , selections{ selections }
    {

    }

    bool hueRandom;
    int hueMin;
    int hueMax;
    bool saturationRandom;
    int saturationMin;
    int saturationMax;
    bool backgroundRandom;
    int selections;
} sessionParams;

#endif // SESSIONPARAMETERS_H
