#include <EYW.h>
#include <HCSR04.h> 
UltraSonicDistanceSensor proximity(6, 7); 
#include <Adafruit_BMP085.h>


  //port 12 LED
  //port 9 and 8 ultra sonic sensor
  //port 7 motor/servo
  //port 11 button
  //a4 a5 for altimeter

  int led = 12;  // Pin 13 has an LED connected on most Arduino boards.  Give it a name:
  int button = 2;
  int distance = 0; 
  int height = 100;

// this library is required when using the ultrasonic rangefinder sensor

EYW::Camera cameraservo; 
bool buttonBool = false;
int speakerPin = 5;
int ledPin = 4;
float currentHeight=0; // declares a decimal (float) variable named “current_height” and sets it to zero
bool heightAchieved = false; 
Adafruit_BMP085 bmp;
int startHeight = 0; 
bool timerEnded = false;
int altitude = 0;
bool calibrated = false;  
int timer = 30000;

void setup() {
 
  Serial.begin(9600);
    if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  cameraservo.begin(2,4,5);  
  cameraservo.calibrate(40,100);  
  pinMode(led, OUTPUT);    
  tone(speakerPin, 250); 
  delay(400);
  noTone(speakerPin); 
  
  
 
  


}

void loop() {
  if(digitalRead(2) == HIGH){
    buttonBool = true; 
  }

  if(!timerEnded && buttonBool){
    delay(timer);
    timerEnded = true; 
     tone(speakerPin, 500); 
    delay(400);
    noTone(speakerPin); 
    if(!calibrated){
      startHeight = bmp.readAltitude(101500);
      Serial.print("Start altitude = ");
      Serial.print(bmp.readAltitude(101500));
      Serial.println(" meters");
      calibrated = true; 

    }

  }
  if(buttonBool && timerEnded){
    digitalWrite(led, HIGH);
   //distance = proximity.measureDistanceCm();
   // Serial.print("Current Distance: ");    
    //Serial.println(distance);

    altitude = bmp.readAltitude(101500);
    if((int)altitude <= (int)(startHeight - 1)){
      Serial.print("Real altitude = ");
      Serial.print(bmp.readAltitude(101500));
      Serial.println(" meters");
      cameraservo.getPicture(200,100);
      tone(speakerPin, 250); 
      delay(400);
      noTone(speakerPin); 
           
    }

   // Serial.print("Real altitude = ");
    //Serial.print(bmp.readAltitude(101500));
    //Serial.println(" meters");

    //if(distance == height){
         //cameraservo.getPicture(200,100);
        //  tone(speakerPin, 250); 
        // delay(400);
         // noTone(speakerPin); 
   // }
 

  }

  
  

  

}
