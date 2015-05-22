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

    static URJCTeam* crearNuevoTeam(std::string nombre);

    VectorAtletas addNuevoIntegrante(Atleta* atleta) { _atletas.push_back(atleta); return _atletas; }
    VectorAtletas eliminarIntegrante(Atleta* atleta);

    void nuevaPlusmarca(RegistroPrueba prueba, Atleta* atleta);

    void mostrarIntegrantes();

    Atleta* getBecadoPrueba(SubTipoPrueba subTipo);

private:
    URJCTeam* m_team;
    std::string _nombre;
    VectorAtletas _atletas;
    MapaAtletas _becados;
};

#endif
