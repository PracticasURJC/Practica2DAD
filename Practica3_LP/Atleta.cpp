#include "Atleta.h"
#include "Prueba.h"

Atleta::Atleta()
{

}

Atleta::~Atleta()
{

}

Atleta::VectorRegistros Atleta::AddRegistroPrueba(RegistroPrueba registro)
{
    _registros.push_back(registro);

    registro._prueba->AddNuevaMarca(registro, m_atleta);

    return _registros;
}

void Atleta::MostrarRegistros()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Registros para el atleta con nombre " << m_atleta->GetNombreAtleta() << std::endl;

    if(_registros.empty())
        std::cout<< "No hay registros del atleta " << m_atleta->GetNombreAtleta() << std::endl;
    else
        for (Atleta::VectorRegistros::const_iterator itr = _registros.begin(); itr != _registros.end(); itr++)
            std::cout << (*itr).ToString() << std::endl;
}

std::string Atleta::ToString() const
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

void Atleta::SetTeam(URJCTeam* team)
{
    // Podemos no tener un team inicialmente
    if (_team)
        _team->EliminarIntegrante(m_atleta);

    _team = team;

    // Team puede ser null indicando que lo queremos dejar
    if (_team)
        _team->AddNuevoIntegrante(m_atleta);
}

std::string RegistroPrueba::ToString() const
{
    std::ostringstream str;
    str << "Fecha: " << _fecha.ToString() << ", Tiempo: " << _resultado.ToString() << ", Lugar: " << _lugar << ", Prueba: " << _prueba->GetNombreSubTipoPrueba(_prueba->GetSubTipoPrueba());
    return str.str();
}

TiempoRegistro Atleta::GetPlusmarca(SubTipoPrueba subTipo)
{
    TiempoRegistro tiempo = TiempoRegistro();
    for (VectorRegistros::const_iterator itr = _registros.begin(); itr != _registros.end(); itr++)
    {
        RegistroPrueba registro = *itr;
        if (registro._prueba->GetSubTipoPrueba() != subTipo)
            continue;

        return registro._resultado;
    }
    return tiempo;
}

TiempoRegistro Atleta::GetPlusmarca(Prueba* prueba)
{
    TiempoRegistro tiempo = TiempoRegistro();
    for (Prueba::MultimapRegistrosPrueba::const_iterator itr = prueba->_marcas.begin(); itr != prueba->_marcas.end(); itr++)
    {
        RegistroPrueba registro = itr->first;
        if (registro._prueba->GetSubTipoPrueba() != prueba->GetSubTipoPrueba())
            continue;

        return registro._resultado;
    }
    return tiempo;
}
