#include <stdio.h>
#include <math.h>
#include "artemis.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calcular_radio_orbital(double altitud_m) {
    return R_TIERRA + altitud_m;
}

double calcular_velocidad_orbital(double r_m) {
    // Demostración analítica: Fg = Fc => G*(M*m)/r^2 = m*v^2/r => v = sqrt(G*M / r)
    return sqrt((G_CONST * M_TIERRA) / r_m);
}

double calcular_periodo_orbital(double r_m, double v_ms) {
    return (2.0 * M_PI * r_m) / v_ms;
}

double calcular_aceleracion_centripeta(double v_ms, double r_m) {
    return (v_ms * v_ms) / r_m;
}

double calcular_desviacion_lateral(double a_ms2, double dt_s) {
    // Movimiento perpendicular bajo aceleración constante: d = 0.5 * a * dt^2
    return 0.5 * a_ms2 * (dt_s * dt_s);
}

void ejecutar_simulacion_escenario2(const DatosOrbita *datos, ResultadosSimulacion *res) {
    res->radio_orbital_m = calcular_radio_orbital(datos->altitud_m);
    res->velocidad_orbital_ms = calcular_velocidad_orbital(res->radio_orbital_m);
    res->periodo_s = calcular_periodo_orbital(res->radio_orbital_m, res->velocidad_orbital_ms);
    res->periodo_min = res->periodo_s / 60.0;
    res->aceleracion_centripeta_ms2 = calcular_aceleracion_centripeta(res->velocidad_orbital_ms, res->radio_orbital_m);
    res->desviacion_lateral_m = calcular_desviacion_lateral(datos->a_pulsos_ms2, datos->dt_pulso_s);
}

void mostrar_demostracion_analitica(void) {
    printf("\n============================================================\n");
    printf("     DEMOSTRACION ANALITICA: FUERZA CENTRIPETA Y GRAVITATORIA\n");
    printf("============================================================\n");
    printf("1. La unica fuerza neta actuando sobre la nave en orbita circular\n");
    printf("   es la Fuerza de Atraccion Gravitatoria (Fg).\n");
    printf("2. Fg = G * (M_T * m_orion) / r^2\n");
    printf("3. Por Segunda Ley de Newton para movimiento circular, Fc = m_orion * (v^2 / r).\n");
    printf("4. Igualando Fg = Fc:\n");
    printf("   G * (M_T * m_orion) / r^2 = m_orion * (v^2 / r)\n");
    printf("5. Despejando la velocidad orbital v:\n");
    printf("   v = sqrt( (G * M_T) / r )\n");
    printf("============================================================\n\n");
}

void mostrar_reporte_completo(const DatosOrbita *datos, const ResultadosSimulacion *res) {
    printf("\n============================================================\n");
    printf("         REPORTE DE SIMULACION DE ORBITA LEO (ARTEMIS)       \n");
    printf("============================================================\n");
    printf(" Parametros de Entrada:\n");
    printf("  - Altitud sobre superficie (h):  %.2f km (%.0f m)\n", datos->altitud_m / 1000.0, datos->altitud_m);
    printf("  - Masa de la nave Orion:        %.2f kg\n", datos->masa_nave_kg);
    printf("  - Pulso de aceleracion lateral:  %.2f m/s^2\n", datos->a_pulsos_ms2);
    printf("  - Duracion del pulso:            %.2f s\n", datos->dt_pulso_s);
    printf("------------------------------------------------------------\n");
    printf(" Resultados de la Simulacion:\n");
    printf("  a) Radio orbital total (r):     %.2f km (%.0f m)\n", res->radio_orbital_m / 1000.0, res->radio_orbital_m);
    printf("     Velocidad orbital (v):       %.2f m/s (%.4f km/s)\n", res->velocidad_orbital_ms, res->velocidad_orbital_ms / 1000.0);
    printf("  b) Periodo orbital (T):          %.2f s (%.2f minutos)\n", res->periodo_s, res->periodo_min);
    printf("  c) Aceleracion centripeta (ac):  %.4f m/s^2\n", res->aceleracion_centripeta_ms2);
    printf("  d) Desviacion lateral (d):       %.2f metros\n", res->desviacion_lateral_m);
    printf("============================================================\n\n");
}