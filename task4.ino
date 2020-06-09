int trigPin1=3;
int trigPin2=5;
int trigPin3=7;
int trigPin4=9;

int echoPin1=2;
int echoPin2=4;
int echoPin3=6;
int echoPin4=8;

int buzzer=13;

int distance[4];
long duration[4];

void setup() {
  
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);

  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);

  pinMode(buzzer, OUTPUT);

}

void sensor(){

 for(int i=1;i<=4;i++)
 {
  digitalWrite(2i+1, HIGH);
 }

 delay(1000);

 for(int i=1;i<=4;i++)
 {
  digitalWrite(2i+1, LOW);
 }
}




void take(){
  for(int i=1;i<=4;i++){
    duration[i-1]=pulseIn(2i,HIGH);
    distance[i-1]=((duration[i-1])*0.034)/2);
    
  }
}


void buzz(){

  for(int i=0;i<4;i++){

    if(distance[i]<10){
      
      tone(buzzer,1000);
    }
    else{
      noTone(buzzer);
    }
  }
}


void loop() {

  sensor();
  take();
  buzz();

}
