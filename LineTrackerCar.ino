// Adafruit Motor shield library copyright
// @Youssouf_IRO

#include <AFMotor.h>

 AF_DCMotor motor1(1, MOTOR12_8KHZ);
 AF_DCMotor motor2(2, MOTOR12_8KHZ);
 AF_DCMotor motor3(3, MOTOR34_1KHZ);
 AF_DCMotor motor4(4, MOTOR34_1KHZ);

// LED IR for movement control
#define RIGHT A0
#define MIDRIGHT A1
#define MIDLEFT A2
#define LEFT A3

// Variable 
short int compteur;

void setup() {
  // initiate communication with serial port
  Serial.begin (9600);
  Serial.println ("Motor test");
  // Declaring pin type
  pinMode (MIDLEFT, INPUT);
  pinMode (MIDRIGHT, INPUT);
  pinMode (LEFT, INPUT);
  pinMode (RIGHT, INPUT);
  compteur =0;
}

void loop() {
  
  if ( !digitalRead(MIDLEFT)== 0 && !digitalRead(MIDRIGHT) == 0 )
   {          GoForward ();
              delay (50);
              Release ();      
    }
   if ( digitalRead(MIDLEFT)== 0 && !digitalRead(MIDRIGHT)== 0 )
   {
               GoRight ();
               delay (50);
               Release (); 
     }
   if ( !digitalRead(MIDLEFT)== 0 && digitalRead(MIDRIGHT)== 0) 
    {
               GoLeft ();
               delay (50);
               Release (); 
      }
    if (( digitalRead(MIDLEFT)== 0 && digitalRead(MIDRIGHT) == 0 ))
     {
        Release (); 
        compteur++;
        if (compteur >= 5)
        {
          if (!digitalRead(RIGHT)==0)
          {
               GoRight ();
               delay (50);
               Release ();
            }
         if (!digitalRead(LEFT)==0)
          {
               GoLeft ();
               delay (50);
               Release ();
            }
            compteur=0;
        }
       } 
}
// Move Forward
void GoForward ()
{
  motor1.setSpeed(50);  // speed 200 (Maximal 255 possible)
  motor1.run(FORWARD);

  motor2.setSpeed(50);  // speed 200 (Maximal 255 possible)
  motor2.run(FORWARD);

  motor3.setSpeed(75);
  motor3.run(FORWARD);

  motor4.setSpeed(75);
  motor4.run(FORWARD);
  } 

  // Release
  void Release ()
  {
  
  motor1.run(RELEASE);

  motor2.run(RELEASE);
  
  motor3.run(RELEASE);

  motor4.run(RELEASE);
    }

   // Move Right
   void GoRight ()
   {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);

  motor2.setSpeed(255);  // speed 100 (Maximal 255 possible)
  motor2.run(BACKWARD);

  motor3.setSpeed(255);  // speed 50 (Maximal 255 possible)
  motor3.run(FORWARD);
  
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  

    }

      // Move Left
   void GoLeft ()
   {
  motor1.setSpeed(255);  // speed 50 (Maximal 255 possible)
  motor1.run(FORWARD);

  motor2.setSpeed(255);
  motor2.run(FORWARD);
  
  motor3.setSpeed(255);
  motor3.run(BACKWARD);

  motor4.setSpeed(255);  // speed 50 (Maximal 255 possible)
  motor4.run(BACKWARD);
    }
