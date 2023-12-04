//mouvement de joystick fait bouger le point sur la matrice led


#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); 
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() 
{

  Serial.begin(9600);
  
  lc.shutdown(0, false);  // The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
  lc.setIntensity(0, 0); // Set the brightness to a medium values 
  lc.clearDisplay(0); //   and clear the display 
   
}

void loop() {

  int col = 3; // intilaisation des corrdonées du point sur la matrice
  int row = 5;

boucle :

  Serial.print("X : ");
  int axeX = (analogRead(X_pin) / 100);
  Serial.println(axeX);

  Serial.print("Y : ");
  int axeY = (analogRead(Y_pin) / 100);
  Serial.println(axeY);
  

  switch (axeX)
  {
    case 0:
      row = row-2;
    case 10:
      row = row+1;
  }

  switch (axeY) //
  {
    case 0:
      col = col+2;
    case 10:
      col = col-1;
  }


  lc.setLed(0, col, row, true); // éclairage de la case voulue
  delay(100);
  lc.setLed(0, col, row, false); // extinction de la case voulue
  
  Serial.print ("col "); Serial.println(col);
  Serial.print ("row ");  Serial.println(row);

  goto boucle;

}
