#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = A0;
int val = 0;
int limit = 40;

void setup() {
  Serial.begin(9600);
  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  
  lcd.begin(16, 2);
  
  lcd.print("Air Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(500); 
  lcd.clear();
}



void loop() {
  
  val = analogRead(sensor);        
  val = map(val, 306, 750, 0, 100); 
  Serial.println(val);              
  lcd.setCursor(0,0);
  lcd.print("Particle contnet in air is ");
  lcd.setCursor(0, 1);
  lcd.print(val);


    if (val > limit) {
      
      lcd.setCursor(0, 0);
      lcd.print("Harmful Gas is");  
      lcd.setCursor(0, 1);
      lcd.print(val);
      digitalWrite(7, HIGH);        
      digitalWrite(6, LOW);         
      tone(8, 1000);                
      delay(100);                   
      noTone(8);                    
      delay(100);                   
    }
    
    else { 
      lcd.clear();                 
      noTone(8);                   
      digitalWrite(7, LOW);        
      digitalWrite(6, HIGH);       
    } 
}
