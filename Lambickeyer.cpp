// Simple Iambic Keyer v1.00
// by Ernest PA3HCM
// modified by VU3AVE for  ATTINY13 (1.2 MHz internal clock  speed) IC use, which is much cheaper than arduino board



//  You can edit below 2 lines

int Maximum_speed_WPM=30;
int Minimum_speed_WPM=3;

// DONT edit below this line

/*
 1) DOT( dit) is 5th physical pin of the IC ATTINY13
 2) DASH is 6th pin physical pin of the IC ATTINY13
 3) CW out put is at 7th physical pin of the IC ATTINY13
 4) 10k potentiometer(speed control) , center lead connection to 2nd physical pin of the IC ATTINY13
 5) Audio tone in output at 3rd physical pin of the IC ATTINY13
 */
#define P_DOT    0   // Connects to the dot lever of the paddle // for ATTINY13
#define P_DASH   1   // Connects to the dash lever of the paddle // for ATTINY13
#define P_CW     2   // Output of the keyer, connect to your radio // for ATTINY13
#define P_SPEED A3   // Attached to center pin of potmeter, allows you
                     // to set the keying speed. // for ATTINY13
int speed;
#define P_AUDIO 4   // Audio output through speaker // for ATTINY13

void setup()
{
  pinMode(P_DOT, INPUT);
  pinMode(P_DASH, INPUT); 
  pinMode(P_AUDIO, OUTPUT);
  pinMode(P_CW, OUTPUT);
 
}


void loop()
{
speed = 60000 / (map(analogRead(P_SPEED), 0, 1023, Maximum_speed_WPM, Minimum_speed_WPM) * 73);

  // speed = 100;
 if(!digitalRead(P_DOT))        // If the dot lever is presssed..
     {
    keyAndBeep(speed);           // ... send a dot at the given speed
    delay(speed);                //     and wait before sending next
     }


  
if(!digitalRead(P_DASH))       // If the dash lever is pressed...
    {
   keyAndBeep(speed*3);         // ... send a dash at the given speed
   delay(speed);                //     and wait before sending next
    }
  
}


// Key the transmitter and sound a beep
void keyAndBeep(int speed)
{
  digitalWrite(P_CW, HIGH);            // Key down
  for (int i=0; i < speed; i++)    // Beep loop
  {
   digitalWrite(P_AUDIO, HIGH);
   delay(1);
   digitalWrite(P_AUDIO, LOW);
   delay(1);
  }
   digitalWrite(P_CW, LOW);             // Key up
 }
