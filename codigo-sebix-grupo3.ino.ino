//SEBIX - Grupo 3 
/*
Diego Oliveira Bomfim
Guilherme Azevedo
Rafael Kuhn Takano
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//contador de pontos
int pontos = 0;

int ativo = false;

int botao;
int gameOver = 0;

//contador para controlar a limpeza dos cactos na tela
int j = 0;

//armazenar o estado do Dinossauro
int estadoDino = 0; //0 - chão   1 - ar   2 - caindo

//Variavel para contar o tempo em que o dino ficar no ar 
int airTime = 0;

//Variaveis para a atualização dos frames
unsigned long currentTime;
unsigned long lastTime;

//declarando uma posição randômica nos intervalos especificados para os cactos aparecem na tela
int posCactus1 = random(14,17);
int posCactus2 = random(19,21);
int posCactus3 = random(23,25);

//desenho do dinossauro
byte dino[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b10110,
  0b11111,
  0b01010,
  0b01010,
  0b00000
};

//desenho do obstáculo cacto
byte cactus[8] = {
  0b00100,
  0b00101,
  0b00101,
  0b10111,
  0b11100,
  0b00100,
  0b00100,
  0b00100
};


void setup()
{
  
  pinMode(8, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  
  lcd.begin(16, 2);
  
  //criando as figuras Dinossauro e Cacto
  lcd.createChar(0, dino);
  lcd.createChar(1, cactus);
  
}



void loop()
{
  //leitura do botao
  botao = digitalRead(8);
  
  //inicialização do jogo - esperando o jogador apertar o botão para começar
  if(!ativo){
    lcd.setCursor(1,0);
    lcd.print("PRESS TO START");
    lcd.setCursor(0,1);
    lcd.print("SEBIX - GRUPO 3");
    
    if(botao == HIGH){
      delay(500);
      lcd.clear();
      
      //Melodia de inicio de jogo
      tone(10,524,100);
      
      tone(10,588,100);
      
      tone(10,660,100);
      
      //inicio do jogo
      game_loop();
      botao = LOW;
    }
  }
}

void game_loop(){
  
    //inicia-se o lastTime 
    lastTime = millis();
  while(true){
    
    //atribui o tempo presente à currentTime
    currentTime = millis();
    
    //Espera o input de pulo do jogador e o registra
    if(botao == 0){ 
      botao = digitalRead(8); //recebendo o estado do botao
        if(botao == 1){
          tone(10, 523, 100);          
          estadoDino = 1; 
      }
    }
    
    //A cada 0,4 segundos atualiza a tela do jogo 
    if(currentTime - lastTime > 400){
      //Incrementa a pontuação 
        //e redefine o ultimo tempo em que houve atualização de tela
        pontos++;
        lastTime = millis();
      
        //Atualiza a tela 
      atualizaTela();
      
        //Caso a flag e gameover seja ativada dentro 
        //de "atualizaTela()" sai do while()
        if(gameOver)
          break;
    }    
  }
  
  //Melodia de fim de jogo
  tone(10,660,100);
  
  tone(10,588,100);
  
  tone(10,524,100);
  
  //Tela de fim de Jogo
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Fim de Jogo!");
  lcd.setCursor(3,1);
  lcd.print("pontos:  ");
  lcd.print(pontos);
  pontos = 0;
  delay(3000);
  
  //Setup das variaveis para um novo jogo
  lcd.clear();
  gameOver = 0;
  j = 0;
  
  posCactus1 = random(14,17);
  posCactus2 = random(19,21);
  posCactus3 = random(23,25);
}

void atualizaTela(){
  
  //registrador de pontos na tela
  lcd.setCursor(13,0);
  lcd.print(pontos);
  
 //decrescendo a posição dos cactos para efeito de animação
  posCactus1--;
  posCactus2--;
  posCactus3--;
  
  //if responsável por chamar a função de renovar os cactos
  if(posCactus1 == -1){
    renovarCactus(&posCactus1);
    lcd.setCursor(0,1);
    lcd.print(" ");
  }
  if(posCactus2 == -1){
    renovarCactus(&posCactus2);
    lcd.setCursor(0,1);
    lcd.print(" "); 
  }  
  if(posCactus3 == -1){
    renovarCactus(&posCactus3);
    lcd.setCursor(0,1);
    lcd.print(" ");
  }
      
  //responsável para controlar o pulo do dinossauro
  if(estadoDino == 1){
    //Dino no ar
    lcd.setCursor(0,0);
  lcd.write(byte(0));
    lcd.setCursor(0,1);
    lcd.print(" ");
    
    //Caso faça 3 "atualizaTela()" de tempo o dino cai 
    if(airTime == 2){
      airTime = -1;
      estadoDino = 2;
    }
    airTime++;
    }
    else{
    //Dino no chão
    estadoDino = 0;
    lcd.setCursor(0,1);
  lcd.write(byte(0));
    lcd.setCursor(0,0);
    lcd.print(" ");
    botao = 0;
  }
  
  //realizando limpeza dos cactos na tela, caso eles ja tenham sido desenhados anteriormente
  if(j > 0){
    lcd.setCursor((posCactus1+1),1);
    lcd.print(" ");
    
    lcd.setCursor((posCactus2+1),1);
    lcd.print(" ");
    
    lcd.setCursor((posCactus3+1),1);
    lcd.print(" ");  
  }
  
  
  //escrita dos cactos na tela
  lcd.setCursor(posCactus1,1);
  lcd.write(byte(1));
  
  lcd.setCursor(posCactus2,1);
  lcd.write(byte(1));
  
  lcd.setCursor(posCactus3,1);
  lcd.write(byte(1));
  
  ///Condição para a derrota do jogador 
  if(posCactus1 == 0 || posCactus2 == 0 || posCactus3 == 0)
    if(estadoDino == 0)
      gameOver = 1;
    
  //incramento de j
  j++;
}

//função para renovar os cactos que chegam no fim da tela
void renovarCactus(int *posCactus){
  *posCactus = random(14,17);
}
