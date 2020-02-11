int numComandos;
unsigned long tempo;
int numColisoes;


/* -- Vetores de teste -- */

int comandos[5] = {1,2,3,4,5};
unsigned long tempos[5] {11,22,33,44,55};
int colisoes[5] = {1,2,3,4,5};

int index = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  //Lógica de aquisição aqui
  // ...

  /* Em vez de fazer Serial.println()
   *  em todos os casos do switch, apenas 
   *  se armazena a qtd de colisões, comandos e tempo
   *  nas variáveis criadas acima.
   *  Antes do final do loop, utiliza-se a função
   *  Output() para juntar os três numa string só
   *  e printá-la na porta serial
   */

   /* testes */

   numComandos = comandos[index];
   tempo = tempos[index];
   numColisoes = colisoes[index];

   index++;
   if(index > 4)
   {
    index = 0;
   }

   Output(numComandos, tempo, numColisoes);

   //delay apenas para o teste
   delay(1000);
}

void Output(int qtdComandos, unsigned long tempo, int qtdColisoes)
{
  Serial.print(qtdComandos);
  Serial.print(',');
  Serial.print(tempo);
  Serial.print(',');
  Serial.println(qtdColisoes);
}
