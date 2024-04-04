#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_COLS 20
#define LCD_ROWS 4

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

const int btnVerdadeiro = 7;
const int btnFalso = 6;
const int ledVerde = 13;     // Pino do LED verde
const int ledVermelho = 11;  // Pino do LED vermelho
const int buzzer = 2;         // Pino do buzzer

enum Resposta {
  FALSO,
  VERDADEIRO
};

int currentQuestion = 0;
String perguntas[] = {
  "O acucar e um alimento saudavel?",
  "Frutas  ajudam a prevenir doencas?",
  "Cafeina pode causar dependencia?",
  "O sistema solar tem o sol como centro?",
  "A lua e maior que a terra?",
  "As plantas precisam de agua para viver?",
  "Os peixes respiram embaixo da agua?",
  "Os passaros tem penas para voar?",
  "O Sol eh uma estrela?",
  "Os dinossauros ainda existem?"
};

Resposta respostas[] = {
  FALSO,
  VERDADEIRO,
  VERDADEIRO,
  VERDADEIRO,
  FALSO,
  VERDADEIRO,
  VERDADEIRO,
  VERDADEIRO,
  VERDADEIRO,
  FALSO
};

void setup() {
  lcd.init(); // Inicializa o LCD
  lcd.backlight();
  lcd.print("Responda com:");
  lcd.setCursor(0, 1);
  lcd.print("Verde (V) ou");
  lcd.setCursor(0, 2);
  lcd.print("Vermelho (F)");

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.print(perguntas[currentQuestion]);

  delay(2000); // Aguarda um tempo antes de iniciar a verificação da resposta

  while (true) {
    if (digitalRead(btnVerdadeiro) == HIGH) {
      checkAnswer(VERDADEIRO);
      break;
    }

    if (digitalRead(btnFalso) == HIGH) {
      checkAnswer(FALSO);
      break;
    }
  }

  delay(1000);

  currentQuestion++;
  if (currentQuestion == sizeof(perguntas) / sizeof(perguntas[0])) {
    currentQuestion = 0;
    lcd.clear();
    lcd.print("Fim de jogo!");
    delay(5000); // Mostra a mensagem de fim de jogo por 5 segundos
  }
}

void checkAnswer(Resposta answer) {
  lcd.clear();
  if (answer == respostas[currentQuestion]) {
    lcd.print("Correto!");
    digitalWrite(ledVerde, HIGH);    // Acende o LED verde
    digitalWrite(ledVermelho, LOW); // Garante que o LED vermelho esteja apagado
    tone(buzzer, 1000, 500);         // Toca um som suave (1kHz) por 500ms
  } else {
    lcd.print("Errado!");
    digitalWrite(ledVerde, LOW);    // Garante que o LED verde esteja apagado
    digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
    tone(buzzer, 2000, 500);         // Toca um som agudo (2kHz) por 500ms
  }
  delay(1000);
    digitalWrite(ledVerde, LOW);    // Garante que o LED verde esteja apagado
    digitalWrite(ledVermelho, LOW);
  noTone(buzzer); // Desliga o buzzer

}
