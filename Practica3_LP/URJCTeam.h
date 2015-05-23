#pragma once

#ifndef URJCTEAM_H
#define URJCTEAH_H

#include "Atleta.h"
#include "Prueba.h"

#include <vector>
#include <map>

class Atleta;
struct RegistroPrueba;
enum SubTipoPrueba;

typedef std::vector<Atleta*> VectorAtletas;
typedef std::map<SubTipoPrueba, Atleta*>  MapaAtletas;

class URJCTeam
{
public:
    URJCTeam();
    URJCTeam(std::string nombre);
    ~URJCTeam();

    static URJCTeam* CrearNuevoTeam(std::string nombre);

    VectorAtletas AddNuevoIntegrante(Atleta* atleta);
    VectorAtletas EliminarIntegrante(Atleta* atleta);

    void NuevaPlusmarca(RegistroPrueba prueba, Atleta* atleta);

    void MostrarIntegrantes();

    Atleta* GetBecadoPrueba(SubTipoPrueba subTipo);

    void RecalcularBecados();

private:
    URJCTeam* m_team;
    std::string _nombre;
    VectorAtletas _atletas;
    MapaAtletas _becados;
};

#endif
