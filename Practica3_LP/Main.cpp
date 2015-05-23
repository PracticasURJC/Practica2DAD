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
    std::cout << "INICIANDO APLICACION." << std::endl;
    srand(time(NULL));

    Prueba* lisos100 = Prueba::CrearNuevaPrueba(TIPO_VELOCISTA, SUBTIPO_VELOCISTA_100M_LISOS);
    Prueba* vallas110 = Prueba::CrearNuevaPrueba(TIPO_VELOCISTA, SUBTIPO_VELOCISTA_110M_VALLAS);
    Prueba* lisos200 = Prueba::CrearNuevaPrueba(TIPO_VELOCISTA, SUBTIPO_VELOCISTA_200M_LISOS);
    Prueba* vallas200 = Prueba::CrearNuevaPrueba(TIPO_VELOCISTA, SUBTIPO_VELOCISTA_200M_VALLAS);

    URJCTeam* informatica = URJCTeam::CrearNuevoTeam("Informatica");
    URJCTeam* derecho = URJCTeam::CrearNuevoTeam("Derecho");

    Velocista* carlos = Velocista::CrearNuevoVelocista("Carlos", 22, informatica);
    Velocista* tony = Velocista::CrearNuevoVelocista("Tony", 23, informatica);
    Velocista* david = Velocista::CrearNuevoVelocista("David", 22, informatica);

    for (int i = 0; i < 5; i++)
    {
        RegistroPrueba registro(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Madrid", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), lisos100);
        carlos->AddRegistroPrueba(registro);

        RegistroPrueba registro2(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Paris", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), vallas110);
        carlos->AddRegistroPrueba(registro2);
    }

    for (int i = 0; i < 5; i++)
    {
        RegistroPrueba registro(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Barcelona", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), lisos100);
        tony->AddRegistroPrueba(registro);

        RegistroPrueba registro2(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Pekin", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), vallas110);
        tony->AddRegistroPrueba(registro2);
    }
    
    for (int i = 0; i < 5; i++)
    {
        RegistroPrueba registro(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Madrid", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), lisos100);
        david->AddRegistroPrueba(registro);

        RegistroPrueba registro2(Fecha(rand() % 31, rand() % 13, rand() % 10 + 2000), "Paris", TiempoRegistro(rand() % 3, rand() % 60, rand() % 100), vallas110);
        david->AddRegistroPrueba(registro2);
    }

    carlos->MostrarRegistros();
    tony->MostrarRegistros();
    david->MostrarRegistros();

    lisos100->MostrarMarcasPrueba();
    vallas110->MostrarMarcasPrueba();
    lisos200->MostrarMarcasPrueba();
    vallas200->MostrarMarcasPrueba();

    informatica->MostrarIntegrantes();
    derecho->MostrarIntegrantes();

    carlos->SetTeam(nullptr);

    informatica->MostrarIntegrantes();
    derecho->MostrarIntegrantes();

    system("PAUSE");
    return 0;
}
