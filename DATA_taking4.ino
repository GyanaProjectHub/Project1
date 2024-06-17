
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5); // RX, TX

const int hallPin = 2;
const int currentSensorPin = A0;
volatile int count = 0;
unsigned long CT1,PT1 ,PT2;
float speed=0;
float distance=0.000;
float current =0.00;
float voltage =52;
float efficiency =0.00;
float energy =0.00;

void hallInterrupt() {
    CT1=millis();
    if((CT1-PT1)>16)
    {
    speed=(0.2932/(CT1-PT1))*1000;
    count++;
    }
    PT1=CT1;   
}


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
   mySerial.begin(9600);
   pinMode(hallPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(hallPin), hallInterrupt, RISING);
}

void loop() { // run over and over

  PT1=millis();
  PT2=PT1;
  float currentSum = 0.0;

  for (int j = 0; j < 2000; j++) {
    float analog_value = analogRead(currentSensorPin);
    float current = (analog_value - 320.099) * 0.1688;
    currentSum += current;
    delayMicroseconds(100);
  }
   current = currentSum / 2000.0;

   energy += voltage*current*0.5/3600;

   if(PT1 == PT2)
   {
    speed=0;
   }
    distance=count * 0.293;

    if(energy >0)
    {
      efficiency=distance/energy;
    }
    else
      efficiency =0.00;
    
    mySerial.println("||"+String(speed*3.6)+"||"+String(current)+"||"+String(distance*0.001 ,2)+"||"+String(voltage)+"||" + String(efficiency)+"||"+String(energy)+"||");
    Serial.println(String(speed*3.6)+"||"+String(current)+"||"+String(distance*0.001 ,2)+"||"+String(voltage)+"||" + String(efficiency)+"||"+String(energy));

    delay(300);
   
}


/*
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2); // RX, TX



void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
   mySerial.begin(9600);
   pinMode(hallPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(hallPin), hallInterrupt, RISING);

}

void loop() { // run over and over

    for(int i=0;i<10;i++){
    mySerial.println(String(i)+"||"+String(i+1)+"||"+String(i+2)+"||");
    Serial.println(String(i)+","+String(i+1)+","+String(i+2));

    delay(500);
    }
}
*/
