// C++ code
//


const int LAzul = 1;
const int LVerde = 2;
const int LVermelho = 3;
const int LAmarelo = 4;
const int BAzul = 8;
const int BVerde = 9;
const int BVermelho = 10;
const int BAmarelo = 11;

const int Som = 7;
const int Start = 6;

int sequencia [50];
int sequencia_jogador [50];
int luz = 0;
int posicao_atual = 0, tamanho_ordem = 0;
int x = 0;

bool game_running = false, player_choosing = false;

bool chose_Azul = false;
bool chose_Verde = false;
bool chose_Vermelho = false;
bool chose_Amarelo = false;

bool sequencias_diferentes = false;

void som (int luz)
{
    if ( luz < 5 )
    {
      if ( luz == 1)
      { tone (Som, 230, 160); }
      if ( luz == 2)
      { tone (Som, 285, 185); }
      if ( luz == 3)
      { tone (Som, 330, 210); }
      if ( luz == 4)
      { tone (Som, 385, 235); }
      delay(150);
    }
  	else
    {
    tone (Som, 450, 495);
    delay(300);
    }
    noTone (Som);
}


void setup()
{
  pinMode(LAzul, OUTPUT);
  pinMode(LVerde, OUTPUT);
  pinMode(LVermelho, OUTPUT);
  pinMode(LAmarelo, OUTPUT);
  pinMode(BAzul, INPUT);
  pinMode(BVerde, INPUT);
  pinMode(BVermelho, INPUT);
  pinMode(BAmarelo, INPUT);
  
  pinMode(Som, OUTPUT);
  pinMode(Start, INPUT);
  
  randomSeed(analogRead(0));
}


void loop()
{

while ( game_running == false )
  {
  if (digitalRead (Start) == HIGH)
	{
      game_running = true;
    }
  }
               
               
while ( game_running == true )
{
  delay (50);
  // Ler sequencia ja existente
  for ( posicao_atual = 0; posicao_atual < tamanho_ordem; posicao_atual = posicao_atual + 1)
  	{
    luz = sequencia [posicao_atual];
    digitalWrite(luz, HIGH);
    // Comando de som
    som (luz);
    delay (400);
    digitalWrite(luz,LOW);
    delay(400);
  	}
 
  delay (50);
  // Definir nova inclusao na sequencia
  luz = random(1,5);
  sequencia [posicao_atual] = luz;
  digitalWrite(luz, HIGH);
  // Comando de som
  som (luz);
  delay (400);
  digitalWrite(luz,LOW);
  tamanho_ordem = tamanho_ordem + 1;
  delay (200);
  
  
  // Analisar comando do jogador
  posicao_atual = 0;
  while ( posicao_atual < tamanho_ordem && sequencias_diferentes == false)
  {
    while (player_choosing == false)
    {
      if ( digitalRead(BAzul) == HIGH )
      {
        player_choosing = true;
        chose_Azul = true;
      }
      if ( digitalRead(BVerde) == HIGH )
      {
        player_choosing = true;
        chose_Verde = true;
      }
      if ( digitalRead(BVermelho) == HIGH )
      {
        player_choosing = true;
        chose_Vermelho = true;
      }
      if ( digitalRead(BAmarelo) == HIGH )
      {
        player_choosing = true;
        chose_Amarelo = true;
      }
    }
    
    if (chose_Azul)
    {
      sequencia_jogador [posicao_atual] = 1;
      chose_Azul = false;
      digitalWrite(LAzul, HIGH);
      som (1);
      delay (280);
      digitalWrite(LAzul,LOW);
      delay (150);
    }
    if (chose_Verde)
    {
      sequencia_jogador [posicao_atual] = 2;
      chose_Verde = false;
      digitalWrite(LVerde, HIGH);
      som (2);
      delay (280);
      digitalWrite(LVerde,LOW);
      delay (150);
    }
    if (chose_Vermelho)
    {
      sequencia_jogador [posicao_atual] = 3;
      chose_Vermelho = false;
      digitalWrite(LVermelho, HIGH);
      som (3);
      delay (280);
      digitalWrite(LVermelho,LOW);
      delay (150);
    }
    if (chose_Amarelo)
    {
      sequencia_jogador [posicao_atual] = 4;
      chose_Amarelo = false;
      digitalWrite(LAmarelo, HIGH);
      som (4);
      delay (280);
      digitalWrite(LAmarelo,LOW);
      delay (150);
    }
    
    // Checar diferença
    if ( sequencia [posicao_atual] != sequencia_jogador [posicao_atual] )
       {
         sequencias_diferentes = true;
       }
    
    player_choosing = false;
    posicao_atual = posicao_atual + 1;
  }// End analisar comando do jogador
  
  
  // Se o jogador errar, do contrário o ciclo repete
  if ( sequencias_diferentes )
  {
    digitalWrite(LAzul, HIGH);
    digitalWrite(LVerde, HIGH);
    digitalWrite(LVermelho, HIGH);
    digitalWrite(LAmarelo, HIGH);
    for ( x = 0; x < 3; x = x + 1 )
    {som (10);
     delay (100); }
    delay (1300);
    digitalWrite(LAzul,LOW);
    digitalWrite(LVerde,LOW);
    digitalWrite(LVermelho,LOW);
    digitalWrite(LAmarelo,LOW);
    delay(250);
    
    // Resetar
    for ( posicao_atual = 0; posicao_atual < tamanho_ordem; posicao_atual = posicao_atual + 1)
    {
      sequencia [posicao_atual] = 0;
      sequencia_jogador [posicao_atual] = 0;
    }
    tamanho_ordem = 0;
    game_running = false;
    sequencias_diferentes = false;
  }
	delay (200);
}
  
}

