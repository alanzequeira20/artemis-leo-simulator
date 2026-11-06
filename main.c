#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"

int main(void) {
    int opcion;
    // Valores nominales de la consigna (Escenario 2)
    DatosOrbita datos = {
        .altitud_m = 192000.0,
        .masa_nave_kg = 33000.0,
        .a_pulsos_ms2 = 0.50,
        .dt_pulso_s = 10.0
    };
    ResultadosSimulacion resultados;

    do {
        printf("====================================================\n");
        printf("   SIMULADOR DE MISIONES ARTEMIS - ESCENARIO 2 (LEO)\n");
        printf("====================================================\n");
        printf(" 1. Ver Demostracion Analitica (Fg = Fc)\n");
        printf(" 2. Ejecutar Simulacion con Valores Nominales (192 km)\n");
        printf(" 3. Ejecutar Simulacion con Parametros Personalizados\n");
        printf(" 4. Salir\n");
        printf("====================================================\n");

        opcion = leer_entero_rango("Seleccione una opcion [1-4]: ", 1, 4);

        switch (opcion) {
            case 1:
                mostrar_demostracion_analitica();
                break;
            case 2:
                ejecutar_simulacion_escenario2(&datos, &resultados);
                mostrar_reporte_completo(&datos, &resultados);
                break;
            case 3:
                printf("\n--- Ingrese nuevos datos de entrada ---\n");
                datos.altitud_m = leer_double_positivo("Ingrese Altitud h (metros): ");
                datos.masa_nave_kg = leer_double_positivo("Ingrese Masa de la nave (kg): ");
                datos.a_pulsos_ms2 = leer_double_positivo("Ingrese Aceleracion lateral (m/s^2): ");
                datos.dt_pulso_s = leer_double_positivo("Ingrese Duracion del pulso (segundos): ");
                
                ejecutar_simulacion_escenario2(&datos, &resultados);
                mostrar_reporte_completo(&datos, &resultados);
                break;
            case 4:
                printf("\nSaliendo del simulador Artemis... ¡Buen viaje!\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}