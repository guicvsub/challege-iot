## Equipe
- Gabriel Souza Fiore – RM553710
- Guilherme Santiago – RM552321
- Michel Lepine – RM553558
  
# Desafio IoT Quiz

Este projeto consiste em uma adaptação de um quiz feito no Kahoot! utilizando Arduino e outros componentes eletrônicos.

## Vídeo Demonstrativo
[Assista ao vídeo demonstrativo](https://www.youtube.com/watch?v=U8Usizv7JS8)

## Projeto no Wokwi
[Acesse o projeto no Wokwi](https://wokwi.com/projects/394081962231636993)

## Equipamentos Utilizados
| Nome            | Quantidade |
|-----------------|------------|
| Arduino         | 1          |
| LEDs            | 2          |
| Buzzer          | 1          |
| Resistor (220Ω) | 2          |
| LCD 12C (20x4)  | 1          |
| Resistor (kΩ)   | 2          |
| Botões          | 2          |

## Bibliotecas Utilizadas
- Arduino.h para utilizar funções do Arduino
- Wire.h para lidar com dispositivos I2C
- LiquidCrystal_I2C.h para lidar com LCD 12C (20x4). Em caso de troca de modelo, a biblioteca deve ser alterada (16x2 12C funciona sem necessidade de alterações).

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
}; // Esse bloco corresponde às respostas das perguntas. Devem ser maiúsculas.

## Vídeo Demonstrativo
[Assista ao vídeo demonstrativo](https://www.youtube.com/watch?v=U8Usizv7JS8)

## Projeto no Wokwi
[Acesse o projeto no Wokwi](https://wokwi.com/projects/394081962231636993)
