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

Prueba* Prueba::CrearNuevaPrueba(TipoPrueba tipo, SubTipoPrueba subTipo)
{
    return new Prueba(tipo, subTipo);
}

std::string Prueba::GetNombreTipoPrueba(TipoPrueba tipo)
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

std::string Prueba::GetNombreSubTipoPrueba(SubTipoPrueba subTipo)
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

Prueba::MultimapRegistrosPrueba Prueba::AddNuevaMarca(RegistroPrueba registro, Atleta* atleta)
{
    if (!atleta)
    {
        std::cout << "ERROR: Atleta no definido." << std::endl;
        return _marcas;
    }

    _marcas.insert(std::pair<RegistroPrueba, Atleta*>(registro, atleta));

    if (atleta->GetTeam())
    {
        Atleta* becado = atleta->GetTeam()->GetBecadoPrueba(registro._prueba->GetSubTipoPrueba());
        
        // Si existe becado lo usamos para comprar marcas, en caso de que no exista, añadimos la plusmarca directamente y la beca
        if (becado)
        {
            // Si el nuevo plusmarquista es un atleta distinto al anterior, modificamos las becas.
            if (becado != atleta)
            {
                if (registro._resultado < becado->GetPlusmarca(registro._prueba))
                {
                    atleta->GetTeam()->NuevaPlusmarca(registro, atleta);
                    atleta->IncrementarBeca();
                    becado->DecrementarBeca();
                    std::cout << "Aumentada beca de " << atleta->GetNombreAtleta() << ", disminuida beca de " << becado->GetNombreAtleta() << std::endl;
                }
            }
            // En caso de que sea el mismo plusmarquista (mejora de marca), actualizamos la marca pero no aumentamos la beca
            else if (registro._resultado < atleta->GetPlusmarca(registro._prueba))
            {
                atleta->GetTeam()->NuevaPlusmarca(registro, atleta);
                std::cout << "Actualizada marca de " << atleta->GetNombreAtleta() << std::endl;
            }
        }
        else
        {
            atleta->GetTeam()->NuevaPlusmarca(registro, atleta);
            atleta->IncrementarBeca();
            std::cout << "Aumentada beca de " << atleta->GetNombreAtleta() << std::endl;
        }
    }
    else
        std::cout << "ERROR: Intentando añadir una marca a un atleta sin equipo." << std::endl;

    return _marcas;
}

void Prueba::MostrarMarcasPrueba()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Registro de marcas para la prueba " << Prueba::GetNombreTipoPrueba(m_prueba->GetTipoPrueba()) << std::endl;
    if (_marcas.empty())
        std::cout << "No hay marcas para la prueba " << Prueba::GetNombreTipoPrueba(m_prueba->GetTipoPrueba()) << " Subtipo " << Prueba::GetNombreSubTipoPrueba(m_prueba->GetSubTipoPrueba()) << std::endl;
    else
        for(Prueba::MultimapRegistrosPrueba::const_iterator itr = _marcas.begin(); itr != _marcas.end(); ++itr)
            std::cout << (*itr).first.ToString() << " => " << (*itr).second->GetNombreAtleta() << std::endl;
}
