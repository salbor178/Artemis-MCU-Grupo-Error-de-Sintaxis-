#include <stdio.h>
#include <windows.h> // Necesario para SetConsoleOutputCP
#include "menu.h"

int main(void) {
    int opcion;

    // Configurar la consola para que entienda UTF-8
    SetConsoleOutputCP(CP_UTF8);

    do {
        mostrarMenu();
        opcion = leerOpcionValida(1, 5);

        switch (opcion) {
            case 1:
                printf("\n[En desarrollo] Carga de parámetros...\n");
                break;
            case 2:
                printf("\n[En desarrollo] Cálculo de aceleración centrípeta...\n");
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