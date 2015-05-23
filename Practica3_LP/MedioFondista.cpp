#include "MedioFondista.h"


MedioFondista::MedioFondista()
{
    m_atleta = this;
    _nombre = "";
    _edad = 0;
    _dineroBeca = 0;
    _team = nullptr;
    _registros.clear();
}

MedioFondista::MedioFondista(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    m_atleta = this;
    _nombre = nombre;
    _edad = edad;
    _dineroBeca = dineroBeca;
    _team = team;
    _registros.clear();
}

MedioFondista* MedioFondista::CrearNuevoMedioFondista(std::string nombre, int edad, URJCTeam* team, int dineroBeca)
{
    return new MedioFondista(nombre, edad, team, dineroBeca);
}

MedioFondista::~MedioFondista()
{
}
