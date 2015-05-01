#pragma once

#include "Prueba.h"

#include <string>
#include <map>
#include <iostream>
#include <sstream>

class Prueba;
enum TipoPrueba;
enum SubTipoPrueba;

enum BonusBecas:int
{
    BONUS_BECA_VELOCISTA        = 700,
    BONUS_BECA_MEDIOFONDISTA    = 500,
    BONUS_BECA_LANZADOR         = 250
};

struct Fecha
{
    int _dia;
    int _mes;
    int _ano;

    Fecha(int dia = 0, int mes = 0, int ano = 0) { _dia = dia; _mes = mes; _ano = ano; };

    std::string toString() const
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

    bool operator() (const TiempoRegistro& t1, const TiempoRegistro& t2) const
    {
        return (t1 < t2);
    }

    std::string toString() const
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

    RegistroPrueba(Fecha fecha, std::string lugar, TiempoRegistro resultado) { _fecha = fecha; _lugar = lugar; _resultado = resultado; };

    std::string toString() const
    {
        std::ostringstream str;
        str << "Fecha: " << _fecha.toString() << ", Tiempo: " << _resultado.toString() << ", Lugar: " << _lugar;
        return str.str();
    }
    
    bool operator>(const RegistroPrueba t) const
    {
        if (this->_resultado > t._resultado)
            return true;
        else if (this->_resultado == t._resultado && this->_resultado > t._resultado)
            return true;
        else if (this->_resultado == t._resultado && this->_resultado == t._resultado &&  this->_resultado > t._resultado)
            return true;
        else
            return false;
    }
    
    bool operator<(const RegistroPrueba t) const
    {
        return !(*this > t);
    }

    bool operator() (const RegistroPrueba& r1, const RegistroPrueba& r2) const
    {
        return (r1._resultado < r2._resultado);
    }
};

typedef std::multimap<RegistroPrueba, SubTipoPrueba> MultimapRegistrosAtleta;

#define PARTE_FIJA_BECA 500

class Atleta
{
public:

    Atleta();
    virtual ~Atleta();

    std::string getNombreAtleta() const { return _nombre; }
    void setNombreAtleta(std::string nombre) { _nombre = nombre; }

    int getEdadAtleta() const { return _edad; }
    void setEdadAtleta(int edad) { _edad = edad; }

    int getDineroBecaAtleta() const { return _dineroBeca; }
    void setDineroBecaAtleta(int bineroBeca) { _dineroBeca = bineroBeca; }

    MultimapRegistrosAtleta getRegistrosAtleta() const { return _registros; }

    MultimapRegistrosAtleta addRegistroPrueba(RegistroPrueba registro, Prueba* prueba);

    virtual void incrementarBeca() = 0;
    virtual void decrementarBeca() = 0;

    std::string toString() const;

    void mostrarRegistros();

protected:

    Atleta *m_atleta;       // Puntero a si mismo, para mejorar visibilidad del codigo

    std::string _nombre;
    int _edad;
    int _dineroBeca;
    MultimapRegistrosAtleta _registros;
};

