#include <EYW.h>
#include <HCSR04.h> 
UltraSonicDistanceSensor proximity(6, 7); 

  //port 12 LED
  //port 9 and 8 ultra sonic sensor
  //port 7 motor/servo
  //port 11 button
  //a4 a5 for altimeter

  int led = 12;  // Pin 13 has an LED connected on most Arduino boards.  Give it a name:
  int button = 2;
  int distance = 0; 
  int targetHeight1 = 100;
  int targetHeight2 = 2;
  int targetHeight3 = 3;
  int speakerPin = 5;
// this library is required when using the ultrasonic rangefinder sensor

EYW::Camera cameraservo; 
bool buttonBool = false;



void setup() {
 
  Serial.begin(9600);
  
  cameraservo.begin(2,4,5);  
  cameraservo.calibrate(20,90);  
  pinMode(led, OUTPUT);    


}

void loop() {
  if(digitalRead(2) == HIGH){
    buttonBool = true; 
  }

  
  if(buttonBool){
    
    digitalWrite(led, HIGH);
    
    distance = proximity.measureDistanceCm();
    Serial.print("Current Distance: ");    
    Serial.println(distance);
    if(distance == targetHeight1){
          cameraservo.getPicture(500,100);
          tone(speakerPin, 250); 
          delay(200);
          noTone(speakerPin); 
    }

  }

  
  

  

}
