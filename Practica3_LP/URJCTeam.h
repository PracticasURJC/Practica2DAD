#pragma once

#include "Atleta.h"
#include "Prueba.h"

#include <vector>

class Atleta;
struct RegistroPrueba;

typedef std::vector<Atleta*> VectorAtletas;

class URJCTeam
{
public:
    URJCTeam();
    ~URJCTeam();

    VectorAtletas addNuevoIntegrante(Atleta* atleta) { _atletas.push_back(atleta); }
    VectorAtletas eliminarIntegrante(Atleta* atleta);

    void nuevaMarca(RegistroPrueba, Atleta*);

    //Atleta* getBecadoPrueba(SubTipoPrueba subTipo) { if (subTipo < MAX_TIPOS_PRUEBAS) return _becados[subTipo]; }

private:
    VectorAtletas _atletas;
    //Atleta* _becados[MAX_TIPOS_PRUEBAS];
};

