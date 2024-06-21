// C++ code
//
#include <Keypad.h>



// Constantes
const int Verde = 10;
const int Azul = 11;
const int Vermelho = 12;
const int EmEscolha = 13;


const byte linhas_teclado= 4; //number of rows on the keypad
const byte colunas_teclado= 4; //number of columns on the keypad

int N1 = 0, N2 = 0, N3 = 0, N_Total = 0;
int cor = 0;
int n_vermelho = 255, n_verde = 255, n_azul = 255;
bool selecionada_cor = false, n_selecionado = false;
char botao;

//Keymap
char Teclas[linhas_teclado][colunas_teclado]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte linhas[linhas_teclado] = {9,8,7,6}; //Rows 0 to 3
byte colunas[colunas_teclado]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad meuTeclado = Keypad (makeKeymap(Teclas), linhas, colunas, linhas_teclado, colunas_teclado);

void setup()
{
pinMode(Verde, OUTPUT);
pinMode(Azul, OUTPUT);
pinMode(Vermelho, OUTPUT);
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
  analogWrite( Vermelho, n_vermelho );
  analogWrite( Verde, n_verde );
  analogWrite( Azul, n_azul );

  digitalWrite ( EmEscolha, LOW );
  
  while ( selecionada_cor == false )
  {
	botao = meuTeclado.getKey();
    if ( botao == 'A' || botao == 'B'|| botao == 'C')
    {
      selecionada_cor = true;
      if ( botao == 'A' )
      {
        cor = Vermelho;
      }
      if ( botao == 'B' )
      {
        cor = Verde;
      }
      if ( botao == 'C' )
      {
        cor = Azul;
      }
    }
  }
  selecionada_cor = false;
  digitalWrite ( EmEscolha, HIGH );
  
  while ( n_selecionado == false )
  {
    botao = meuTeclado.getKey();
    if ( botao == '0' || botao == '1' || botao == '2'
		|| botao == '3' || botao == '4' || botao == '5'
		|| botao == '6' || botao == '7' || botao == '8'
		|| botao == '9' )
    {
     N1 = botao - '0';
     n_selecionado = true;
    }
  }
  n_selecionado = false;

  while ( n_selecionado == false )
  {
    botao = meuTeclado.getKey();
    if ( botao == '0' || botao == '1' || botao == '2'
		|| botao == '3' || botao == '4' || botao == '5'
		|| botao == '6' || botao == '7' || botao == '8'
		|| botao == '9' )
    {
     N2 = botao - '0';
     n_selecionado = true;
    }
  }
  n_selecionado = false;
  
  while ( n_selecionado == false )
  {
    botao = meuTeclado.getKey();
    if ( botao == '0' || botao == '1' || botao == '2'
		|| botao == '3' || botao == '4' || botao == '5'
		|| botao == '6' || botao == '7' || botao == '8'
		|| botao == '9' )
    {
     N3 = botao - '0';
     n_selecionado = true;
    }
  }
  n_selecionado = false;

  N_Total = (N1 * 100) + (N2 * 10) + (N3);
  if ( N_Total > 255 ) { N_Total = 255; }
  
  if ( cor == Vermelho ) { n_vermelho = N_Total;  }
  if ( cor == Verde ) { n_verde = N_Total; }
  if ( cor == Azul ) { n_azul = N_Total; }
  
  
}

