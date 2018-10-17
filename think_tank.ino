#include <Mindwave.h>

Mindwave mindwave;

void setup() {
  Serial.begin(MINDWAVE_BAUDRATE);
    pinMode(7, OUTPUT);      // led is connecvtvted to this pin for showing the attention level 1 (20%-40%)
    pinMode(8, OUTPUT);      // led is connecvtvted to this pin for showing the attention level 2 (40%-60%)
     pinMode(9, OUTPUT);     // led is connecvtvted to this pin for showing the attention level 3 (60%-70%)
    pinMode(10, OUTPUT);     // led is connecvtvted to this pin for showing the attention level 4 (70%-80%, Relay is connected to ppin number 11 which trigers the water pump (0.5HP)
  
}
void onMindwaveData(){
  Serial.print("\tquality: ");
  Serial.print(mindwave.quality());
  Serial.print("\tattention: ");
  Serial.print(mindwave.attention());
  if (20<mindwave.attention() && mindwave.attention()<40)   // range of the neurosky sensor input to arduino
  {
    digitalWrite(7, HIGH);
    
    //turn the LED on (HIGH is the voltage level)
  }
   else if (40<mindwave.attention() && mindwave.attention()<60) // range of the neurosky sensor input to arduino
  {
   
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    //turn the LED on (HIGH is the voltage level)
  }
else if (60<mindwave.attention() && mindwave.attention()<70)   // range of the neurosky sensor input to arduino
  {
    
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
   
    //turn the LED on (HIGH is the voltage level)
  }
  else if (70<mindwave.attention() && mindwave.attention()<80)   // range of the neurosky sensor input to arduino
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
   
    //turn the LED on (HIGH is the voltage level)
  }
  
 
    else                                           
    {digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);                                          // if above range/ condition not satisfied then make all pin LOW
    digitalWrite(10,LOW);
   
    }
  
    // turn the LED on (HIGH is the voltage level)
  

  Serial.print("\tmeditation: ");                                 // for printing on serial monitor
  Serial.print(mindwave.meditation());
  Serial.print("\tlast update: ");
  Serial.print(mindwave.lastUpdate());
  Serial.print("ms ago");
  Serial.println();
}
void loop() {
  mindwave.update(Serial,onMindwaveData);
}
