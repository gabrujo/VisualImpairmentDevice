// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int buzzerS = 7;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 80 && safetyDistance > 70){
  tone(buzzer,400);
  delay(400);
    noTone(buzzer);
    delay(800);
 // digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else if(safetyDistance <= 70 &&  safetyDistance > 50){
   tone(buzzer,800);
    delay(200);
    noTone(buzzer);
    delay(200);
}

else if(safetyDistance <= 50){
   tone(buzzer,1000);
   tone(buzzerS,1000);
    delay(100);
    noTone(buzzer);
    noTone(buzzerS);
    delay(100);
}

else {
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
