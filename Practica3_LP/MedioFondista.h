#pragma once
#include "Atleta.h"

class MedioFondista :
    public Atleta
{
public:
    MedioFondista();
    ~MedioFondista();
    
    void incrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() + BONUS_BECA_MEDIOFONDISTA); }
    void decrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() - BONUS_BECA_MEDIOFONDISTA); }
};

