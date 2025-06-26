#include <Servo.h>

const int pinoLDR = A0;   // pino onde o sensor de luz está conectado
const int pinoServo = 9;  // pino onde o fio de sinal do servo está conectado

const int posBaixada = 90;
const int posLevantada = 0;

// limite de luz
// valor que define quando está claro o suficiente para baixar a persiana
const int limiarLuz = 500;

// cria o objeto servo
Servo meuServo;

void setup() {
  Serial.begin(9600);

  // associa o objeto servo ao pino físico no arduino
  meuServo.attach(pinoServo);

  // inicia com a persiana levantada
  meuServo.write(posLevantada);
  Serial.println("Sistema iniciado. Persiana levantada.");
}

void loop() {
  // lê o valor do sensor de luz
  int valorLuz = analogRead(pinoLDR);

  // mostra o valor no monitor serial
  Serial.print("Valor do sensor de luz: ");
  Serial.println(valorLuz);

  if (valorLuz > limiarLuz) {
    // se a luz for acima do limiar, a persiana abaixa
    meuServo.write(posBaixada);
    Serial.println("Ambiente claro. Baixando a persiana...");
  } else {
    // Se a luz for abaixo do limiar, a persiana levanta
    meuServo.write(posLevantada);
    Serial.println("Ambiente escuro. Mantendo a persiana levantada.");
  }

  // delay de 1 segundo para verificar a luz novamente
  delay(1000);
}
