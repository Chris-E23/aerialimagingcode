#include <EYW.h>

  //port 12 LED
  //port 9 and 8 ultra sonic sensor
  //port 7 motor/servo
  //port 11 button
  //a4 a5 for altimeter

  int led = 12;  // Pin 13 has an LED connected on most Arduino boards.  Give it a name:
  
  
/*
Altimeter
Measures the height above a reference altitude
*/



EYW::Altimeter myaltimeter;  // this line names the altimeter "myaltimeter"
float current_height=0;      // declares a decimal (float) variable named “current_height” and sets it to zero
float target_altitude_one=0;
float target_altitude_two=0;
float target_altitude_three=0;

/*
RangeFinder
Measures current distance of the closest object
*/

EYW::RangeFinder proximity;  // this line names the rangefinder "proximity"
int distance = 0; // declares an integer variable named “distance” and sets it to zero.  Must be an integer.
float target_distance_one = 0;
float target_distance_two = 0;
float target_distance_three = 0;

/*
Servo rotation
Rotates servo to depress camera shutter
*/

EYW::Camera cameraservo; // this line names the servo "cameraservo"
bool button = false;



void setup() {
  // put your setup code here, to run once:
/*altimeter*/
  Serial.begin(9600);  
  myaltimeter.begin();  // required; initializes the altimeter; no arguments required
  current_height = myaltimeter.getHeight();  // sets variable 'current_height' to the pre-calibrated sensor reading
  Serial.print("Pre-calibration height reading in meters: ");   
    // prints "Pre-calibration height reading in meters: " phrase to the serial monitor
  Serial.println(current_height);   // prints current height value to the serial monitor
  myaltimeter.calibrate(1000); 
    // required; takes 1000 measurements, then calibrates that height to "zero"; argument must be an integer
  myaltimeter.alarm(3,880,1000);    // plays 3 notes at 880 Hz for 1 second each.  Each argument must be an integer

  //rangefinder
  proximity.begin();   // required; initializes the rangefinder; does not need any arguments
  proximity.alarm(6,659,50);  // plays 6 notes at 659 Hz for 50 milliseconds each. Each argument must be an integer
  proximity.calibrate(10);  //waits until sensor sees something 10cm away.  Allows user to verify sensor works properly.

  //servo
  cameraservo.begin(2,4,5);  // initializes the servo.  Arguments are the button, LED, and speaker pin respectively
  cameraservo.calibrate(20,90);  // sweeps the servo back and forth from 20 to 90 degrees. 
                                                   // Make sure arguments are integers between 0 and 180.

  //LED
  pinMode(led, OUTPUT);    // initialize the digital pin as an output.


}

void loop() {
  // put your main code here, to run repeatedly:
  //altimeter

  if(digitalRead(11)){
    button = true;

  }
  else{
    return void; 
  }
  
  
  
  current_height = myaltimeter.getHeightAvg(50);  // takes 50 measurements, sets it equal to "current_height" variable 
    // You can get more accurate readings with a higher number but your readings will be slower
  Serial.print("Current Height in meters: ");   
  Serial.println(current_height);    
  if (current_height<0)   // If the current height is below the starting height, 
  {
    myaltimeter.alarm(6,800,500);  // sound alarm 6 times at 800 Hz
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }

  if (current_height == target_altitude_one || distance == target_distance_one)
  {
    myaltimeter.alarm(6,800,500);  // sound alarm 6 times at 800 Hz
    cameraservo.getPicture(1000,1750);  // rotates servo to depress camera shutter. The servo will depress the button 
                                                                // for 1 second at 20 degrees, then go back to 90 degrees, and waits 1.75
                                                                // seconds before returning to its original position
    myaltimeter.alarm(3,880,1000);    // plays 3 notes at 880 Hz for 1 second each.  Each argument must be an integer
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }

  if (current_height == target_altitude_two || distance == target_distance_two)
  {
    myaltimeter.alarm(6,800,500);  // sound alarm 6 times at 800 Hz
    cameraservo.getPicture(1000,1750);  // rotates servo to depress camera shutter. The servo will depress the button 
                                                                // for 1 second at 20 degrees, then go back to 90 degrees, and waits 1.75
                                                                // seconds before returning to its original position
    myaltimeter.alarm(3,880,1000);    // plays 3 notes at 880 Hz for 1 second each.  Each argument must be an integer
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }

  if (current_height == target_altitude_three || distance == target_distance_two)
  {
    myaltimeter.alarm(6,800,500);  // sound alarm 6 times at 800 Hz
    cameraservo.getPicture(1000,1750);  // rotates servo to depress camera shutter. The servo will depress the button 
                                                                // for 1 second at 20 degrees, then go back to 90 degrees, and waits 1.75
                                                                // seconds before returning to its original position
    myaltimeter.alarm(3,880,1000);    // plays 3 notes at 880 Hz for 1 second each.  Each argument must be an integer
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }

  //rangefinder 
  distance = proximity.getDistance(); 
  // measures the current distance of closest object and assigns it to the “distance” variable, which must be an integer
  Serial.print("Current Distance: ");    
  // prints "Current Distance: " phrase to the serial monitor
  Serial.println(distance);
  // prints current distance value to the serial monitor
  // See live data feed by clicking Tools > Serial Monitor (or Ctrl+Shift+M)

  //servo
 // cameraservo.beginTimer(3000); // starts a 3 second timer; this is a one-time use timer; it cannot be reset
  //if (cameraservo.timerExpired()==true || cameraservo.buttonPressed()==true)
  // checks if the timer is expired or if the button is pressed
  // Comparison Operators: = = (equal to)
  //                                        != (not equal to) 
  //                                        < (less than)
  //                                        > (greater than)
  //                                        <= (less than or equal to)
  //                                        >= (greater than or equal to)
  //                                        || (or)
  //                                        && (and)
//  {
  //  cameraservo.getPicture(1000,1750);  // rotates servo to depress camera shutter. The servo will depress the button 
                                                                // for 1 second at 20 degrees, then go back to 90 degrees, and waits 1.75
                                                                // seconds before returning to its original position
  //}
  
  

  

}
