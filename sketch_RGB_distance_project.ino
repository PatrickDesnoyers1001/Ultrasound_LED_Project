const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;
const int echoPin = 9;
const int trigPin = 8;

int distance;

void setup(){
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
  pinMode(echoPin, INPUT);  
 pinMode(trigPin, OUTPUT);
  Serial.begin(9600); 
}

void loop(){
 sendPing();
 int duration = pulseIn(echoPin, HIGH);
 distance = 0.034 * duration / 2;
 distance = clamp(distance, 0, 50);
 printToScreen(distance); 
 
 if(distance >= 0 && distance <= 15){           
    Blue(255);
    Green(0);
    Red(0);    
    }
else if(distance >= 16 && distance < 33){       
    Green(255);
    Blue(0);
    Red(0);
    }
    else if (distance >= 33 && distance <= 50){
      Red(255);
      Green(0);
      Blue(0); 
    }
}

void Red(int VAL){
 analogWrite(redPin, VAL);
 analogWrite(greenPin, 0);
 analogWrite(bluePin, 0);
}
void Green(int VAL){
 analogWrite(redPin, 0);
 analogWrite(greenPin, VAL);
 analogWrite(bluePin, 0);
}
void Blue(int VAL){
 analogWrite(redPin, 0);
 analogWrite(greenPin, 0);
 analogWrite(bluePin, VAL);
}
void sendPing(){
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
}
int clamp(int VAL, int min, int max){
    if(VAL <= min){
    VAL = min;
    return VAL;
    }
    else if(VAL >= max){
    VAL = max;
    return VAL;
    }
    else{
    return VAL;
    }
}
void printToScreen(int TARGET){
    Serial.print(TARGET);
    Serial.println(" cm");
}
