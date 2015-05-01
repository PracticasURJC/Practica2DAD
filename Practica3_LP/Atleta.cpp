#include "Atleta.h"
#include "Prueba.h"

Atleta::Atleta()
{

}

Atleta::~Atleta()
{

}

MultimapRegistrosAtleta Atleta::addRegistroPrueba(RegistroPrueba registro, Prueba* prueba)
{
    _registros.insert(std::pair<RegistroPrueba, SubTipoPrueba>(registro, prueba->getSubTipoPrueba()));

    prueba->addNuevaMarca(registro, m_atleta);

    return _registros;
}

void Atleta::mostrarRegistros()
{
    std::cout << "Registros para el atleta con nombre " << m_atleta->getNombreAtleta() << std::endl;
    for (auto& it : _registros)
        std::cout << it.first.toString() << " => " << Prueba::getNombreSubTipoPrueba(it.second) << std::endl;
}

std::string Atleta::toString() const
{
    std::ostringstream str;
    str << _nombre;
    if (_edad < 10)
        str << "0";
    str << ", Edad: " << _edad;
    str << ", Beca: " << _dineroBeca;
    return str.str();
}