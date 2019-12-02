#include <LiquidCrystal.h>
#include <Keypad.h> 

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //RS,E,D4,D5,D6,D7

const byte filas = 4;
const byte colunas = 4;

char tecla[filas][colunas] = { //Matriz do teclado
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Determinar os pinos de saída do teclado.
byte pinFilas[filas] = {7, 6, 5, 4}; 
byte pinColunas[colunas] = {3, 2, A4, A5}; 

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColunas, filas, colunas );

int count = 0;  // Contador para saber quantos numeros foram digitados
char Correto[16] = "1234";  // Define a senha padrão
char digitos[16]; // Armazena a senha digitada pelo teclado

void setup() {
  lcd.begin(16, 2); // Inicia o LCD (16 colunas e 2 linhas)
  lcd.clear(); // Limpa o display
  lcd.setCursor(0, 0); // Coloca o cursor no ponto 0
  lcd.print("Digite a senha:");
}

void loop() {
  char key; // Recebe os digitos

  while (!key) { // Loop que detecta quando uma tecla for presionada e armazena ela na variável "key"
    key = keypad.getKey();
  }

  if (key == 'D' || count == 16) { // Se clicar no D ou se der 16 dígitos, entra na condição

 	if (strcmp(digitos, Correto) == 0) { // Compara a senha digitada com a senha estabelecida
        lcd.clear(); // limpa a tela
        lcd.setCursor(1, 0); // anda o cursor
        correta();
      	reset();
	} else {
		lcd.clear();
		lcd.setCursor(0, 0);
    	lcd.print("Senha incorreta");
    	delay(2000);
    	lcd.clear();;
    	lcd.setCursor(0, 0);
    	lcd.print("Tente novamente");
    	delay(1000);
    	reset();
	}
  } else {
	lcd.setCursor(count, 1); //Movimenta o cursor +1 coluna na linha 1
	lcd.print("*"); //Imprime * no display
	digitos[count] = key; // Salva o número que você digitou no vetor "digitando"
	count++; // Aumenta +1 no contador de numeros digitados
  }
}

// Função de animação de senha correta
void correta(){ 
	lcd.print("Senha Correta!"); 
    delay(300);
    lcd.clear();
	delay(300);
    lcd.print("Senha Correta!"); 
    delay(300);
    lcd.clear();
    delay(300);
    lcd.print("Senha Correta!"); 
    delay(1500);
}

// Função de reset
void reset(){ 
	lcd.clear(); // limpa a tela
	lcd.setCursor(0, 0); // Coloca o cursor no inicio do display
	lcd.print("Digite a senha:");
	count = 0; // Zera o contador de numeros digitados
	for(int i = 0; i < 16; i++){  //Limpa o vetor pra você poder digitar a senha novamente
		digitos[i] = '\0';
	} 
}