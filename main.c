#include <stdio.h>
#include <windows.h>
#include "menu.h"

int main(void) {
    int opcion;
    // Creamos la variable que guardará los datos durante todo el programa
    ParametrosOrbitales nave = {0.0, 0.0}; 

    SetConsoleOutputCP(CP_UTF8);

    do {
        mostrarMenu();
        opcion = leerOpcionValida(1, 5);

        switch (opcion) {
            case 1:
                // Le enviamos la dirección de memoria (&) de nuestra variable
                ingresarParametros(&nave);
                break;
            case 2:
                // Le pasamos una copia de los datos (sin el &)
                calcularAceleracion(nave);
                break;
            case 3:
                calcularPeriodoYFrecuencia(nave);
                break;
            case 4:
                evaluarEstabilidad(nave);
                break;
            case 5:
                printf("\nCerrando simulador Artemis. Misión finalizada.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
