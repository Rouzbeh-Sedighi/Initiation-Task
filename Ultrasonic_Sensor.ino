int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo

int redPin= 5; //red
int greenPin = 3; //green
int bluePin = 2; //blue
float duration, distance;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop() {
  
  if (Serial.available()){
    char ReadCommand =(char)Serial.read();
    if (ReadCommand == 'R'){
      setColor(255, 0, 0); // Red Color
    }
    else if (ReadCommand == 'G'){
      setColor(0, 255, 0); // Green Color
    }
    else if (ReadCommand == 'B'){
      setColor(0, 0, 255); // Blue Color
    }
    else if (ReadCommand == 'W'){
      setColor(255, 255, 255); // White Color
    }
    else if(ReadCommand == 'P'){
      setColor(170, 0, 255); // Purple Color
    }
     else if(ReadCommand == 'f'){
      analogWrite(redPin, 0); //turn off red 
      analogWrite(greenPin, 0); //turn off green       
      analogWrite(bluePin, 0); // turn off Color
    }
  }
  
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  distance = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  
  //Serial.print("Distance = ");
  Serial.print(distance);
  //Serial.print("cm");
  Serial.println();
  
  delay(500);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
