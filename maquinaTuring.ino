 /**
 * Universidade Tecnológica Federal do Paraná(UTFPR) - Campus Apucarana
 * Curso: Engenharia de Computação 
 * Disciplina: Teoria da Computação (TCCO5) - 2022/2
 * Professor: Lucio Agostinho Rocha
 * Discente: Mariana Pedroso Naves
 * Projeto: Máquina de Turing no Arduino
*/

// Incluido a biblioteca para uso do Display LCD e da função scanf
#include <LiquidCrystal.h>
#include <ArduinoSTL.h> 

// Inicializando os pinos para habilitar as funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

//Declaração do vetor
char palavra[5];

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas
  // Posiciona o cursor do LCD
  lcd.setCursor(0, 0); // (coluna 0, linha 0)
  lcd.print("Maquina de"); // Imprime mensagem
  lcd.setCursor(0, 1); 
  lcd.print("Turing - UTFPR");
  delay(5000);
  Serial.begin(9600); // Inicializando o monitor serial
}//setup

void loop(){
  //Imprime mensagem no monitor serial
  Serial.println("Digite uma palavra que pertença a linguagem B = {w#w|w ∈ {0, 1}∗}: ");
  //Recebe do usuário a palavra por meio do teclado
  scanf( "%s", palavra);
  Serial.println(palavra);
  // Limpa o LCD
  lcd.clear();
  lcd.print("Fita: "); //Imprime mensagem
  lcd.print(palavra);
  
//========================== Cabeçote sendo 0 ========================== 
  
  ///q1 --> q2
  for(int i=0; palavra[i] != '\0'; i++) {
    if(palavra[0] == '0'){
      palavra[0] = 'x'; //Alterando o símbolo 
      //Imprimindo no monitor serial
      Serial.println("==== Cabeçote sendo 0 =====");
      Serial.println("Fita modificada (q1 --> q2): ");
      Serial.println(palavra);
      //Mudando o visor
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
      
  // q2 --> q2
    if(palavra[1] == '0' || palavra[1] == '1'){
      Serial.println("Fita modificada (q2 --> q2): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else if(palavra[1] == '#'){ // q2 --> q4
        Serial.println("Fita modificada (q2 --> q4): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else {
          naoReconhecida();
        }//else

  // q2 --> q4
    if(palavra[2] == '#'){
      Serial.println("Fita modificada (q2 --> q4): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else {
        naoReconhecida();
      }//else

  // q4 --> q4
    if(palavra[3] == 'x'){
      Serial.println("Fita modificada (q4 --> q4): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else if(palavra[3] == '0'){ // q4 --> q6
        palavra[3] = 'x';
        Serial.println("Fita modificada (q4 --> q6) : ");
        Serial.println(palavra);
        //mudando o visor
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else {
          naoReconhecida();
        }//else

  // q6 --> q6
    if(palavra[2] == '0' || palavra[2] == '1' || palavra[2] == 'x'){
      Serial.println("Fita modificada (q6 --> q6): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else if(palavra[2] == '#'){ // q6 --> q7
        Serial.println("Fita modificada(q6 --> q7) : ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
       } else {
          naoReconhecida();
        }//else

  // q7 --> q7
    if(palavra[1] == '0' || palavra[1] == '1' ){
      Serial.println("Fita modificada (q7 --> q7): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else {
        naoReconhecida();
      }//else

  // q7 --> q1
    if(palavra[0] == 'x'){
      Serial.println("Fita modificada (q7 --> q1): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else {
        naoReconhecida();
        }

  // q1 --> q3
    if(palavra[1] == '1'){
      palavra[1] = 'x';
      Serial.println("Fita modificada (q1 --> q3): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else if(palavra[1] == '#'){ // q1 --> q8
        Serial.println("Fita modificada (q1 --> q8): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else {
          naoReconhecida();
        }//else

  // q3 --> q3
    if(palavra[2] == '0' || palavra[2] == '1' ){
      Serial.println("Fita modificada (q1 --> q3): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else if(palavra[2] == '#'){ // q3 --> q5
        Serial.println("Fita modificada (q3 --> q5): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else {
          naoReconhecida();
        }//else

  // q5 --> q5
    if(palavra[3] == 'x'){
      Serial.println("Fita modificada (q5 --> q5): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else {
        naoReconhecida();
       }//else
       
  // q5 --> q6
    if(palavra[3] == '1' || palavra[4] == '1'){ 
      palavra[3] = 'x';
      palavra[4] = 'x';
      Serial.println("Fita modificada (q5 --> q6): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else {
        naoReconhecida();
      }//else

  // q6 --> q6
    if(palavra[2] == '0' || palavra[2] == '1' || palavra[2] == 'x'){
      Serial.println("Fita modificada (q6 --> q6): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else if(palavra[2] == '#'){ // q6 --> q7
        Serial.println("Fita modificada(q6 --> q7) : ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else {
          naoReconhecida();
        }//else

  // q7 --> q1
    if(palavra[0] == 'x'|| palavra[1] == 'x'){
      Serial.println("Fita modificada (q7 --> q1): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
    } else {
        naoReconhecida();
      }//else
         
  // q1 --> q3
    if(palavra[1] == '1'){
      palavra[1] = 'x';
      Serial.println("Fita modificada (q1 --> q3): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else if(palavra[1] == '#'|| palavra[2] == '#'){// q1 --> q8
        Serial.println("Fita modificada (q1 --> q8): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
       } else {
          naoReconhecida();
        }//else
        
  // q8 --> q8
    if(palavra[2] == 'x'|| palavra[3] == 'x'|| palavra[4] == 'x'){
      Serial.println("Fita modificada (q8 --> q8): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else {
        naoReconhecida();
       }//else

  // q8 --> qaceita
    if(palavra[2] == '\0'||palavra[3] == '\0'||palavra[4] == '\0'){
      Serial.println("Fita modificada (q8 --> qaceita): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
     } else {
        reconhecida();
       }//else 
     }//==== Cabeçote sendo 0 =====
  }//for

//========================== Cabeçote sendo 1 ========================== 
  for(int i=0; palavra[i] != '\0'; i++) {
  
  // q1 --> q3
    if(palavra[0] == '1'){ 
      palavra[0] = 'x';
      Serial.println("==== Cabeçote sendo 1 =====");
      Serial.println("Fita modificada (q1 --> q3) : ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
      
  // q3 --> q3
    if(palavra[1] == '0' || palavra[1] == '1' ){
      Serial.println("Fita modificada (q3 --> q3): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
      if(palavra[2] == '\0'){
        naoReconhecida();
      }//if
    }//if
    
  // q3 --> q5  
      if (palavra[1] == '#'||palavra[2] == '#' ){ 
        Serial.println("Fita modificada (q3 --> q5): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
       }//if
       
  // q5 --> q5 
      if (palavra[3] == 'x'){
        Serial.println("Fita modificada (q5 --> q5): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
       }//if
   
  // q5 --> q6        
       if(palavra[2] == '1' || palavra[3] == '1'){ 
        palavra[2] = 'x';
        Serial.println("Fita modificada (q5 --> q6): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
       } else if(palavra[2] == '0' || palavra[2] == '1'){
          Serial.println("Fita modificada (q6 --> q6): ");
          Serial.println(palavra);
          lcd.clear();
          lcd.print("Nova fita: ");
          lcd.print(palavra);
        } //else if
       
 // q6 --> q7
      if(palavra[2] == '#'|| palavra[1] == '#'){ 
        Serial.println("Fita modificada(q6 --> q7) : ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
  // q7 --> q1
        if(palavra[1] == 'x'|| palavra[0] == 'x'){
          Serial.println("Fita modificada (q7 --> q1): ");
          Serial.println(palavra);
          lcd.clear();
          lcd.print("Nova fita: ");
          lcd.print(palavra);
        }//if
      }//if

 // q1 --> q8
        if(palavra[1] == '#'|| palavra[2] == '#'){
          Serial.println("Fita modificada (q1 --> q8): ");
          Serial.println(palavra);
          lcd.clear();
          lcd.print("Nova fita: ");
          lcd.print(palavra);
  // q8 --> q8     
          if(palavra[2] == 'x'|| palavra[3] == 'x'|| palavra[4] == 'x'){
            Serial.println("Fita modificada (q8 --> q8): ");
            Serial.println(palavra);
            lcd.clear();
            lcd.print("Nova fita: ");
            lcd.print(palavra);
            if (palavra[3] == '\0'){
              reconhecida();
            }//if
          }//if
        }//if
     }//if
   }//for

//========================== Cabeçote sendo # ========================== 

  // q1 --> q8
     if(palavra[0] == '#'){
      Serial.println("==== Cabeçote sendo # =====");
      Serial.println("Fita modificada (q1 --> q8): ");
      Serial.println(palavra);
      lcd.clear();
      lcd.print("Nova fita: ");
      lcd.print(palavra);
      if(palavra[1] == 'x'|| palavra[2] == 'x'|| palavra[3] == 'x'){
        Serial.println("Fita modificada (q8 --> q8): ");
        Serial.println(palavra);
        lcd.clear();
        lcd.print("Nova fita: ");
        lcd.print(palavra);
      } else{
          naoReconhecida();
        }//else
      
      if (palavra[2] == '\0'|| palavra[3] == '\0'||palavra[4] == '\0'){
        reconhecida();
      }//if
     }//if
 }//loop

  void naoReconhecida(){
    Serial.print("Palavra não reconhecida: ");
    Serial.println(palavra);
    //mudando o visor
    lcd.clear();
    lcd.print("Nova fita: ");
    lcd.setCursor(0, 1);
    lcd.print("qrejeita.");
  }//naoReconhecida()

  void reconhecida(){
    Serial.print("Palavra reconhecida: ");
    Serial.println(palavra);
    //mudando o visor
    lcd.clear();
    lcd.print("Nova fita: ");
    lcd.setCursor(0, 1);
    lcd.print("qaceita.");
  }//reconhecida()
