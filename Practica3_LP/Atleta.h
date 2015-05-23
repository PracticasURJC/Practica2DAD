#pragma once

#ifndef ATLETA_H
#define ATLETA_H

#include "Prueba.h"
#include "URJCTeam.h"

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

class URJCTeam;
class Prueba;

enum TipoPrueba;
enum SubTipoPrueba;

enum BonusBecas
{
    BONUS_BECA_VELOCISTA        = 700u,
    BONUS_BECA_MEDIOFONDISTA    = 500u,
    BONUS_BECA_LANZADOR         = 250u
};

struct Fecha
{
    int _dia;
    int _mes;
    int _ano;

    Fecha(int dia = 0, int mes = 0, int ano = 0) { _dia = dia; _mes = mes; _ano = ano; };
    
    bool operator>(const Fecha t) const
    {
        if (this->_ano > t._ano)
            return true;
        else if (this->_ano == t._ano && this->_mes > t._mes)
            return true;
        else if (this->_ano == t._ano && this->_mes == t._mes &&  this->_dia > t._dia)
            return true;
        else
            return false;
    }

    bool operator<(const Fecha t) const
    {
        return !(*this > t);
    }

    std::string ToString() const
    {
        std::ostringstream str;
        if (_dia < 10)
            str << "0";
        str << _dia << "/";
        if (_mes < 10)
            str << "0";
        str << _mes << "/";
        str << _ano;
        return str.str();
    }
};

struct TiempoRegistro
{
    int _min;
    int _sec;
    int _milli;

    TiempoRegistro(int min = 0, int sec = 0, int milli = 0) { _min = min; _sec = sec; _milli = milli; };

    bool operator>(const TiempoRegistro t) const
    {
        if (this->_min > t._min)
            return true;
        else if (this->_min == t._min && this->_sec > t._sec)
            return true;
        else if (this->_min == t._min && this->_sec == t._sec &&  this->_milli > t._milli)
            return true;
        else
            return false;
    }

    bool operator<(const TiempoRegistro t) const
    {
        return !(*this > t);
    }

    bool operator==(const TiempoRegistro t) const
    {
        return (_min == t._min && _sec == t._sec && _milli == t._milli);
    }

    bool operator!=(const TiempoRegistro t) const
    {
        return !(*this == t);
    }

    bool operator() (const TiempoRegistro& t1, const TiempoRegistro& t2) const
    {
        return (t1 < t2);
    }

    std::string ToString() const
    {
        std::ostringstream str;
        str << _min << "'";
        if (_sec < 10)
            str << "0";
        str << _sec << "''";
        if (_milli < 10)
            str << "0";
        str << _milli;
        return str.str();
    }
};

struct RegistroPrueba
{
    Fecha _fecha;
    std::string _lugar;
    TiempoRegistro _resultado;
    Prueba* _prueba;

    RegistroPrueba(Fecha fecha, std::string lugar, TiempoRegistro resultado, Prueba* prueba) { _fecha = fecha; _lugar = lugar; _resultado = resultado; _prueba = prueba; };

    std::string ToString() const;

    bool operator>(const RegistroPrueba t) const
    {
        return (this->_resultado > t._resultado || (this->_resultado == t._resultado && this->_fecha < t._fecha));
    }
    
    bool operator<(const RegistroPrueba t) const
    {
        return !(*this > t);
    }
};

#define PARTE_FIJA_BECA 500

class Atleta
{
public:
    typedef std::vector<RegistroPrueba> VectorRegistros;

    Atleta();
    virtual ~Atleta();

    std::string GetNombreAtleta() const { return _nombre; }
    void SetNombreAtleta(std::string nombre) { _nombre = nombre; }

    int GetEdadAtleta() const { return _edad; }
    void SetEdadAtleta(int edad) { _edad = edad; }

    int GetDineroBecaAtleta() const { return _dineroBeca; }
    void SetDineroBecaAtleta(int bineroBeca) { _dineroBeca = bineroBeca; }

    URJCTeam* GetTeam() const { return _team; }
    void SetTeam(URJCTeam* team);

    VectorRegistros GetRegistrosAtleta() const { return _registros; }

    VectorRegistros AddRegistroPrueba(RegistroPrueba registro);
    
    TiempoRegistro GetPlusmarca(SubTipoPrueba subTipo);
    TiempoRegistro GetPlusmarca(Prueba* prueba);

    bool HasPlusmarca(Prueba* prueba) { return GetPlusmarca(prueba) != TiempoRegistro(); }
    bool HasPlusmarca(SubTipoPrueba subTipo) { return GetPlusmarca(subTipo) != TiempoRegistro(); }

    virtual void IncrementarBeca() = 0;
    virtual void DecrementarBeca() = 0;

    std::string ToString() const;

    void MostrarRegistros();

protected:

    Atleta *m_atleta;       // Puntero a si mismo, para mejorar visibilidad del codigo

    std::string _nombre;
    int _edad;
    int _dineroBeca;
    VectorRegistros _registros;
    URJCTeam* _team;
};

#endif
