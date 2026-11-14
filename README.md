# Artemis-MCU-Grupo-Error de Sintaxis
#  Simulador Orbital Artemis - Escenario MCU (Situación 2)

**Materia:** Algoritmos y Estructuras de Datos  
**Carrera:** Ingeniería en Sistemas de Información  
**Institución:** UTN - Facultad Regional Resistencia  

##  Integrantes del Equipo
*   Albornoz Alejandro Sebastian - 30350
*   Bogado Sharon Tatiana - [Legajo]
*   Korovaichuk Dilan Lautaro- [30439]


##  Descripción del Proyecto
Este proyecto es un simulador interactivo por consola desarrollado nativamente en lenguaje C. Resuelve la **Situación Problemática 2 (Movimiento Circular Uniforme)** de la misión aeroespacial Artemis. El sistema permite ingresar los parámetros de vuelo de una nave orbitando la Luna y calcula sus variables físicas fundamentales, diagnosticando si las condiciones son seguras para la tripulación.

##  Funcionalidades del Simulador
El programa cuenta con un menú interactivo con validación estricta de datos que permite:
1. **Ingreso de parámetros orbitales:** Captura de radio (km) y velocidad (km/s).
2. **Cálculo de Aceleración Centrípeta:** Aplica la fórmula $a_c = v^2 / r$.
3. **Cálculo de Periodo y Frecuencia:** Determina el tiempo por órbita y los ciclos por segundo (Hz).
4. **Evaluación de Estabilidad (Fuerza G):** Compara la aceleración de la nave con la gravedad terrestre e imprime un diagnóstico de seguridad para los astronautas.

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
