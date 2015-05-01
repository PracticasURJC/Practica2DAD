#pragma once
#include "Atleta.h"

class Lanzador :
    public Atleta
{
public:
    Lanzador();
    ~Lanzador();

    void incrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() + BONUS_BECA_LANZADOR); }
    void decrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() - BONUS_BECA_LANZADOR); }
};

