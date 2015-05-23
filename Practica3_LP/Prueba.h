#pragma once

#ifndef PRUEBA_H
#define PRUEBA_H

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


class Prueba
{
public:

    typedef std::multimap<RegistroPrueba, Atleta*> MultimapRegistrosPrueba;

    Prueba();
    Prueba(TipoPrueba tipo, SubTipoPrueba subTipo);
    ~Prueba();

    static Prueba* CrearNuevaPrueba(TipoPrueba tipo, SubTipoPrueba subTipo);

    static std::string GetNombreTipoPrueba(TipoPrueba tipo);
    static std::string GetNombreSubTipoPrueba(SubTipoPrueba subTipo);

    TipoPrueba GetTipoPrueba() const { return _tipo; }
    void SetTipoPrueba(TipoPrueba tipo) { _tipo = tipo; }

    SubTipoPrueba GetSubTipoPrueba() const { return _subTipo; }
    void SetSubTipoPrueba(SubTipoPrueba subTipo) { _subTipo = subTipo; }

    MultimapRegistrosPrueba AddNuevaMarca(RegistroPrueba registro, Atleta* atleta);

    MultimapRegistrosPrueba GetMarcas() const { return _marcas; }

    void MostrarMarcasPrueba();
    MultimapRegistrosPrueba _marcas;

private:
    TipoPrueba _tipo;
    SubTipoPrueba _subTipo;

    Prueba* m_prueba;
};

#endif
