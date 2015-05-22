#include "Atleta.h"
#include "Prueba.h"

Atleta::Atleta()
{

}

Atleta::~Atleta()
{

}

Atleta::VectorRegistros Atleta::addRegistroPrueba(RegistroPrueba registro, Prueba* prueba)
{
    _registros.push_back(registro);

    prueba->addNuevaMarca(registro, m_atleta);

    return _registros;
}

void Atleta::mostrarRegistros()
{
    std::cout << "Registros para el atleta con nombre " << m_atleta->getNombreAtleta() << std::endl;
    for (Atleta::VectorRegistros::const_iterator itr = _registros.begin(); itr != _registros.end(); itr++)
        std::cout << (*itr).toString() << std::endl;
}

std::string Atleta::toString() const
{
    std::ostringstream str;
    str << _nombre;
    str << ", Edad: ";
    if (_edad < 10)
        str << "0";
    str << _edad;
    str << ", Beca: " << _dineroBeca;
    return str.str();
}

void Atleta::setTeam(URJCTeam* team)
{
    // Podemos no tener un team inicialmente
    if (_team)
        _team->eliminarIntegrante(m_atleta);

    _team = team;

    // Team puede ser null indicando que lo queremos dejar
    if (_team)
        _team->addNuevoIntegrante(m_atleta);
}

std::string RegistroPrueba::toString() const
{
    std::ostringstream str;
    str << "Fecha: " << _fecha.toString() << ", Tiempo: " << _resultado.toString() << ", Lugar: " << _lugar << ", Prueba: " << _prueba->getNombreSubTipoPrueba(_prueba->getSubTipoPrueba());
    return str.str();
}

TiempoRegistro Atleta::getPlusmarca(Prueba* prueba)
{
    for (Prueba::MultimapRegistrosPrueba::const_iterator itr = prueba->_marcas.begin(); itr != prueba->_marcas.end(); itr++)
    {
        RegistroPrueba registro = itr->first;
        if (registro._prueba->getSubTipoPrueba() != prueba->getSubTipoPrueba())
            continue;

        return registro._resultado;
    }
    return 0;
}
