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
  int targetHeight1 = 180;
  int targetHeight2 = 2;
  int targetHeight3 = 3;

// this library is required when using the ultrasonic rangefinder sensor

EYW::Camera cameraservo; 
bool buttonBool = false;

EYW::Altimeter altitude;
int speakerPin = 5;
int ledPin = 4;
float currentHeight=0; // declares a decimal (float) variable named “current_height” and sets it to zero
bool heightAchieved = false; 


void setup() {
 
  Serial.begin(9600);
  
  cameraservo.begin(2,4,5);  
  cameraservo.calibrate(50,90);  
  pinMode(led, OUTPUT);    
  altitude.begin(); // required; initializes the altimeter; no arguments required
altitude.calibrate(100);
  tone(speakerPin, 250); 
          delay(200);
          noTone(speakerPin); 

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
    //currentHeight = altitude.getHeightAvg(50); // takes 50 measurements, sets it equal to "current_height" variable
    // You can get more accurate readings with a higher number but your readings will be slower
    Serial.print("Current Height in meters: "); // prints current distance value to the serial monitor
    //Serial.println(currentHeight);
    if(distance == targetHeight1){
          cameraservo.getPicture(200,100);
          tone(speakerPin, 250); 
          delay(200);
          noTone(speakerPin); 
    }

  }

  
  

  

}
