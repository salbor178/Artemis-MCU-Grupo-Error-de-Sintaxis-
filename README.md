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

![Diagrama de Flujo del Simulador Artemis](diagrama.png)


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

## 🤖 Registro de Uso de Inteligencia Artificial (IA)

Para el desarrollo de este Trabajo Práctico Integrador, el equipo utilizó **Gemini** como asistente de aprendizaje, depuración de código y estructuración del proyecto. A continuación, se detalla el uso ético y crítico de la herramienta, cumpliendo con los lineamientos de la cátedra:

### 1. Resolución de Errores en la Validación de Entradas (Buffer)
*   **Tarea específica:** Evitar que el programa entrara en un bucle infinito cuando el usuario ingresaba letras en lugar de números en el `scanf`.
*   **Prompt utilizado:** *"explicame con mas detalle la linea 25 y 26 (`while (getchar() != '\n');` e `if (resultado == 1 && opcion >= min && opcion <= max)`)"*
*   **Validación y Adaptación:** La IA explicó el concepto del buffer de teclado (`stdin`) en C. El equipo validó la explicación probando el código y adaptó el bucle `while (getchar() != '\n');` en todas las funciones de ingreso de datos (`menu.c`) para asegurar que el programa no sufra cierres inesperados (segfaults) ni bucles.

### 2. Comprensión de Punteros y Gestión de Memoria
*   **Tarea específica:** Entender correctamente el paso de parámetros por referencia para modificar una estructura (`struct`) desde una función modularizada.
*   **Prompt utilizado:** *"esa funcion cuando en el argumento empieza la variable con un * significa que recibe una direccion de memoria cierto? (`void ingresarParametros(ParametrosOrbitales *params)`)"*
*   **Validación y Adaptación:** Se confirmó el marco teórico sobre punteros. El equipo decidió aplicar el paso por referencia **solo** en la función de carga de datos, mientras que para las funciones de cálculo (Opciones 2, 3, 4 y 5) se utilizó el paso por valor, ya que solo se necesitaba leer los datos, protegiendo así la memoria original.

### 3. Implementación de Fórmulas Físicas (Fuerza G y Propulsor Lateral)
*   **Tarea específica:** Trasladar las fórmulas físicas del Escenario 2 (MCU y MRUV) al lenguaje C para las opciones 4 y 5.
*   **Prompt utilizado:** *"ahora la implementacion de la funcion 4"* y *"que paso con el item d? desarrolla la funcion nueva"*
*   **Validación y Adaptación:** La IA generó la base matemática (ej. cálculo de $d = 0.5 \cdot a \cdot t^2$ para el propulsor lateral). El equipo revisó matemáticamente las fórmulas, ajustó las constantes (como la gravedad terrestre) y adaptó los condicionales `if-else` para personalizar los mensajes de diagnóstico de la misión Artemis que se muestran por consola.

### 4. Organización del Repositorio y Control de Versiones
*   **Tarea específica:** Buscar una estrategia para versionar el código localmente de forma colaborativa sin que Windows arroje el error de "ruta demasiado larga" por anidamiento de carpetas.
*   **Prompt utilizado:** *"como podria organizar commits localmente con sus archivos y sus modificaciones unicas correspondientes de otra manera para evitar el error de ruta larga en Windows?"*
*   **Validación y Adaptación:** Se implementó la sugerencia de usar una estructura de carpetas plana con nomenclatura secuencial (`AñoMesDia_Hora_Descripción`). Esto permitió a los distintos miembros del grupo simular las versiones locales, pasarse el código limpio y realizar commits equitativos en GitHub para reflejar un trabajo realmente colaborativo.
