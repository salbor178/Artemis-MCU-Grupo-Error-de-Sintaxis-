# Artemis-MCU-Grupo-Error de Sintaxis
#  Simulador Orbital Artemis - Escenario MCU (Situación 2)

**Materia:** Algoritmos y Estructuras de Datos  
**Carrera:** Ingeniería en Sistemas de Información  
**Institución:** UTN - Facultad Regional Resistencia  

##  Integrantes del Equipo - Comision: k1.4 ( D )
*   Albornoz, Alejandro Sebastian - 30350
*   Bogado, Sharon Tatiana - [30213]
*   Korovaichuk, Dilan Lautaro- [30439]


##  Descripción del Proyecto
Este proyecto es un simulador interactivo por consola desarrollado nativamente en lenguaje C. Resuelve la Situación Problemática 2 (Movimiento Circular Uniforme) de la misión aeroespacial Artemis. El sistema permite ingresar los parámetros de vuelo de una nave en órbita terrestre baja (LEO) y calcula sus variables físicas fundamentales, diagnosticando si las condiciones son seguras para la tripulación.

##  Funcionalidades del Simulador
El programa cuenta con un menú interactivo con validación estricta de datos que permite:
1. **Ingreso de parámetros orbitales:** Captura de radio (km) y velocidad (km/s).
2. **Cálculo de Aceleración Centrípeta:** Aplica la fórmula $a_c = v^2 / r$.
3. **Cálculo de Periodo y Frecuencia:** Determina el tiempo por órbita y los ciclos por segundo (Hz).
4. **Evaluación de Estabilidad (Fuerza G):** Compara la aceleración de la nave con la gravedad terrestre e imprime un diagnóstico de seguridad para los astronautas.
5. **Simulación de Propulsor Auxiliar Lateral:** Calcula la desviación lateral instantánea y el cambio de trayectoria tras el encendido de un motor perpendicular a la órbita.

##  Diagrama de flujo del Simulador
A continuación, se detalla el flujo de ejecución del menú principal, las validaciones de entrada y las ramificaciones lógicas de la simulación:

<img width="2746" height="1965" alt="image" src="https://github.com/user-attachments/assets/92b6a115-1596-4e15-82a1-d27ee6901c97" />



##  Estructura del Código (Modularización)
El código fuente cumple con el estándar de desarrollo profesional dividiendo la lógica en tres archivos:
*   `main.c`: Archivo principal que gestiona el control de flujo y el bucle del programa.
*   `menu.h`: Archivo de cabecera con las definiciones de la estructura `ParametrosOrbitales` y las firmas de las funciones.
*   `menu.c`: Archivo que contiene la lógica de las fórmulas físicas, el diseño de la interfaz y las validaciones de entrada.

##  Instrucciones de Compilación y Ejecución

Para ejecutar este simulador en Windows, es necesario contar con el compilador GCC instalado.

**1. Compilar el proyecto:**
Abre una terminal en la carpeta raíz del proyecto y ejecuta el siguiente comando para vincular y compilar todos los archivos fuente:
```bash
gcc *.c -o Artemis.exe
```

**2. Ejecutar el proyecto:**
En la misma terminal en la carpeta raíz del proyecto, ejecuta el siguiente comando para iniciar el proyecto:
```bash
.\Artemis.exe
```

## Registro de Uso de Inteligencia Artificial (IA)

Para el desarrollo de este Trabajo Práctico Integrador, el equipo utilizó **Gemini** como asistente de aprendizaje, depuración de código y estructuración del proyecto. A continuación, se detalla el uso ético y crítico de la herramienta:

### 1. Resolución de Errores en la Validación de Entradas (Buffer)
*   **Tarea específica:** Evitar que el programa entrara en un bucle infinito cuando el usuario ingresaba caracteres no numéricos en la función `scanf`.
*   **Prompt utilizado:** *"Solicitud de explicación detallada sobre el funcionamiento interno del buffer de entrada en C, específicamente el uso de `while (getchar() != '\n');` para la limpieza de caracteres remanentes, y su correcta integración con condicionales de validación de rango."*
*   **Validación y Adaptación:** La IA explicó el concepto del buffer de teclado (`stdin`) en C. El equipo validó la explicación probando el código y adaptó esta técnica en todas las funciones de ingreso de datos (`menu.c`) para asegurar que el programa no sufra cierres inesperados (segfaults) ni bucles infinitos.

### 2. Comprensión de Punteros y Gestión de Memoria
*   **Tarea específica:** Comprender correctamente el paso de parámetros por referencia para modificar una estructura (`struct`) desde una función modularizada.
*   **Prompt utilizado:** *"Consulta conceptual sobre la gestión de memoria en C: análisis y confirmación del comportamiento del paso de parámetros por referencia mediante el uso de punteros (ej. `*params`) en la firma de una función."*
*   **Validación y Adaptación:** Se confirmó el marco teórico sobre punteros. El equipo decidió aplicar el paso por referencia **solo** en la función de carga de datos iniciales. En contraste, para las funciones de cálculo (Opciones 2, 3, 4 y 5) se utilizó el paso por valor para proteger la estructura original en memoria, ya que solo se requería su lectura.
