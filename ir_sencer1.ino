#include <IRremote.h>
int const light = 8;
int spooky[4] = {255,136,132, 84};
int inbtn[11]= {17,21,21,16,18,22,16,18,17,25,20};
int clues; 
int clear = 0; 

void setup()
{
  Serial.begin(19200);
  IrReceiver.begin(5); 
	pinMode(light,OUTPUT);
}


void loop()
{  
  while(clear <= 11){
  if(IrReceiver.decode()){
 	 clues = IrReceiver.decodedIRData.command;
    	Serial.println(clues);
     IrReceiver.resume();
    if(!(clues ==inbtn[clear])){ 
    Serial.println("You done goofed!");
      digitalWrite(light,HIGH);
      delay(300);
      digitalWrite(light,LOW);
      break;
    }
     clear++;
    if(clear == 11){ 
      Serial.println("You didn't goof!");
      digitalWrite(light,HIGH);
      delay(300);
      digitalWrite(light,LOW);
      delay(300);
      digitalWrite(light,HIGH);
      delay(300);
      digitalWrite(light,LOW);
      delay(300);
      digitalWrite(light,HIGH);
      delay(300);
      digitalWrite(light,LOW);
    }
   IrReceiver.resume();
   }
 
  }
  
  clear=0;
}
