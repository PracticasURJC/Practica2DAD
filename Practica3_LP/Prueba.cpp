#include "Prueba.h"

Prueba::Prueba()
{
    _tipo = TIPO_VELOCISTA;
    _subTipo = SUBTIPO_VELOCISTA_100M_LISOS;
    _marcas.clear();
    m_prueba = this;
}

Prueba::Prueba(TipoPrueba tipo, SubTipoPrueba subTipo)
{
    _tipo = tipo;
    _subTipo = subTipo;
    _marcas.clear();
    m_prueba = this;
}

Prueba::~Prueba()
{
}

Prueba* Prueba::crearNuevaPrueba(TipoPrueba tipo, SubTipoPrueba subTipo)
{
    Prueba *prueba = new Prueba(tipo, subTipo);
    return prueba;
}

std::string Prueba::getNombreTipoPrueba(TipoPrueba tipo)
{
    switch(tipo)
    {
    case TIPO_VELOCISTA:
        return "TIPO_VELOCISTA";
    case TIPO_MEDIOFONDISTA:
        return "TIPO_MEDIOFONDISTA";
    case TIPO_LANZADOR:
        return "TIPO_LANZADOR";
    }
    return "UNKNOWN";
}

std::string Prueba::getNombreSubTipoPrueba(SubTipoPrueba subTipo)
{
    switch(subTipo)
    {
    case SUBTIPO_VELOCISTA_100M_LISOS:
        return "VELOCISTA_100M_LISOS";
    case SUBTIPO_VELOCISTA_110M_VALLAS:
        return "VELOCISTA_110M_VALLAS";
    case SUBTIPO_VELOCISTA_200M_LISOS:
        return "VELOCISTA_200M_LISOS";
    case SUBTIPO_VELOCISTA_200M_VALLAS:
        return "VELOCISTA_200M_VALLAS";
    case SUBTIPO_VELOCISTA_400M_LISOS:
        return "VELOCISTA_400M_LISOS";
    case SUBTIPO_VELOCISTA_400M_VALLAS:
        return "VELOCISTA_400M_VALLAS";
    case SUBTIPO_MEDIOFONDISTA_800M_LISOS:
        return "MEDIOFONDISTA_800M_LISOS";
    case SUBTIPO_MEDIOFONDISTA_1500M_LISOS:
        return "MEDIOFONDISTA_1500M_LISOS";
    case SUBTIPO_MEDIOFONDISTA_3000M_OBSTACULOS:
        return "MEDIOFONDISTA_3000M_OBSTACULOS";
    case SUBTIPO_LANZADOR_DISCO:
        return "LANZADOR_DISCO";
    case SUBTIPO_LANZADOR_JABALINA:
        return "LANZADOR_JABALINA";
    case SUBTIPO_LANZADOR_MARTILLO:
        return "LANZADOR_MARTILLO";
    case SUBTIPO_LANZADOR_PESO:
        return "LANZADOR_PESO";
    }
    return "UNKNOWN";
}

Prueba::MultimapRegistrosPrueba Prueba::addNuevaMarca(RegistroPrueba registro, Atleta* atleta)
{
    if (!atleta)
    {
        std::cout << "Atleta no encontrado (NULL)" << std::endl;
        return _marcas;
    }

    // En caso de estar vacio el registro de atletas, el primero que tenga una marca ganara el bonus de beca.
    if (_marcas.empty())
    {
        _marcas.insert(std::pair<RegistroPrueba, Atleta*>(registro, atleta));

        if (atleta->getTeam())
        {
            atleta->getTeam()->nuevaPlusmarca(registro, atleta);
            atleta->incrementarBeca();
        }
    }
    else
    {
        _marcas.insert(std::pair<RegistroPrueba, Atleta*>(registro, atleta));
        
        if (atleta->getTeam())
        {
            Atleta* becado = atleta->getTeam()->getBecadoPrueba(registro._prueba->getSubTipoPrueba());
            // Si el nuevo plusmarquista es un atleta distinto al anterior, modificamos las becas.
            if (becado != atleta)
            {
                std::cout << "Beca " << becado->getNombreAtleta() << ": " << becado->getDineroBecaAtleta() << "Beca " << atleta->getNombreAtleta() << ": " << atleta->getDineroBecaAtleta() << std::endl;
                if (becado && registro._resultado < becado->getPlusmarca(registro._prueba))
                {
                    atleta->getTeam()->nuevaPlusmarca(registro, atleta);
                    atleta->incrementarBeca();
                    becado->decrementarBeca();
                }
                else if (!becado)
                    atleta->incrementarBeca();

                std::cout << "Beca " << becado->getNombreAtleta() << ": " << becado->getDineroBecaAtleta() << "Beca " << atleta->getNombreAtleta() << ": " << atleta->getDineroBecaAtleta() << std::endl;
            }
        }
    }
    return _marcas;
}

void Prueba::mostrarMarcasPrueba()
{
    std::cout << "Registro de marcas para la prueba " << Prueba::getNombreTipoPrueba(m_prueba->getTipoPrueba()) << std::endl;
    for(Prueba::MultimapRegistrosPrueba::const_iterator itr = _marcas.begin(); itr != _marcas.end(); ++itr)
        std::cout << (*itr).first.toString() << " => " << (*itr).second->getNombreAtleta() << std::endl;
}
