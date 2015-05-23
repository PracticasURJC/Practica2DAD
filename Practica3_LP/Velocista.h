#pragma once

#ifndef VELOCISTA_H
#define VELOCISTA_H

#include "Atleta.h"

class Velocista :
    public Atleta
{
public:
    Velocista();
    Velocista(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);
    ~Velocista();

    static Velocista* CrearNuevoVelocista(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);
    
    void IncrementarBeca() { SetDineroBecaAtleta(GetDineroBecaAtleta() + BONUS_BECA_VELOCISTA); }
    void DecrementarBeca() { SetDineroBecaAtleta(GetDineroBecaAtleta() - BONUS_BECA_VELOCISTA); }

    std::string toString() const;
};

#endif
