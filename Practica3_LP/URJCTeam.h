#pragma once

#include "Atleta.h"

#include <vector>

typedef std::vector<Atleta*> VectorAtletas;

class URJCTeam
{
public:
    URJCTeam();
    ~URJCTeam();

    VectorAtletas addNuevoIntegrante(Atleta* atleta) { _atletas.push_back(atleta); }
    VectorAtletas eliminarIntegrante(Atleta* atleta);

private:
    VectorAtletas _atletas;
};

