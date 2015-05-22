#include "URJCTeam.h"


URJCTeam::URJCTeam()
{
    m_team = this;
    _nombre = "";
    _atletas.clear();
    _becados.clear();
}

URJCTeam::URJCTeam(std::string nombre)
{
    m_team = this;
    _nombre = nombre;
    _atletas.clear();
    _becados.clear();
}

URJCTeam* URJCTeam::crearNuevoTeam(std::string nombre)
{
    return new URJCTeam(nombre);
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

void URJCTeam::mostrarIntegrantes()
{
    std::cout << "Lista de atletas del equipo " << m_team->_nombre << ":" << std::endl;
    for (VectorAtletas::const_iterator itr = _atletas.begin(); itr != _atletas.end(); itr++)
        std::cout << (*itr)->toString() << std::endl;
}

 void URJCTeam::nuevaPlusmarca(RegistroPrueba prueba, Atleta* atleta)
 {
     _becados[prueba._prueba->getSubTipoPrueba()] = atleta;
 }

 Atleta* URJCTeam::getBecadoPrueba(SubTipoPrueba subTipo)
 {
     if (_becados.find(subTipo) == _becados.end())
         return nullptr;

    return _becados.find(subTipo)->second;
 }