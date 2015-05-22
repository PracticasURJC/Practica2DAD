#include "Velocista.h"


Velocista::Velocista()
{
    m_atleta = this;
    _nombre = "";
    _edad = 0;
    _dineroBeca = 0;
    _team = nullptr;
    _registros.clear();
}

Velocista::Velocista(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    m_atleta = this;
    _nombre = nombre;
    _edad = edad;
    _dineroBeca = dineroBeca;
    _team = team;
    _team->addNuevoIntegrante(m_atleta);
    _registros.clear();
}

Velocista* Velocista::crearNuevoVelocista(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    return new Velocista(nombre, edad, team, dineroBeca);
}

Velocista::~Velocista()
{
}
