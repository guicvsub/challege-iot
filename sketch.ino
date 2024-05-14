#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
#define SCROLL_DELAY 400

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

const int btnVerdadeiro = 7;
const int btnFalso = 6;
const int ledVerde = 13;
const int ledVermelho = 11;
const int buzzer = 2;
enum Resposta {
  FALSO,
  VERDADEIRO
};

int currentQuestion = 0;
String perguntas[] = {
  "Comer frutas e vegetais todos os dias ajuda a manter o corpo saudavel",
  "Tomar banho com agua gelada no inverno ajuda a evitar gripes e resfriados",
  "Ficar muito tempo em frente a telas (computador, celular, tablet) pode prejudicar a visao",
  "Dormir mais de oito horas todas as noites e importante para o bom funcionamento do cerebro",
  "O consumo de alimentos gordurosos em excesso pode aumentar o risco de problemas de saude, como colesterol alto",
  "Se voce engolir um chiclete, ele ficara preso no seu estomago para sempre"
};

Resposta respostas[] = {
  VERDADEIRO,
  FALSO,
  VERDADEIRO,
  VERDADEIRO,
  VERDADEIRO,
  FALSO
};

void setup() {
  lcd.init();
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
  scrollQuestion(perguntas[currentQuestion]);


  delay(2000); 

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
    delay(5000); 
  }
}


void scrollQuestion(String question) {
  int len = question.length();
  int teste = len - LCD_COLS + 1;
    for (int i = 0; i < teste; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(question.substring(i, min(i + LCD_COLS, len)));
      delay(SCROLL_DELAY);
    }
}

void checkAnswer(Resposta answer) {
  lcd.clear();
  if (answer == respostas[currentQuestion]) {
    lcd.print("Correto!");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    tone(buzzer, 1000, 500);
  } else {
    lcd.print("Errado!");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 2000, 500);
  }
  delay(1000);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  noTone(buzzer);
}
