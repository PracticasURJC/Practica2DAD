#pragma once

#ifndef MEDIOFONDISTA_H
#define MEDIOFONDISTA_H

#include "Atleta.h"

class MedioFondista :
    public Atleta
{
public:
    MedioFondista();
    MedioFondista(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);
    ~MedioFondista();

    static MedioFondista* CrearNuevoMedioFondista(std::string nombre, int edad, URJCTeam* team, int dineroBeca = PARTE_FIJA_BECA);
    
    void IncrementarBeca() { SetDineroBecaAtleta(GetDineroBecaAtleta() + BONUS_BECA_MEDIOFONDISTA); }
    void DecrementarBeca() { SetDineroBecaAtleta(GetDineroBecaAtleta() - BONUS_BECA_MEDIOFONDISTA); }
};

#endif
