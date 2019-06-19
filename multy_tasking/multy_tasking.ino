const int buttonPin1 = 22;     // the number of the pushbutton pin
const int buttonPin2 = 23;  
const int RELAY1 =  13;  
boolean otomatis1 = false;
boolean otomatis2 = false;
boolean flag = false;
boolean flag2 = false;
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (RELAY1,OUTPUT);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

    //tombol datang
  if (buttonState1 == HIGH) {
   otomatis2=false;
   otomatis1 = true;
  } else if (buttonState2 == HIGH) {
   otomatis1 = false;
   otomatis2 = true;
  } else {
    // turn LED off:
    digitalWrite(RELAY1, LOW);
  }
//masuk
 if(otomatis1){
     if(flag){
      //RELAY 1
  digitalWrite(RELAY1,HIGH);
  delay(100);
  digitalWrite(RELAY1,LOW);
  delay(50);
  flag=false;
  delay(100);
  }else{
      digitalWrite(RELAY1,LOW);
      flag=true;
  
}
 }

 //pulang
 if(otomatis2){
     if(flag){
      //RELAY 1
  digitalWrite(RELAY1,HIGH);
  delay(1000);
  digitalWrite(RELAY1,LOW);
  delay(100);
  flag=false;
  delay(100);
  }else{
      digitalWrite(RELAY1,LOW);
      flag=true;
  
}
 }
 delay(100);
}

