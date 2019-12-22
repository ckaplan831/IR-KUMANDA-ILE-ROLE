   
#include "IRremote.h" 
int receiver = 10;
int IR_pozitif_pin = 11; 
int IR_negatif_pin = 12;
int relay_1 = 9;
int relay_2 = 8;
int relay_3 = 7;
int relay_4 = 6;
int relay_5 = 5;
int relay_6 = 4;
int relay_7 = 3;
int relay_8 = 2;
IRrecv irrecv(receiver);    
decode_results results;  
void setup()
{
  pinMode(IR_negatif_pin, OUTPUT);
  pinMode(IR_pozitif_pin, OUTPUT);
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  pinMode(relay_5, OUTPUT);
  pinMode(relay_6, OUTPUT);
  pinMode(relay_7, OUTPUT);
  pinMode(relay_8, OUTPUT);
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
  digitalWrite(relay_4, HIGH);
  digitalWrite(relay_5, HIGH);
  digitalWrite(relay_6, HIGH);
  digitalWrite(relay_7, HIGH);
  digitalWrite(relay_8, HIGH);
  digitalWrite(IR_negatif_pin, LOW);
  digitalWrite(IR_pozitif_pin, HIGH);
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); 
}
void loop(){
  if (irrecv.decode(&results)) {translateIR(); irrecv.resume();}  
  if (digitalRead(relay_1) == HIGH && results.value == 0xFF6897){relay_1_on (); results.value=0;}
  if (digitalRead(relay_1) == LOW && results.value == 0xFF6897){relay_1_off (); results.value=0;}
  if (digitalRead(relay_2) == HIGH && results.value == 0xFF9867){relay_2_on (); results.value=0;}
  if (digitalRead(relay_2) == LOW && results.value == 0xFF9867){relay_2_off (); results.value=0;} 
  if (digitalRead(relay_3) == HIGH && results.value == 0xFFB04F){relay_3_on (); results.value=0;}
  if (digitalRead(relay_3) == LOW && results.value == 0xFFB04F){relay_3_off (); results.value=0;} 
  if (digitalRead(relay_4) == HIGH && results.value == 0xFF30CF){relay_4_on (); results.value=0;}
  if (digitalRead(relay_4) == LOW && results.value == 0xFF30CF){relay_4_off (); results.value=0;}
  if (digitalRead(relay_5) == HIGH && results.value == 0xFF18E7){relay_5_on (); results.value=0;}
  if (digitalRead(relay_5) == LOW && results.value == 0xFF18E7){relay_5_off (); results.value=0;} 
  if (digitalRead(relay_6) == HIGH && results.value == 0xFF7A85){relay_6_on (); results.value=0;}
  if (digitalRead(relay_6) == LOW && results.value == 0xFF7A85){relay_6_off (); results.value=0;} 
  if (digitalRead(relay_7) == HIGH && results.value == 0xFF10EF){relay_7_on (); results.value=0;}
  if (digitalRead(relay_7) == LOW && results.value == 0xFF10EF){relay_7_off (); results.value=0;} 
  if (digitalRead(relay_8) == HIGH && results.value == 0xFF38C7){relay_8_on (); results.value=0;}
  if (digitalRead(relay_8) == LOW && results.value == 0xFF38C7){relay_8_off (); results.value=0;}   
  if (results.value == 0xFF42BD){yak (); results.value=0;} 
  if (results.value == 0xFF52AD){sondur (); results.value=0;}   
}
void translateIR(){switch(results.value) 
  { 
  case 0xFF629D: Serial.println(" 0"); break;
  case 0xFF22DD: Serial.println(" 2");    break;
  case 0xFF02FD: Serial.println(" 3");    break;
  case 0xFFC23D: Serial.println(" 4");   break;
  case 0xFFA857: Serial.println(" 5"); break;
  case 0xFF6897: Serial.println(" 6");    break;
  case 0xFF9867: Serial.println(" 7");    break;
  case 0xFFB04F: Serial.println(" 8");    break;
  case 0xFF30CF: Serial.println(" 9");    break;
  case 0xFF18E7: Serial.println(" *");    break;
  case 0xFF7A85: Serial.println(" ");    break;
  case 0xFF10EF: Serial.println(" #");    break;
  case 0xFF38C7: Serial.println(" -ok-");    break;
  case 0xFF5AA5: Serial.println(" REPEAT");    break;
  case 0xFF42BD: Serial.println(" LEFT");    break;
  case 0xFF4AB5: Serial.println(" RIGHT");    break;
  case 0xFF52AD: Serial.println(" REVERSE");    break;
  case 0xFFFFFFFF: Serial.println(" 0");break;  
  default: 
    Serial.println(" other button   ");
   }
   delay(500); 
} 
void relay_1_on(){digitalWrite(relay_1, LOW);}
void relay_1_off(){digitalWrite(relay_1, HIGH);}
void relay_2_on(){digitalWrite(relay_2, LOW);}
void relay_2_off(){digitalWrite(relay_2, HIGH);}
void relay_3_on(){digitalWrite(relay_3, LOW);}
void relay_3_off(){digitalWrite(relay_3, HIGH);}
void relay_4_on(){digitalWrite(relay_4, LOW);}
void relay_4_off(){digitalWrite(relay_4, HIGH);}
void relay_5_on(){digitalWrite(relay_5, LOW);}
void relay_5_off(){digitalWrite(relay_5, HIGH);}
void relay_6_on(){digitalWrite(relay_6, LOW);}
void relay_6_off(){digitalWrite(relay_6, HIGH);}
void relay_7_on(){digitalWrite(relay_7, LOW);}
void relay_7_off(){digitalWrite(relay_7, HIGH);}
void relay_8_on(){digitalWrite(relay_8, LOW);}
void relay_8_off(){digitalWrite(relay_8, HIGH);}
void yak(){
  digitalWrite(relay_1, LOW); 
  digitalWrite(relay_2, LOW); 
  digitalWrite(relay_3, LOW); 
  digitalWrite(relay_4, LOW); 
  digitalWrite(relay_5, LOW); 
  digitalWrite(relay_6, LOW); 
  digitalWrite(relay_7, LOW); 
  digitalWrite(relay_8, LOW);
}
void sondur(){
  digitalWrite(relay_1, HIGH); 
  digitalWrite(relay_2, HIGH); 
  digitalWrite(relay_3, HIGH); 
  digitalWrite(relay_4, HIGH); 
  digitalWrite(relay_5, HIGH); 
  digitalWrite(relay_6, HIGH); 
  digitalWrite(relay_7, HIGH); 
  digitalWrite(relay_8, HIGH);
  }
