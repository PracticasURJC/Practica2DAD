#include "URJCTeam.h"


URJCTeam::URJCTeam()
{
}


URJCTeam::~URJCTeam()
{
}

VectorAtletas URJCTeam::eliminarIntegrante(Atleta* atleta)
{
    VectorAtletas::const_iterator itr;
    for (itr = _atletas.begin(); itr != _atletas.end(); ++itr)
    {
        if (*itr == atleta)
            break;
    }
    if (itr != _atletas.end())
        _atletas.erase(itr);

    return _atletas;
}
