#include <stdio.h>
#include "menu.h"


void mostrarMenu(void) {
    printf("\n=========================================\n");
    printf("   MISIÓN ARTEMIS - SIMULADOR ORBITAL MCU\n");
    printf("=========================================\n");
    printf("1. Ingresar parámetros orbitales (Radio / Velocidad)\n");
    printf("2. Calcular Aceleración Centrípeta\n");
    printf("3. Calcular Periodo y Frecuencia de Órbita\n");
    printf("4. Evaluar Estabilidad de Órbita (Fuerza G)\n");
    printf("5. Salir\n");
    printf("=========================================\n");
    printf("Seleccione una opción: ");
}

int leerOpcionValida(int min, int max) {
    int opcion;
    int resultado;

    while (1) {
        resultado = scanf("%d", &opcion);

        // Limpiar buffer de entrada para evitar bucles si ingresan letras
        while (getchar() != '\n');

        if (resultado == 1 && opcion >= min && opcion <= max) {
            return opcion;
        }

        printf("Opción inválida. Ingrese un número entre %d y %d: ", min, max);
    }
}

void ingresarParametros(ParametrosOrbitales *params) {
    printf("\n--- INGRESO DE PARÁMETROS ORBITALES ---\n");
    
    printf("Ingrese el radio de la órbita (en km): ");
    scanf("%f", &params->radio);
    
    printf("Ingrese la velocidad de la nave (en km/s): ");
    scanf("%f", &params->velocidad);
    
    // Limpiamos el buffer por si el usuario ingresó basura
    while (getchar() != '\n'); 
    
    printf("\n[EXITO] Parámetros guardados correctamente.\n");
}