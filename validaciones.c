#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double leer_double_positivo(const char *mensaje) {
    double valor;
    int resultado;
    do {
        printf("%s", mensaje);
        resultado = scanf("%lf", &valor);
        if (resultado != 1 || valor <= 0) {
            printf("[ERROR] Entrada invalida. Ingrese un numero real mayor a cero.\n");
            limpiar_buffer();
        } else {
            limpiar_buffer();
            break;
        }
    } while (1);
    return valor;
}

int leer_entero_rango(const char *mensaje, int min, int max) {
    int valor, resultado;
    do {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        if (resultado != 1 || valor < min || valor > max) {
            printf("[ERROR] Opcion fuera de rango (%d - %d). Intente nuevamente.\n", min, max);
            limpiar_buffer();
        } else {
            limpiar_buffer();
            break;
        }
    } while (1);
    return valor;
}