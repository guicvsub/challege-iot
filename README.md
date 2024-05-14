## Equipe
- Gabriel Souza Fiore – RM553710
- Guilherme Santiago – RM552321
- Michel Lepine – RM553558
  
# Desafio IoT Quiz

Este projeto consiste em uma adaptação de um quiz feito no Kahoot! Utilizando Arduino e outros componentes eletrônicos.

## Vídeo Demonstrativo
[Assista ao vídeo demonstrativo ]()

## Projeto no Wokwi
[Acesse o projeto no Wokwi](https://wokwi.com/projects/397315509790205953)

## Equipamentos Utilizados
| Nome            | Quantidade |
|-----------------|------------|
| Arduino         | 1          |
| LEDs            | 2          |
| Buzzer          | 1          |
| Resistor (220Ω) | 2          |
| LCD 12C (16x2)  | 1          |
| Resistor (kΩ)   | 2          |
| Botões          | 2          |

## Bibliotecas Utilizadas
- Arduino.h para utilizar funções do Arduino
- Wire.h para lidar com dispositivos I2C
- LiquidCrystal_I2C.h para lidar com LCD 12C (16x2). 

## Pinagem do Arduino
- LCD: SDA = A4, SLC = A5 (padrão, não deve ser alterado)
- Botão Verdadeiro: 7
- Botão Falso: 6
- LED Verde: 13
- LED Vermelho: 11
- Buzzer: 2

## Possibilidades de Alterações
```cpp
int currentQuestion = 0;
String perguntas[] = {
 
}; // Esse bloco corresponde às perguntas (se encontram no wokwi). As perguntas devem ser strings, não conter acentuações ou caracteres especiais, devido à limitação do display.

Resposta respostas[] = {
  VERDADEIRO,
  FALSO,
  VERDADEIRO,
  VERDADEIRO,
  VERDADEIRO,
  FALSO
};
 // Esse bloco corresponde às respostas das perguntas. Devem ser maiúsculas.
