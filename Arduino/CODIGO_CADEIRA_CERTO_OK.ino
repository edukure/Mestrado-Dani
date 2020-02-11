//Código Driver - Comando da cadeira, sensor ultra, contagem de métricas


// Variáveis de controle da cadeira

#include <SoftwareSerial.h>
SoftwareSerial bt(9, 10); //Tx, Rx


char comandoAtual = '1';
int numComandos = 0;
unsigned long tempoInicial;
unsigned long tempoFinal;
bool contagemIniciada = false; // Determina se a sessão foi iniciada ou não

// Variáveis de controle do número de colisões (MUDAR VALORES PARA PINOS QUE FOR USAR)

int numColisoes = 0;
const int trig1 = 2;
const int echo1 = 13;
const int trig2 = 14;
const int echo2 = 15;
const int trig3 = 7;
const int echo3 = 8;
const int trig4 = 17;
const int echo4 = 18;

bool colisaoDetectada1 = false;
bool colisaoDetectada2 = false;
bool colisaoDetectada3 = false;
bool colisaoDetectada4 = false;


void setup()
{
  pinMode(3, OUTPUT); // Pino 2 da cadeira
  pinMode(5, OUTPUT); // Pino 3 da cadeira
  pinMode(6, OUTPUT); // Pino 5 da cadeira
  
  // Configuração de pinos como entrada e saída
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  
  Serial.begin(9600); // Inicialização da porta serial
  bt.begin(9600);
}
void loop()
{
  // Trecho referente aos sensores de colisão
  // Variáveis utilizadas para conversão do ping em cm
  
  long duration, inches, cm1;
  long duration2, inches2, cm2;
  long duration3, inches3, cm3;
  long duration4, inches4, cm4;
  
  // Sensor 1
  
  digitalWrite(trig1, LOW); // Desliga o emissor
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH); // 2 ms depois envia um sinal que dura 5 ms
  delayMicroseconds(5);
  digitalWrite(trig1, LOW); // Desliga o emissor
  duration = pulseIn(echo1, HIGH); // O receptor recebe o eco e envia um sinal digital HIGH - alto
  cm1 = microsecondsToCentimeters(duration); // Converte a distância e retorna a variável cm
  if (cm1 > 50) // Condição de leitura da variável - comandos para motores
  {
    digitalWrite (10, LOW); // Se a distância for maior que 50, o buzzer para
  }
  else
  {
    digitalWrite(10, HIGH); // Se a distância for menor que 50, o buzzer liga
  }

  
  // Sensor 2
  digitalWrite(trig2, LOW); // Desliga o emissor
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH); // 2 ms depois envia um sinal que dura 5 ms
  delayMicroseconds(5);
  digitalWrite(trig2, LOW); // Desliga o emissor
  duration2 = pulseIn(echo2, HIGH); // O receptor recebe o eco e envia um sinal digital HIGH - alto
  cm2 = microsecondsToCentimeters(duration2); // Converte a distância e retorna a variável cm
  if (cm2 > 50) // Condição de leitura da variável - comandos para motores
  {
    digitalWrite (11, LOW); // Se a distância for maior que 50, o buzzer para
  }
  else
  {
    digitalWrite(11, HIGH); // Se a distância for menor que 50, o buzzer liga
  }

    // Sensor 3
  digitalWrite(trig3, LOW); // Desliga o emissor
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH); // 2 ms depois envia um sinal que dura 5 ms
  delayMicroseconds(5);
  digitalWrite(trig3, LOW); // Desliga o emissor
  duration3 = pulseIn(echo3, HIGH); // O receptor recebe o eco e envia um sinal digital HIGH - alto
  cm3 = microsecondsToCentimeters(duration3); // Converte a distância e retorna a variável cm
  if (cm3 > 50) // Condição de leitura da variável - comandos para motores
  {
    digitalWrite (11, LOW); // Se a distância for maior que 50, o buzzer para
  }
  else
  {
    digitalWrite(11, HIGH); // Se a distância for menor que 50, o buzzer liga
  }

    // Sensor 4
  digitalWrite(trig4, LOW); // Desliga o emissor
  delayMicroseconds(2);
  digitalWrite(trig4, HIGH); // 2 ms depois envia um sinal que dura 5 ms
  delayMicroseconds(5);
  digitalWrite(trig4, LOW); // Desliga o emissor
  duration4 = pulseIn(echo4, HIGH); // O receptor recebe o eco e envia um sinal digital HIGH - alto
  cm4 = microsecondsToCentimeters(duration4); // Converte a distância e retorna a variável cm
  if (cm4 > 50) // Condição de leitura da variável - comandos para motores
  {
    digitalWrite (11, LOW); // Se a distância for maior que 50, o buzzer para
  }
  else
  {
    digitalWrite(11, HIGH); // Se a distância for menor que 50, o buzzer liga
  }

  //Contagem de colisao 
  
  //Sensor 1
  if ((contagemIniciada) && (cm1 < 10) && (!colisaoDetectada1)) // Checa se a contagem de dados foi iniciada, se a distância é menor que 10 cm no sensor 1, e se a colisão já foi contabilizada
  {
    colisaoDetectada1 = true;
    numColisoes += 1;
  }
  if ((cm1 > 10) && (colisaoDetectada1)) // Checa se o sensor 1 saiu da zona de colisão
  {
    colisaoDetectada1 = false;
  }

   //Sensor 2
  if ((contagemIniciada) && (cm2 < 10) && (!colisaoDetectada2)) // Checa se a contagem de dados foi iniciada, se a distância é menor que 10 cm no sensor 2, e se a colisão já foi contabilizada
  {
    colisaoDetectada2 = true;
    numColisoes += 1;
  }

  if ((cm2 > 10) && (colisaoDetectada2)) // Checa se o sensor 2 saiu da zona de colisão
  {
    colisaoDetectada2 = false;
  }

  //Sensor 3
  if ((contagemIniciada) && (cm3 < 10) && (!colisaoDetectada3)) // Checa se a contagem de dados foi iniciada, se a distância é menor que 10 cm no sensor 2, e se a colisão já foi contabilizada
  {
    colisaoDetectada3 = true;
    numColisoes += 1;
  }

  if ((cm3 > 10) && (colisaoDetectada3)) // Checa se o sensor 2 saiu da zona de colisão
  {
    colisaoDetectada3 = false;
  }

  //Sensor 4
  if ((contagemIniciada) && (cm4 < 10) && (!colisaoDetectada4)) // Checa se a contagem de dados foi iniciada, se a distância é menor que 10 cm no sensor 2, e se a colisão já foi contabilizada
  {
    colisaoDetectada4 = true;
    numColisoes += 1;
  }

  if ((cm4 > 10) && (colisaoDetectada4)) // Checa se o sensor 2 saiu da zona de colisão
  {
    colisaoDetectada4 = false;
  }

  
  // Trecho referente ao controle da cadeira
  if (Serial.available() > 0) // Verifica se tem algum comando na entrada
  {
    comandoAtual = Serial.read(); // Leitura do comando de entrada
    comandoAtual = '1';
    
    switch (comandoAtual)
    {
      case '1': // Enviar comando para ficar parado
        wheelchairInput(130, 130, 130);
     //Serial.println("Parado");
      numComandos = numComandos + 1;
        Serial.println(numComandos);
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '2': // Enviar comando para frente
        wheelchairInput(183, 144, 144);
      //Serial.println("Frente");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
       Serial.println(numComandos);
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '3': // Enviar comando para tras
        wheelchairInput(87, 144, 144);
      //Serial.println("Tras");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
        Serial.println(numComandos);;
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '4': // Enviar comando para direita
        wheelchairInput(144, 87, 144);
       // Serial.println("Direita");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
       Serial.println(numComandos);
        tempoFinal = millis();
       // Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '5': // Enviar comando para esquerda
        wheelchairInput(144, 180, 144);
        //Serial.println("Esquerda");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
        Serial.println(numComandos);
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '6': // Enviar comando para D1
        wheelchairInput(170, 86, 144);
        //Serial.println("D1");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
       Serial.println(numComandos);
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '7': // Enviar comando para D2
        wheelchairInput(85, 112, 144);
      //  Serial.println("D2");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
       Serial.println(numComandos);
       tempoFinal = millis();
       // Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '8': // Enviar comando para D3
        wheelchairInput(95, 175, 144);
       // Serial.println("D3");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
       Serial.println(numComandos);
        tempoFinal = millis();
       // Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      case '9': // Enviar comando para D4
        wheelchairInput(125, 186, 144);
        //Serial.println("D4");
        numComandos = numComandos + 1;
        if (!contagemIniciada)
        {
          contagemIniciada = true;
          tempoInicial = millis();
        }
        Serial.println(numComandos);
        tempoFinal = millis();
        //Serial.println((tempoFinal - tempoInicial) / 1000);
        break;
        
      //case '0':
        //if (contagemIniciada)
        //{
         // wheelchairInput(130, 130, 130);
          //Serial.println("Parado");
          //Serial.print("Numero de comandos: ");
          //Serial.println(numComandos);
          //Serial.print("Time: ");
          //tempoFinal = millis();
          //Serial.println((tempoFinal - tempoInicial) / 1000);
          // Mostrar resultados do contador de colisões
          //Serial.print("Distancia 1 ");
          //Serial.print(cm1);
          //Serial.println("cm");
          //Serial.print("Distancia 2 ");
          //Serial.print(cm2);
          //Serial.println("cm");
          //Serial.print("Colisao: ");
          //Serial.println(numColisoes);
          
          // Sessão para resetar os contadores
         // numComandos = 0;
        //  numColisoes = 0;
          //contagemIniciada = false;
       // }
     // break;
    }
  }
  delay(100);
}
void wheelchairInput(int pin3Value, int pin5Value, int pin6Value)
{
  analogWrite(3, pin3Value); // Envia o valor pin2Value para pino 2
  analogWrite(5, pin5Value); // Envia o valor pin3Value para pino 3
  analogWrite(6, pin6Value); // Envia o valor pin4Value para pino 5
}

long microsecondsToCentimeters(long microseconds) // Função para conversão de ms para cm
{
  // A velocidade do som é 340 m/s ou 29 ms/cm. O ping vai e volta, e sua distância será metade do tempo de ida e volta
  return microseconds / 29 / 2;
}
