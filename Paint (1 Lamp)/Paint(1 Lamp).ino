// C++ code
//
#include <Keypad.h>



// Constantes
const int Verde = 10;
const int Azul = 11;
const int Vermelho = 12;


const byte linhas_teclado= 4; // Linhas no keypad
const byte colunas_teclado= 4; // Colunas no keypad

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

// Conexões ao keypad
byte linhas[linhas_teclado] = {9,8,7,6}; //Rows 0 to 3
byte colunas[colunas_teclado]= {5,4,3,2}; //Columns 0 to 3

// Inicialização do keypad
Keypad meuTeclado = Keypad (makeKeymap(Teclas), linhas, colunas, linhas_teclado, colunas_teclado);

void setup()
{
pinMode(Verde, OUTPUT);
pinMode(Azul, OUTPUT);
pinMode(Vermelho, OUTPUT);
}

void loop()
{
// Definir luz da lâmpada
  analogWrite( Vermelho, n_vermelho );
  analogWrite( Verde, n_verde );
  analogWrite( Azul, n_azul );

// Reconhecer qual cor alterar
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

// Reconhecer valor da centena
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

// Reconhecer valor da dezena
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

// Reconhecer valor da unidade
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

// Calcular valor total
  N_Total = (N1 * 100) + (N2 * 10) + (N3);
// Redefinir se ultrapassar o máximo
  if ( N_Total > 255 ) { N_Total = 255; }
  
// Aplicar valor a cor selecionada
  if ( cor == Vermelho ) { n_vermelho = N_Total;  }
  if ( cor == Verde ) { n_verde = N_Total; }
  if ( cor == Azul ) { n_azul = N_Total; }
  
  
}

