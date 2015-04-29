#include "Atleta.h"

Atleta::Atleta()
{
    _nombre = "";
    _edad = 0;
    _dineroBeca = 0;
    m_atleta = this;
    _registros.clear();
}

Atleta::Atleta(std::string nombre, int edad, int dineroBeca /*= 0*/)
{
    _nombre = nombre;
    _edad = edad;
    _dineroBeca = dineroBeca;
    m_atleta = this;
    _registros.clear();
}

Atleta::~Atleta()
{

}

Atleta* Atleta::crearNuevoAtleta(std::string nombre, int edad, int dineroBeca /*= 0*/)
{
    Atleta* atleta = new Atleta(nombre, edad, dineroBeca);
    return atleta;
}

std::vector<RegistroPrueba> Atleta::addRegistroPrueba(RegistroPrueba const registro)
{
}
