#include <Servo.h> // Inclui a biblioteca para controlar o servo motor

const int pinoLDR = A0;   // Pino analógico onde o sensor de luz está conectado
const int pinoServo = 9;  // Pino digital PWM onde o fio de sinal do servo está conectado

// 90 graus = persiana abaixada e 0 é persianas levantadas
const int posBaixada = 90;
const int posLevantada = 0;

// --- Limite de Luz ---
// valor que define quando está "claro" o suficiente para baixar a persiana
const int limiarLuz = 500;

// cria um objeto 'servo'
Servo meuServo;

void setup() {
  Serial.begin(9600);

  // Associa o nosso objeto servo ao pino físico no Arduino
  meuServo.attach(pinoServo);

  // Inicia com a persiana levantada
  meuServo.write(posLevantada);
  Serial.println("Sistema iniciado. Persiana levantada.");
}

void loop() {
  // 1. Lê o valor do sensor de luz
  int valorLuz = analogRead(pinoLDR);

  // 2. Mostra o valor no Monitor Serial (muito útil para calibrar o 'limiarLuz')
  Serial.print("Valor do sensor de luz: ");
  Serial.println(valorLuz);

  // 3. LÓGICA PRINCIPAL - AQUI ESTÁ A MUDANÇA
  if (valorLuz > limiarLuz) {
    // Se a luz for FORTE (acima do limiar), a persiana é ATIVADA e ABAIXA
    meuServo.write(posBaixada);
    Serial.println("Ambiente claro. Baixando a persiana...");
  } else {
    // Se a luz for FRACA (abaixo do limiar), a persiana fica DESLIGADA (ou seja, levantada)
    meuServo.write(posLevantada);
    Serial.println("Ambiente escuro. Mantendo a persiana levantada.");
  }

  // Espera um tempo antes de verificar a luz novamente para não ficar movendo o tempo todo
  delay(1000); // Pausa de 1 segundo
}