#include "Atleta.h"
#include "Velocista.h"
#include "Lanzador.h"
#include "MedioFondista.h"
#include "Prueba.h"
#include "URJCTeam.h"
#include <iostream>
#include <random>
#include <time.h>

int main( int argc, const char* argv[])
{
    srand(time(NULL));

    Prueba* prueba = Prueba::crearNuevaPrueba(TIPO_VELOCISTA, SUBTIPO_VELOCISTA_100M_LISOS);
    URJCTeam* team = URJCTeam::crearNuevoTeam("Informatica");

    Velocista* carlos = Velocista::crearNuevoVelocista("Carlos", 6, team);
    Velocista* tony = Velocista::crearNuevoVelocista("Tony", 23, team);

    for (int i = 0; i < 5; i++)
    {
        RegistroPrueba registro(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Madrid", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), prueba);
        carlos->addRegistroPrueba(registro, prueba);
    }

    for (int i = 0; i < 5; i++)
    {
        RegistroPrueba registro(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Barcelona", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), prueba);
        tony->addRegistroPrueba(registro, prueba);
    }

    carlos->mostrarRegistros();
    tony->mostrarRegistros();
    prueba->mostrarMarcasPrueba();

    team->mostrarIntegrantes();
    carlos->setTeam(nullptr);
    team->mostrarIntegrantes();

    system("PAUSE");
    return 0;
}