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

URJCTeam* URJCTeam::CrearNuevoTeam(std::string nombre)
{
    return new URJCTeam(nombre);
}

URJCTeam::~URJCTeam()
{
}

VectorAtletas URJCTeam::AddNuevoIntegrante(Atleta* atleta)
{
    _atletas.push_back(atleta);

    RecalcularBecados();

    return _atletas; 
}

VectorAtletas URJCTeam::EliminarIntegrante(Atleta* atleta)
{
    VectorAtletas::const_iterator itr;
    for (itr = _atletas.begin(); itr != _atletas.end(); ++itr)
    {
        if (*itr == atleta)
            break;
    }
    if (itr != _atletas.end())
        _atletas.erase(itr);

    RecalcularBecados();
    return _atletas;
}

void URJCTeam::MostrarIntegrantes()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Lista de atletas del equipo " << m_team->_nombre << ":" << std::endl;
    if (_atletas.empty())
        std::cout << "Equipo vacio." << std::endl;
    else
        for (VectorAtletas::const_iterator itr = _atletas.begin(); itr != _atletas.end(); itr++)
            std::cout << (*itr)->ToString() << std::endl;
}

 void URJCTeam::NuevaPlusmarca(RegistroPrueba prueba, Atleta* atleta)
 {
    _becados[prueba._prueba->GetSubTipoPrueba()] = atleta;
 }

 Atleta* URJCTeam::GetBecadoPrueba(SubTipoPrueba subTipo)
 {
    if (_becados.find(subTipo) == _becados.end())
        return nullptr;

    return _becados.find(subTipo)->second;
 }

 void URJCTeam::RecalcularBecados()
 {
    _becados.clear();
    for (int i = SUBTIPO_VELOCISTA_100M_LISOS; i < MAX_TIPOS_PRUEBAS; ++i)
    {
        Atleta* becado = nullptr;

        // Maximo tiempo que se puede registrar (1 hora)
        TiempoRegistro tiempo = TiempoRegistro(60,60,1000);

        for (VectorAtletas::const_iterator itr = _atletas.begin(); itr != _atletas.end(); ++itr)
        {
            Atleta* atleta = *itr;

            // Reiniciamos las becas
            atleta->SetDineroBecaAtleta(PARTE_FIJA_BECA);

            if (!atleta->HasPlusmarca(SubTipoPrueba(i)))
                continue;

            if (atleta->GetPlusmarca(SubTipoPrueba(i)) < tiempo)
            {
                tiempo = atleta->GetPlusmarca(SubTipoPrueba(i));
                becado = atleta;
            }
        }
        if (becado)
            _becados[SubTipoPrueba(i)] = becado;
    }

    for (MapaAtletas::const_iterator itr = _becados.begin(); itr != _becados.end(); ++itr)
    {
        (*itr).second->IncrementarBeca();
        std::cout << (*itr).second->GetNombreAtleta() << std::endl;
    }
 }
