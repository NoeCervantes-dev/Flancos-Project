Control de Relés y Contador con ESP32

Proyecto desarrollado con ESP32 para demostrar el manejo de botones, relés y un contador mediante la librería Button.h.

El sistema utiliza cuatro botones para controlar dos relés y modificar el valor de un contador. Además, se utiliza el monitor serial para mostrar en tiempo real las acciones realizadas y el estado de los dispositivos.

Descripción

El proyecto implementa diferentes formas de detectar eventos producidos por botones:

Botón 1: Detecta el momento en que se presiona mediante pressed() y cambia el estado del Relé 1.
Botón 2: Detecta el momento en que se suelta mediante released() y cambia el estado del Relé 2.
Botón 3: Incrementa el contador en una unidad cada vez que se presiona.
Botón 4: Decrementa el contador en una unidad cada vez que se presiona.

Los relés pueden utilizarse para controlar LEDs u otros dispositivos externos. En este ejemplo:

Relé 1 → LED Rojo
Relé 2 → LED Verde

El estado de los relés y el valor del contador se muestran mediante comunicación serial a 115200 baudios.

Hardware utilizado
ESP32
4 botones
2 módulos de relé
LED rojo
LED verde
Resistencias según el circuito utilizado
Cables de conexión
Protoboard
Asignación de pines
Componente	GPIO	Función
Botón 1	GPIO 25	Activar/desactivar Relé 1
Botón 2	GPIO 33	Activar/desactivar Relé 2
Botón 3	GPIO 4	Incrementar contador
Botón 4	GPIO 5	Decrementar contador
Relé 1	GPIO 26	Control de LED rojo
Relé 2	GPIO 27	Control de LED verde
Funcionamiento
Botón 1 — Evento pressed()

Al detectar que el botón 1 ha sido presionado, se invierte el estado del Relé 1.

if (boton1.pressed()) {
    estadoRele1 = !estadoRele1;
    digitalWrite(RELAY1_PIN, estadoRele1);
}


Cada pulsación alterna entre:

Relé 1 OFF → Relé 1 ON
Relé 1 ON  → Relé 1 OFF

Botón 2 — Evento released()

El botón 2 utiliza released(), por lo que el cambio de estado ocurre cuando el usuario suelta el botón.

if (boton2.released()) {
    estadoRele2 = !estadoRele2;
    digitalWrite(RELAY2_PIN, estadoRele2);
}

Botón 3 — Incremento

Cada pulsación del botón 3 incrementa el contador:

contador++;


Por ejemplo:

0 → 1 → 2 → 3 → 4 ...

Botón 4 — Decremento

Cada pulsación del botón 4 disminuye el contador:

contador--;


Por ejemplo:

4 → 3 → 2 → 1 → 0 → -1 ...

Monitor Serial

El ESP32 utiliza una velocidad de comunicación de 115200 baudios para mostrar información sobre el funcionamiento del sistema.

Ejemplo de salida:

==========================================
  PRACTICA: RELES Y LIBRERIA BUTTON
==========================================
Contador inicial: 0

[Tarea 1 - Subida] Rele 1: ENCENDIDO (LED 1 ON)
[Tarea 2 - Bajada] Rele 2: ENCENDIDO (LED 2 ON)
Contador (+1) -> Valor actual: 1
Contador (+1) -> Valor actual: 2
Contador (-1) -> Valor actual: 1

Librería utilizada

El proyecto utiliza la librería:

#include <Button.h>


Esta librería facilita la detección de eventos asociados con botones, como:

pressed() — Detecta la pulsación del botón.
released() — Detecta cuando el botón es liberado.
begin() — Inicializa el botón.
Objetivos del proyecto

Este proyecto tiene como objetivo practicar:

Configuración de entradas y salidas digitales en ESP32.
Lectura y control de botones.
Detección de eventos mediante pressed() y released().
Control de dispositivos mediante relés.
Manejo de variables de estado.
Implementación de un contador.
Comunicación serial mediante Serial.
Uso de librerías externas en Arduino/ESP32.
Estructura del programa

El código se divide principalmente en dos partes:

setup()

Se ejecuta una sola vez al iniciar el ESP32 y se encarga de:

Inicializar la comunicación serial.
Inicializar los cuatro botones.
Configurar los pines de los relés como salidas.
Establecer el estado inicial de los relés.
Mostrar información inicial en el monitor serial.
loop()

Se ejecuta continuamente y se encarga de:

Detectar la pulsación del Botón 1.
Detectar la liberación del Botón 2.
Incrementar el contador mediante el Botón 3.
Decrementar el contador mediante el Botón 4.
Requisitos

Para compilar y ejecutar el proyecto se necesita:

Arduino IDE o PlatformIO.
Placa ESP32 configurada.
Librería Button.h.
Cable USB para programar el ESP32.
Autor

Proyecto académico/práctico desarrollado para experimentar con ESP32, botones, relés y eventos de entrada digital.
