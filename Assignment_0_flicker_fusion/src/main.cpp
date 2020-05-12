#include<Arduino.h>
#define   ledPin  13
#define  Button_Pin  5
//-------------------------------DECLARATION OF VARIABLES-------------------------------------------------------
 bool   ledState  = 0;  //LED State
 uint32_t   time_period = 0;  //Input from Serial  Communication -
 int value = 0 ;  //For accumulate the ascii values
 float Frequency = 0;//Frequency derived from system
 volatile uint32_t Previous_Time = 0;//Variable will store the last time value
 volatile uint32_t Current_Time = 0;//Variable will store the current time value
 uint8_t buttonState = 0;//Variable will store the last time value
 const int32_t debounce_Time = 150;//To make a debounce delay
 void Serial_com();//Function for serial commuication for input the values
 void buttonpress_ISR(); //Interrupt fuction
 void setup(){
  pinMode(ledPin, OUTPUT);//To declare the pin as a digital OUTPUT
  pinMode(Button_Pin, INPUT_PULLUP);//To declare the pin as a digital INPUT
  Serial.begin(115200);//Baud RATE
  attachInterrupt(digitalPinToInterrupt(Button_Pin), buttonpress_ISR, FALLING); // button press enable interrupt function
  }
  void loop() {
    Serial_com();// Calling Serial Communication Function
    Frequency =(500/time_period);//For calculating frequency & Time period
    Current_Time = millis();//Declaring variable is using millis
    if(Current_Time - Previous_Time >= Frequency)//Loop the LED toogling
      {
        ledState = !ledState;//Inverse the led state
        //plot point-1
        //Serial.println(ledState);//for plotting the graph
        digitalWrite(ledPin,ledState);
        //plot point-2
       // Serial.println(ledState);//for plotting the graph
        Previous_Time = Current_Time;
      }
     buttonState = digitalRead(Button_Pin);
    }
 // -------------------------------SERIAL COMMUNICATION FOR INPUT THE TIME/VALUES------------------------
  void Serial_com(){
  if( Serial.available())
  {
     char ch = Serial.read();
    if(ch >= '0' && ch <= '9') // is this an ascii digit between 0 and 9?
    {
       value = (value * 10) + (ch - '0'); // yes, accumulate the value
    }
    else if (ch == 10)  // is the character the newline character
    {
       time_period = value;  // set blinkrate to the accumulated value
      // Serial.println(blinkRate);
       value = 0; // reset val to 0 ready for the next sequence of digits
    }
   }
  }
//------------------------------------INTERRUPT USING EXTERNAL BUTTON-----------------------
 void buttonpress_ISR()                                                    // Interrupt function
{
  static uint32_t previoustimebutton_ms = 0;                              // Variable for debouncing
  uint32_t currenttimebutton_ms = millis();                               // Variable for debouncing
   if((currenttimebutton_ms - previoustimebutton_ms) >= debounce_Time) // Code inside loop only executes if buttonpress time is greater than debounce delay_ms
  { buttonState = !buttonState;
    previoustimebutton_ms = currenttimebutton_ms;
    // printing commands to print Flicker fusion frequency and timeperiod
    Serial.print("\nFrequency:");
    Serial.print(Frequency);
    Serial.print("Hz");
    Serial.print("       Time:");
    Serial.print(time_period);
    Serial.print("ms");
  }
}