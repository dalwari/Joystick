#include <HID.h>//Human Interface Device
#include <Keyboard.h>//HID device
#include <Platform.h>
int x,y;
int X,Y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
/**************************************/
pinMode(10,INPUT);//up  
pinMode(8,INPUT);//left  
pinMode(12,INPUT);//right
pinMode(2,INPUT); //down
/**************************************/
pinMode(41,INPUT);//Big Bro interact
pinMode(43,INPUT);//Little Bro interact
pinMode(45,INPUT);//Left Rotate Camera
pinMode(47,INPUT);//Right Rotate Camera
/***************************/
pinMode(50,INPUT);//Joystick 1 switch
  digitalWrite(50,HIGH);
/****************************/
pinMode(51,INPUT);//Joystick 2 Switch
  digitalWrite(51,HIGH);
/*****************************/

}

void loop() {
  // put your main code here, to run repeatedly:
  int b1=digitalRead(41);
int b2=digitalRead(43);
int b3=digitalRead(45);
int b4=digitalRead(47);
  
  /*************************************************************************/
//Button Controls  
  if(b1==1)//Big bro interact 
  {
   Serial.println("Button 1 => HIGH");
   
   Keyboard.press(' ');
   
   delay(300);
  }
  else
  {
    Keyboard.release(' ');
   
  }
  if(b2==1)//Little bro interact 
  {
   Serial.println("Button 2 => HIGH");
    Keyboard.press(KEY_RIGHT_CTRL);

   delay(300);
  }else
  {
    Keyboard.release(KEY_RIGHT_CTRL);
    
  }
   if(b3==1)//Rotate camera left
  {
    Serial.println("Button 3 => HIGH");
    Keyboard.press(KEY_LEFT_SHIFT);
    
   delay(300);
  }
  else
  {
    Keyboard.release(KEY_LEFT_SHIFT);
    
  }
  if(b4==1)//Rotate camera Right
  {
    Serial.println("Button 4 => HIGH");
    Keyboard.press(KEY_RIGHT_SHIFT);
    
   delay(300);
  }
  else
  {
    Keyboard.release(KEY_RIGHT_SHIFT);
     
  }
  /*************************************************************************/
  //Joystick 1
  int state=digitalRead(50);
  x=analogRead(A0);
  if (x == 1023) //UP
  {

   Keyboard.press('w');
    
    
  }
  else
  {
    Keyboard.release('w');
    
  }
  x = analogRead(A0);  
  if (x == 0) //DOWN

  {
    Keyboard.press('s');
    
    
    
  }
  else
  {
    Keyboard.release('s');
     
  }
  y = analogRead(A1);  

    if (y == 1023) //RIGHT
    {
      Keyboard.press('d');
      
    
    }
    else
    {
      Keyboard.release('d');
    
    }
  y = analogRead(A1); 

    if (y == 0) //LEFT
    {
      Keyboard.press('a');
    
   
  }
  else
  {

  Keyboard.release('a');
     
  }
int z=digitalRead(50);
    if (z == 0) //ENTER
    {
      Keyboard.press(KEY_RETURN);
     
      delay(300);  
           
   }
   else
   {
    Keyboard.release(KEY_RETURN);
  
   }
  /*************************************************************************/
  //Joystick 2
  X=analogRead(A2);
  if (X == 1023) 
  {
   
    
    Keyboard.press(KEY_UP_ARROW);
    
 
   }
   else
   {
    Keyboard.release(KEY_UP_ARROW);
   }
   X=0;
  X = analogRead(A2);  
  if (X == 0)
  {
     
     Keyboard.press(KEY_DOWN_ARROW);
     
   
    
  }
  else
   {
    Keyboard.release(KEY_DOWN_ARROW);
   } 
  X=0;
  Y = analogRead(A3);  

    if (Y == 1023)
    {   
    
    Keyboard.press(KEY_RIGHT_ARROW);
    
    
     }
     else
   {
    Keyboard.release(KEY_RIGHT_ARROW);
   }
     Y=0;
  Y = analogRead(A3); 

    if (Y == 0)
    {
    
    
    Keyboard.press(KEY_LEFT_ARROW);
     
    
  }
  else
   {
    Keyboard.release(KEY_LEFT_ARROW);
   }
  Y=0;
int Z=digitalRead(51);//ESC
    if (Z == 0) 
    {
     // Serial.println("ESC");
      Keyboard.press(KEY_ESC);
      //Keyboard.println("ESC1");
      delay(500);        
   }
   else
   {
    Keyboard.release(KEY_ESC);
   }
  /*************************************************************************/
}
