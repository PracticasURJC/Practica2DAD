#pragma once

#include "Atleta.h"
#include <vector>

enum TipoPrueba:int
{
    TIPO_VELOCISTA          = 0,
    TIPO_MEDIOFONDISTA      = 1,
    TIPO_LANZADOR           = 2
};

class Prueba
{
public:
    Prueba();
    ~Prueba();
    Atleta* getPlusmarquista() { return *(_mejoresMarcas.begin()); }

    int getTipoPrueba() const { return _tipo; }
    void setTipoPrueba(int tipo) { _tipo = tipo; }

private:
    std::vector<Atleta*> _mejoresMarcas;
    int _tipo;
};

