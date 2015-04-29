#pragma once

#include <string>
#include <vector>

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

    Fecha(int dia, int mes, int ano) { _dia = dia; _mes = mes; _ano = ano; }
};

struct RegistroPrueba
{
    Fecha _fecha;
    std::string _lugar;
    int _resultado = 0;

    RegistroPrueba(Fecha fecha, std::string lugar, int resultado) { _fecha = fecha; _lugar = lugar; _resultado = resultado; };
};

class Atleta
{
public:

    Atleta();
    Atleta(std::string nombre, int edad, int dineroBeca = 0);
    Atleta(const Atleta& atleta);
    virtual ~Atleta();

    Atleta *crearNuevoAtleta(std::string nombre, int edad, int dineroBeca = 0);

    std::string getNombreAtleta() const { return _nombre; }
    void setNombreAtleta(std::string nombre) { _nombre = nombre; }

    int getEdadAtleta() const { return _edad; }
    void setEdadAtleta(int edad) { _edad = edad; }

    int getDineroBecaAtleta() const { return _dineroBeca; }
    void setDineroBecaAtleta(int bineroBeca) { _dineroBeca = bineroBeca; }

    std::vector<RegistroPrueba> getRegistrosAtleta() const { return _registros; }

    std::vector<RegistroPrueba> addRegistroPrueba(RegistroPrueba const registro);

private:

    Atleta *m_atleta;       // Puntero a si mismo, para mejorar visibilidad del codigo

    std::string _nombre;
    int _edad;
    int _dineroBeca;
    std::vector<RegistroPrueba> _registros;
};

