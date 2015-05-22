#pragma once

#ifndef LANZADOR_H
#define LANZADOR_H

#include "Atleta.h"

class Lanzador :
    public Atleta
{
public:
    Lanzador();
    Lanzador(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);
    ~Lanzador();

    static Lanzador* crearNuevoLanzador(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);

    void incrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() + BONUS_BECA_LANZADOR); }
    void decrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() - BONUS_BECA_LANZADOR); }
};

#endif
