3#define PIN_LED1 2
#define PIN_LED2 3
#define PIN_LED3 4
// Le numéro de la broche sur laquelle la lampe 1 
//(par défaut intégrée dans la carte) est branchée 
char data; // variable contenant le caractère lu
const int buzzer = 9; //buzzer to arduino pin 9

void setup() {
 digitalWrite(PIN_LED1,LOW);
  digitalWrite(PIN_LED2,LOW);
  digitalWrite(PIN_LED3,LOW);
  // Configure la broche 13 sur laquelle est reliée notre LED  en sortie
  for (int i=2;i<5;i++)
  {pinMode(i,OUTPUT);
  Serial.begin(9600);
  }//Permet d'initialiser le moniteur série à 9600 bauds 
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}



void loop() {
  
  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     if(data=='1') //si le caractère lu est égale à 1
    {     for(int i=2;i<5;i++)
      {digitalWrite(i,HIGH); 
       delay(500);
       digitalWrite(i,LOW);  
      }    
     }
      else if (data=='2'){
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1sec
      }     
      }
      }
