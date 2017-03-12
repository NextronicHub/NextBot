#include <AFMotor.h>
#include <RedBot.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

RedBotSensor left = RedBotSensor(A3);   
RedBotSensor center = RedBotSensor(A4);
RedBotSensor right = RedBotSensor(A5); 


#define LINETHRESHOLD 800
#define SPEED 60  

int leftSpeed;  
int rightSpeed;  

void setup()
{
    Serial.begin(9600);
    Serial.println("Welcome to experiment 6.2 - Line Following");
    Serial.println("------------------------------------------");
    delay(2000);
    Serial.println("IR Sensor Readings: ");
    delay(500);

motor1.setSpeed(0);
  motor2.setSpeed(0);
      
      motor1.run(RELEASE);
  motor2.run(RELEASE);
}
int boul =0;
void loop()
{
    Serial.print(left.read());
    Serial.print("\t"); 
    Serial.print(center.read());
    Serial.print("\t"); 
    Serial.print(right.read());
    Serial.println();

////////////////////////////////////////////////////////////////////////////////////////////////////////
if( left.read() > LINETHRESHOLD &&center.read() < LINETHRESHOLD && right.read() > LINETHRESHOLD)
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(80);
    motor2.setSpeed(80);
   
 }
else{
   motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor1.setSpeed(0);
    motor2.setSpeed(0);
  
  
  }

if( left.read() < LINETHRESHOLD &&center.read() > LINETHRESHOLD && right.read() > LINETHRESHOLD)
    {
      boul=1;
      while(boul){
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor1.setSpeed(0);
    motor2.setSpeed(70);

                 if( center.read() < LINETHRESHOLD ){
                  boul=0;    
                  motor1.run(FORWARD);
                  motor2.run(RELEASE);
                  motor1.setSpeed(70);
                  motor2.setSpeed(60);
                  delay(50);
                  }
                 }   
 }
if( left.read()  > LINETHRESHOLD &&center.read() > LINETHRESHOLD && right.read() <  LINETHRESHOLD)
    {
      boul=1;
      while(boul){
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    motor1.setSpeed(70);
    motor2.setSpeed(0);

               if( center.read() < LINETHRESHOLD ){
                            boul=0;    
                            motor1.run(RELEASE);
                            motor2.run(FORWARD);
                            motor1.setSpeed(60);
                            motor2.setSpeed(70);
                            delay(50);
                            }
               }
 }
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

 if(center.read() < LINETHRESHOLD && left.read() < LINETHRESHOLD && right.read() > LINETHRESHOLD)
    {
         motor1.run(BACKWARD);
         motor2.run(FORWARD);
         motor1.setSpeed(0);
        motor2.setSpeed(70);
 }

  else if(center.read() < LINETHRESHOLD && left.read() > LINETHRESHOLD && right.read() < LINETHRESHOLD)
    {
         motor1.run(FORWARD);
         motor2.run(FORWARD);
         motor1.setSpeed(70);
        motor2.setSpeed(0);
 }

///////////////////////////////////////////////////////////////////////////////////////
  if(right.read() < LINETHRESHOLD && center.read() > LINETHRESHOLD && left.read() > LINETHRESHOLD)
    {
        
        motor1.run(FORWARD);
         motor2.run(FORWARD);
        motor1.setSpeed(70);
        motor2.setSpeed(0);
    }
    
if(left.read() < LINETHRESHOLD && center.read() > LINETHRESHOLD && right.read() > LINETHRESHOLD)
    {
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor1.setSpeed(0);
        motor2.setSpeed(70);
    }
    
if((left.read() > LINETHRESHOLD) && (center.read() > LINETHRESHOLD) && (right.read() > LINETHRESHOLD) )
    {
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor1.setSpeed(0);
        motor2.setSpeed(70);
        
    }

     if((left.read() < LINETHRESHOLD) && (center.read() < LINETHRESHOLD) && (right.read() < LINETHRESHOLD) )
    {
        motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(80);
    motor2.setSpeed(80);
    }

    delay(0);  // add a delay to decrease sensitivity.
}

