#include "Lanzador.h"


Lanzador::Lanzador()
{
}

Lanzador::Lanzador(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    m_atleta = this;
    _nombre = nombre;
    _edad = edad;
    _dineroBeca = dineroBeca;
    _team = team;
    _registros.clear();
}

Lanzador* Lanzador::crearNuevoLanzador(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    return new Lanzador(nombre, edad, team, dineroBeca);
}

Lanzador::~Lanzador()
{
}
