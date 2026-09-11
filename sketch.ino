#include <Button.h>

// ----------------------------------------------------
// PINES DE ENTRADA Y SALIDA
// ----------------------------------------------------
const int BTN1_PIN  = 25; // Botón 1 (Subida)
const int BTN2_PIN  = 33; // Botón 2 (Bajada)
const int BTN3_PIN  = 4;  // Botón 3 (Incrementar)
const int BTN4_PIN  = 5;  // Botón 4 (Decrementar)

const int RELAY1_PIN = 26; // Relé 1 -> LED Rojo
const int RELAY2_PIN = 27; // Relé 2 -> LED Verde

// ----------------------------------------------------
// OBJETOS DE LA LIBRERÍA BUTTON
// ----------------------------------------------------
Button boton1(BTN1_PIN);
Button boton2(BTN2_PIN);
Button boton3(BTN3_PIN);
Button boton4(BTN4_PIN);

// Variables de estado y contador
bool estadoRele1 = false;
bool estadoRele2 = false;
int contador = 0;

void setup() {
  Serial.begin(115200);

  // Inicializar botones
  boton1.begin();
  boton2.begin();
  boton3.begin();
  boton4.begin();

  // Configuración de los relés
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  digitalWrite(RELAY1_PIN, estadoRele1);
  digitalWrite(RELAY2_PIN, estadoRele2);

  Serial.println("==========================================");
  Serial.println("  PRACTICA: RELES Y LIBRERIA BUTTON");
  Serial.println("==========================================");
  Serial.print("Contador inicial: ");
  Serial.println(contador);
}

void loop() {

  // ----------------------------------------------------
  // TAREA 1: Botón 1 - Flanco de Subida (.pressed())
  // Detecta el momento exacto en que se presiona
  // ----------------------------------------------------
  if (boton1.pressed()) {
    estadoRele1 = !estadoRele1;
    digitalWrite(RELAY1_PIN, estadoRele1);

    Serial.print("[Tarea 1 - Subida] Rele 1: ");
    Serial.println(estadoRele1 ? "ENCENDIDO (LED 1 ON)" : "APAGADO (LED 1 OFF)");
  }

  // ----------------------------------------------------
  // TAREA 2: Botón 2 - Flanco de Bajada (.released())
  // Detecta el momento exacto en que se suelta
  // ----------------------------------------------------
  if (boton2.released()) {
    estadoRele2 = !estadoRele2;
    digitalWrite(RELAY2_PIN, estadoRele2);

    Serial.print("[Tarea 2 - Bajada] Rele 2: ");
    Serial.println(estadoRele2 ? "ENCENDIDO (LED 2 ON)" : "APAGADO (LED 2 OFF)");
  }

  // ----------------------------------------------------
  // TAREA 3: Botón 3 - Incrementar contador
  // ----------------------------------------------------
  if (boton3.pressed()) {
    contador++;
    Serial.print("Contador (+1) -> Valor actual: ");
    Serial.println(contador);
  }

  // ----------------------------------------------------
  // TAREA 4: Botón 4 - Decrementar contador
  // ----------------------------------------------------
  if (boton4.pressed()) {
    contador--;
    Serial.print("Contador (-1) -> Valor actual: ");
    Serial.println(contador);
  }
}
