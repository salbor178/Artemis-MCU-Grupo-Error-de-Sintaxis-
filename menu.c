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
    int resultado; // Variable para saber si scanf leyó bien el dato

    printf("\n--- INGRESO DE PARÁMETROS ORBITALES ---\n");
    
    // 1. Bucle infinito para validar el Radio
    while (1) {
        printf("Ingrese el radio de la órbita (en km): ");
        resultado = scanf("%f", &params->radio);
        
        // Limpiamos el buffer inmediatamente después de leer
        while (getchar() != '\n'); 

        // Validamos que se haya ingresado 1 número Y que sea mayor a 0
        if (resultado == 1 && params->radio > 0) {
            break; // Todo está correcto, rompemos el bucle y avanzamos
        }
        
        printf("[ERROR] Valor no compatible. Ingrese un número mayor a 0.\n");
    }
    
    // 2. Bucle infinito para validar la Velocidad
    while (1) {
        printf("Ingrese la velocidad de la nave (en km/s): ");
        resultado = scanf("%f", &params->velocidad);
        
        while (getchar() != '\n'); 

        // Solo validamos que sea un número (resultado == 1)
        if (resultado == 1) {
            break; // Todo está correcto, rompemos el bucle
        }
        
        printf("[ERROR] Valor no compatible. Ingrese un número válido.\n");
    }
    
    printf("\n[EXITO] Parámetros guardados correctamente.\n");
}

void calcularAceleracion(ParametrosOrbitales params) {
    printf("\n--- CÁLCULO DE ACELERACIÓN CENTRÍPETA ---\n");
    
    // Validación de seguridad: no se puede dividir por cero
    if (params.radio <= 0) {
        printf("[ERROR] Primero debes ingresar un radio mayor a 0 en la Opción 1.\n");
        return; // Corta la ejecución de la función y vuelve al menú
    }

    // Aplicamos la fórmula de Física: a_c = v^2 / r
    float aceleracion = (params.velocidad * params.velocidad) / params.radio;
    
    printf("Datos actuales -> Radio: %.2f km | Velocidad: %.2f km/s\n", params.radio, params.velocidad);
    printf("Fórmula: a_c = v^2 / r\n");
    printf("[RESULTADO] La aceleración centrípeta es de %.4f km/s^2\n", aceleracion);
}
