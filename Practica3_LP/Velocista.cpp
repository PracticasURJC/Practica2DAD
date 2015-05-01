#include "Velocista.h"


Velocista::Velocista()
{
    m_atleta = this;
    _nombre = "";
    _edad = 0;
    _dineroBeca = 0;
    _registros.clear();
}

Velocista::Velocista(std::string nombre, int edad, int dineroBeca)
{
    m_atleta = this;
    _nombre = nombre;
    _edad = edad;
    _dineroBeca = dineroBeca;
    _registros.clear();
}

Velocista* Velocista::crearNuevoVelocista(std::string nombre, int edad, int dineroBeca)
{
    return new Velocista(nombre, edad, dineroBeca);
}

Velocista::~Velocista()
{
}
