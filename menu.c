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

void calcularPeriodoYFrecuencia(ParametrosOrbitales params) {
    // Definimos el valor de PI como una constante
    const float PI = 3.14159265;

    printf("\n--- CÁLCULO DE PERIODO Y FRECUENCIA ---\n");

    // Validación de seguridad: radio y velocidad deben ser mayores a 0
    if (params.radio <= 0 || params.velocidad <= 0) {
        printf("[ERROR] Primero debes ingresar un radio y velocidad mayores a 0 en la Opción 1.\n");
        return;
    }

    // Cálculos físicos
    float periodo = (2 * PI * params.radio) / params.velocidad;
    float frecuencia = 1.0 / periodo;

    printf("Datos actuales -> Radio: %.2f km | Velocidad: %.2f km/s\n", params.radio, params.velocidad);
    printf("Fórmulas: T = (2 * PI * r) / v  |  f = 1 / T\n");
    printf("[RESULTADO] Periodo Orbital (T): %.4f segundos\n", periodo);
    printf("[RESULTADO] Frecuencia (f): %.8f Hz (órbitas por segundo)\n", frecuencia);
}

void evaluarEstabilidad(ParametrosOrbitales params) {
    printf("\n--- EVALUACIÓN DE ESTABILIDAD (FUERZA G) ---\n");

    // Validación de seguridad para evitar divisiones por cero
    if (params.radio <= 0) {
        printf("[ERROR] Primero debes ingresar un radio mayor a 0 en la Opción 1.\n");
        return; // Retorna inmediatamente al menú principal
    }

    // 1. Calculamos la aceleración centrípeta (v^2 / r)
    float aceleracion = (params.velocidad * params.velocidad) / params.radio;

    // 2. Definimos la gravedad terrestre en km/s^2 constante
    const float GRAVEDAD_TERRESTRE = 0.00981;

    // 3. Calculamos la Fuerza G dividiendo la aceleración por la gravedad
    float fuerza_g = aceleracion / GRAVEDAD_TERRESTRE;

    printf("Aceleración centrípeta detectada: %.4f km/s^2\n", aceleracion);
    printf("[RESULTADO] Fuerza G experimentada por la nave: %.2f G\n", fuerza_g);

    // 4. Simulamos el diagnóstico médico/físico de la misión
    if (fuerza_g <= 3.0) {
        printf("[DIAGNÓSTICO] Órbita estable. Condiciones seguras para los astronautas de Artemis.\n");
    } else if (fuerza_g <= 8.0) {
        printf("[DIAGNÓSTICO] ADVERTENCIA: Órbita inestable. Fuerza G muy elevada. Riesgo de desmayo (G-LOC).\n");
    } else {
        printf("[DIAGNÓSTICO] PELIGRO CRÍTICO: Fuerza G estructuralmente letal. Misión abortada.\n");
    }
}

void simularPropulsorLateral() {
    float aceleracion_lat, tiempo;
    int resultado;

    printf("\n--- SIMULACIÓN DE PROPULSOR AUXILIAR LATERAL ---\n");
    printf("Teoría: Un pulso perpendicular a la velocidad orbital altera el plano de la órbita (Movimiento 3D).\n");

    // Validación para la aceleración lateral
    while(1) {
        printf("Ingrese la aceleración lateral (en m/s^2) [Ej. 0.50]: ");
        resultado = scanf("%f", &aceleracion_lat);
        while (getchar() != '\n'); // Limpieza del buffer
        
        if (resultado == 1 && aceleracion_lat > 0) {
            break;
        }
        printf("[ERROR] Valor no compatible. Ingrese un número mayor a 0.\n");
    }

    // Validación para el tiempo de encendido
    while(1) {
        printf("Ingrese el tiempo de encendido (en segundos) [Ej. 10.0]: ");
        resultado = scanf("%f", &tiempo);
        while (getchar() != '\n'); // Limpieza del buffer
        
        if (resultado == 1 && tiempo > 0) {
            break;
        }
        printf("[ERROR] Valor no compatible. Ingrese un tiempo numérico mayor a 0.\n");
    }

    // Cálculo físico de cinemática: Desplazamiento d = 0.5 * a * t^2
    float desviacion_metros = 0.5 * aceleracion_lat * (tiempo * tiempo);

    printf("\n[TRAYECTORIA] La trayectoria resultante adopta una forma helicoidal temporal, ");
    printf("generando una inclinación o cambio en el plano orbital original de la nave.\n");
    printf("[RESULTADO] La desviación lateral instantánea es de %.2f metros.\n", desviacion_metros);
}