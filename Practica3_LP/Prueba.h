#pragma once

#include "Atleta.h"
#include <map>
#include <iostream>

class Atleta;
struct RegistroPrueba;

enum TipoPrueba
{
    TIPO_VELOCISTA                      = 0,
    TIPO_MEDIOFONDISTA,
    TIPO_LANZADOR
};

enum SubTipoPrueba
{
    SUBTIPO_VELOCISTA_100M_LISOS        = 0,
    SUBTIPO_VELOCISTA_110M_VALLAS,
    SUBTIPO_VELOCISTA_200M_LISOS,
    SUBTIPO_VELOCISTA_200M_VALLAS,
    SUBTIPO_VELOCISTA_400M_LISOS,
    SUBTIPO_VELOCISTA_400M_VALLAS,

    SUBTIPO_MEDIOFONDISTA_800M_LISOS,
    SUBTIPO_MEDIOFONDISTA_1500M_LISOS,
    SUBTIPO_MEDIOFONDISTA_3000M_OBSTACULOS,

    SUBTIPO_LANZADOR_PESO,
    SUBTIPO_LANZADOR_MARTILLO,
    SUBTIPO_LANZADOR_JABALINA,
    SUBTIPO_LANZADOR_DISCO,

    MAX_TIPOS_PRUEBAS
};

typedef std::multimap<RegistroPrueba, Atleta*> MultimapRegistrosPrueba;

class Prueba
{
public:
    Prueba();
    Prueba(TipoPrueba tipo, SubTipoPrueba subTipo);
    ~Prueba();

    static Prueba* crearNuevaPrueba(TipoPrueba tipo, SubTipoPrueba subTipo);

    static std::string getNombreTipoPrueba(TipoPrueba tipo);
    static std::string getNombreSubTipoPrueba(SubTipoPrueba subTipo);

    TipoPrueba getTipoPrueba() const { return _tipo; }
    void setTipoPrueba(TipoPrueba tipo) { _tipo = tipo; }

    SubTipoPrueba getSubTipoPrueba() const { return _subTipo; }
    void setSubTipoPrueba(SubTipoPrueba subTipo) { _subTipo = subTipo; }

    MultimapRegistrosPrueba addNuevaMarca(RegistroPrueba registro, Atleta* atleta);

    void mostrarMarcasPrueba();

private:
    MultimapRegistrosPrueba _marcas;
    TipoPrueba _tipo;
    SubTipoPrueba _subTipo;

    Prueba* m_prueba;
};

