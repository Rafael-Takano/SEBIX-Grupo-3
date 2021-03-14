# SEBIX-Grupo-3
## Descrição do Projeto
Desenvolvimento de um jogo arcade inspirado no "T-Rex Game" do Google Chrome em Arduino, realizado como projeto de treinamento de trabalho em grupo e consolidação de conceitos aprendidos no treinamento da ada. 
## Protótipo
O protótipo foi montado e testado por meio do TinkerCad, utilizando:
- 1 Arduino UNO
- 1 Buzzer 
- 1 Display de LCD 16x2
- 1 Potenciômetro de 250 kOhm
- 1 Protoboard 
- 1 Pushbutton
- 2 Resistores de 1 kOhm 

E foi montado assim como na imagem abaixo.
![Prototipo montado no TinkerCad](/Imagens/montagem-tinkercad.png)

## Código
- #### Breve descrição do funcionamento do jogo
Inicialmente ao ligar o Arduino à uma fonte de energia o jogo fica numa tela inicial esperando o input do jogador para começar:

![Tela inicial do jogo](/Imagens/tela-start.png)

Em seguida, com o clique do jogador, começa o jogo e toca a melodia de inicio de game. 

O objetivo do jogador é evitar os cactos que vem em sua direção, a pontuação disposta no canto superior direito é contado com base no tempo de jogo, ao clicar no botão o dinossauro pula e o buzzer emite o som de pulo.
![Tela durante o jogo](/Imagens/tela-ingame.png)

Ao colidir-se com um cacto o jogo termina e é exibida a tela de Game Over e toca-se a musica de fim de jogo.
![Tela de fim de jogo](/Imagens/tela-gameover.png)

Caso haja interesse, o link do código está abaixo:
- **[Código do jogo](/codigo-sebix-grupo3.ino.ino)**

## PCB
A placa de circuito impresso foi produzida no software Eagle, diferentemente do protótipo nessa placa é esperado o uso do Arduino Nano pois o design fica mais compacto.

A imagem da placa com os componentes pode ser observada abaixo.

![PCB produzida no Eagle](/Imagens/PCB.png)

Os fios azuis representam as conexões do lado de cima da placa e o fios vermelhos a rede do lado de baixo da placa

Caso haja o interesse na producão dessa placa do jeito como foi projetada os templates estão abaixo:
 
- [Parte de cima "Fios Azuis"](/PCB_Files/Schematics_Sebix_top.pdf)
- [Parte de baixo "Fios Vermelhos"](/PCB_Files/Schematics_Sebix_bottom.pdf)

Caso haja o interesse na modificação dessa placa: 

- [Esquema](/PCB_Files/Schematics_Sebix.sch)
- [Placa](/PCB_Files/Schematics_Sebix.brd)

