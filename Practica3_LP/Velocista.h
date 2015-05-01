#pragma once
#include "Atleta.h"

class Velocista :
    public Atleta
{
public:
    Velocista();
    Velocista(std::string nombre, int edad, int dineroBeca = PARTE_FIJA_BECA);
    ~Velocista();

    static Velocista* crearNuevoVelocista(std::string nombre, int edad, int dineroBeca = PARTE_FIJA_BECA);
    
    void incrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() + BONUS_BECA_VELOCISTA); }
    void decrementarBeca() { setDineroBecaAtleta(getDineroBecaAtleta() - BONUS_BECA_VELOCISTA); }

    std::string toString() const;
};

