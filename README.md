# 🪟 Persiana Automática com Arduino e Sensor de Luz

<div align="center">
   <img src="https://i.imgur.com/uAMD84J.png" width="300px" height="300px">
</div>

## 📖 Descrição

Este é um projeto simples, desenvolvido com Arduino, que simula o funcionamento de uma persiana automática. Ele utiliza um fotorresistor (LDR) para medir a intensidade da luz ambiente e um servo motor para controlar a posição da persiana (aberta ou fechada).

O projeto foi prototipado e testado na plataforma online [Tinkercad](https://www.tinkercad.com/).

## ✨ Funcionalidades

* **Controle Inteligente:** Baixa a persiana (fecha) automaticamente quando o ambiente fica claro, para bloquear o excesso de sol.
* **Modo de Repouso:** Levanta a persiana (abre) automaticamente quando o ambiente fica escuro.
* **Sensibilidade Ajustável:** O nível de luz que dispara a ação pode ser facilmente calibrado alterando uma única variável no código.
* **Feedback Visual:** O servo motor se move para posições angulares específicas (0° e 90°) para representar os estados "aberta" e "fechada".

## 🛠️ Componentes Necessários

* 1x Arduino Uno R3
* 1x Micro Servo Motor
* 1x Fotorresistor (LDR)
* 1x Resistor de 10kΩ
* 1x Protoboard (Placa de Ensaio)
* Fios Jumper para as conexões

## 🔌 Montagem do Circuito

A montagem do circuito é baseada em dois módulos principais:

1.  **Sensor de Luz (Divisor de Tensão):**
    * O Fotorresistor (LDR) é conectado entre a alimentação de 5V e um pino de leitura analógico (neste caso, `A0`).
    * O Resistor de 10kΩ é conectado entre o mesmo pino de leitura (`A0`) e o Terra (GND).
    * Isso permite que o Arduino leia a variação de tensão conforme a resistência do LDR muda com a luz.

2.  **Atuador (Servo Motor):**
    * **Fio Vermelho (Alimentação):** Conectado ao 5V.
    * **Fio Preto/Marrom (Terra):** Conectado ao GND.
    * **Fio Laranja/Amarelo (Sinal):** Conectado a um pino digital com PWM, como o pino `~9`.

## 🚀 Como Usar

1.  **Monte o circuito** conforme o diagrama apresentado no topo deste README.
2.  **Carregue o código** deste repositório na sua placa Arduino ou copie-o para o seu projeto no Tinkercad.
3.  **Abra o Monitor Serial** na IDE do Arduino (ou no Tinkercad) com a velocidade de 9600 bps para visualizar os valores lidos pelo sensor de luz.
4.  **Teste o sensor:**
    * **No Tinkercad:** Clique no LDR durante a simulação para abrir o controle deslizante de luz.
    * **Com o circuito real:** Cubra o LDR com a mão para simular escuridão e aponte uma lanterna para simular claridade.
5.  **Observe o resultado:** O servo motor se moverá de acordo com a intensidade da luz, abrindo ou fechando a "persiana".
6.  **(Opcional) Calibragem:** Se necessário, ajuste o valor da variável `limiarLuz` no código para tornar o sensor mais ou menos sensível à luz.
