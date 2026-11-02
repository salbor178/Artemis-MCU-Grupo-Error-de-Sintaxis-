#ifndef MENU_H
#define MENU_H

// 1. Creamos un struct para guardar todos los datos de la nave juntos
typedef struct {
    float radio;
    float velocidad;
} ParametrosOrbitales;

void mostrarMenu(void);
int leerOpcionValida(int min, int max);

// 2. Declaramos la función que recibe un puntero (*) al struct
void ingresarParametros(ParametrosOrbitales *params);

#endif