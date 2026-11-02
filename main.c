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
                // Imprimimos los valores para verificar que se guardaron
                printf("\n[En desarrollo] Calculando con Radio: %.2f y Vel: %.2f...\n", nave.radio, nave.velocidad);
                break;
            case 3:
                printf("\n[En desarrollo] Cálculo de periodo y frecuencia...\n");
                break;
            case 4:
                printf("\n[En desarrollo] Simulación de estabilidad...\n");
                break;
            case 5:
                printf("\nCerrando simulador Artemis. Misión finalizada.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}