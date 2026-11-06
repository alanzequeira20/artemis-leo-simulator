#ifndef ARTEMIS_H
#define ARTEMIS_H

#define G_CONST 6.674e-11
#define M_TIERRA 5.972e24
#define R_TIERRA 6371000.0

typedef struct {
    double altitud_m;       // Altitud h (metros)
    double masa_nave_kg;    // Masa m_orion (kg)
    double a_pulsos_ms2;    // Aceleración lateral (m/s^2)
    double dt_pulso_s;      // Duración del pulso (s)
} DatosOrbita;

typedef struct {
    double radio_orbital_m;
    double velocidad_orbital_ms;
    double periodo_s;
    double periodo_min;
    double aceleracion_centripeta_ms2;
    double desviacion_lateral_m;
} ResultadosSimulacion;

// Prototipos de funciones lógicas
double calcular_radio_orbital(double altitud_m);
double calcular_velocidad_orbital(double r_m);
double calcular_periodo_orbital(double r_m, double v_ms);
double calcular_aceleracion_centripeta(double v_ms, double r_m);
double calcular_desviacion_lateral(double a_ms2, double dt_s);

void ejecutar_simulacion_escenario2(const DatosOrbita *datos, ResultadosSimulacion *res);
void mostrar_demostracion_analitica(void);
void mostrar_reporte_completo(const DatosOrbita *datos, const ResultadosSimulacion *res);

#endif