# Simulador de Misiones Artemis - Escenario 2: Órbita Terrestre Baja (LEO)

## a) Integrantes y Comisión
1. **Meza Duarte, Juan Gabriel** — Legajo: 31289
2. **Vicentin, Javier Nicolas** — Legajo: 29355
3. **Zequeira, Alan Gabriel** — Legajo: 29220
- **Comisión:** K1.3 

---

## b) Descripción Detallada del Escenario Artemis Asignado y Reglas del Juego

### Escenario Asignado: Situación - Problema 2 (LEO)
Tras el apagado de sus motores de ascenso, la nave **Orion** ($m = 33.000,0\text{ kg}$) es inyectada en una órbita terrestre baja de estacionamiento (LEO), donde realiza un Movimiento Circular Uniforme (MCU) a una altitud constante de $h = 192,0\text{ km}$ ($192.000,0\text{ m}$) sobre la superficie terrestre.

**Constantes Físicas del Dominio:**
- Masa de la Tierra ($M_T$): $5,972 \times 10^{24}\text{ kg}$
- Radio terrestre medio ($R_T$): $6.371,0\text{ km}$ ($6.371.000,0\text{ m}$)
- Radio orbital total ($r = R_T + h$): $6.563,0\text{ km}$ ($6.563.000,0\text{ m}$)
- Constante de Gravitación Universal ($G$): $6,674 \times 10^{-11}\text{ N}\cdot\text{m}^2/\text{kg}^2$

### Respuestas y Funcionalidades del Simulador
1. **Demostración Analítica ($F_g = F_c$):** Demuestra que la fuerza de atracción gravitatoria actúa como la fuerza centrípeta del sistema y determina la velocidad orbital necesaria ($v = \sqrt{\frac{G \cdot M_T}{r}} \approx 7.792,95\text{ m/s}$).
2. **Período Orbital ($T$):** Calcula el tiempo en segundos y minutos necesario para completar una órbita completa ($T \approx 5.291,52\text{ s} \approx 88,19\text{ min}$).
3. **Aceleración Centrípeta ($a_c$):** Determina el módulo de la aceleración centrípeta dentro de la cápsula ($a_c \approx 9,25\text{ m/s}^2$).
4. **Desviación Lateral por Pulso Auxiliar:** Simula el encendido de un propulsor lateral ($a = 0,50\text{ m/s}^2$ constante y perpendicular a la velocidad orbital durante $\Delta t = 10,0\text{ s}$), calculando la desviación lateral resultante ($d = \frac{1}{2} a \cdot \Delta t^2 = 25,0\text{ m}$).

### Reglas y Dinámica de la Simulación
- **Modo Menú Interactivo:** El simulador opera en una consola mediante un menú por opciones numeradas.
- **Modo Valores Nominales:** Ejecuta los cálculos directamente con los parámetros reales de la misión Artemis 192 km.
- **Modo Parámetros Personalizados:** Permite al usuario ingresar altitudes, masas y duraciones de pulso alternativas para evaluar el comportamiento orbital.
- **Control de Navegación:** El ciclo se mantiene activo hasta que el usuario decida salir explícitamente.

---

## c) Breve Detalle de Funcionamiento y Arquitectura Técnica

El proyecto cumple con los criterios de programación estructurada en C y se modulariza en archivos de código (.c) y cabeceras (.h) con responsabilidades delimitadas:

- **`main.c` (Módulo Principal):** Contiene la función `main()`, la estructura del menú interactivo de consola y el ciclo principal de navegación.
- **`artemis.h` / `artemis.c` (Módulo de Lógica y Dominio):** 
  - Contiene las definiciones de estructuras de datos `DatosOrbita` y `ResultadosSimulacion`.
  - Implementa los algoritmos de cálculo físico ($v$, $T$, $a_c$, $d$) y la generación de reportes formateados en consola.
- **`validaciones.h` / `validaciones.c` (Módulo de Interfaz y Seguridad):**
  - Implementa `limpiar_buffer()` para vaciar `stdin` tras cada lectura.
  - Implementa `leer_double_positivo()` y `leer_entero_rango()` para interceptar datos no numéricos o fuera de rango sin permitir que la aplicación sufra un desbordamiento o cierre inesperado.
- **`Makefile`:** Archivo de automatización para compilación modular nativa mediante `gcc`.

---

## d) Instrucciones Claras de Compilación y Ejecución

### Requisitos Previos
- Compilador GCC instalado (compatible con estándar C99).
- Herramienta `make` (opcional para compilación automatizada).

### Ejecución en Linux/macOS
```bash
./simulador_artemis

### Ejecución en Windows
simulador_artemis.exe

### Limpieza de Archivos Objeto y Ejecutables
make clean

### Compilación Manual Alternativa (Sin Make)
gcc -Wall -Wextra -std=c99 main.c artemis.c validaciones.c -o simulador_artemis -lm

### Compilación Automática (Recomendada)
Para compilar todos los módulos y generar el ejecutable principal:

make
```
## e) Registro Detallado del Uso de Inteligencia Artificial
- Herramientas Consultadas: Gemini / ChatGPT
- Tareas Específicas Asistidas:
  1. Depuración de Entradas por Consola: Consultas sobre el tratamiento de desbordamientos de buffer en scanf() y el uso de getchar() dentro de validaciones.c.
  2. Estructura del Makefile: Asistencia en la sintaxis de reglas implícitas y enlace de la librería matemática -lm.
  3. Verificación Físico-Matemática: Validación de las fórmulas analíticas para el cálculo del período orbital $T$ y aceleración centrípeta $a_c$.
- Prompts Utilizados:
  - "¿Cómo limpiar el buffer de entrada stdin en C si el usuario ingresa una letra en lugar de un double?"
  - "Escribe un Makefile genérico en C para compilar main.c, artemis.c y validaciones.c usando gcc con flags -Wall y -lm.
- "Validación y Adaptación Humana:
  El código sugerido por la IA fue analizado, adaptado y refactorizado por los integrantes del grupo para asegurar el cumplimiento del estándar C99, el paso estricto de estructuras mediante punteros const y la modularización en archivos .c y .h.

