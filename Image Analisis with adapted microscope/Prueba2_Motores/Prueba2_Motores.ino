//MOTOR A
int enA = 10; //PWM
int in1 = 9;
int in2 = 8;

//MOTOR B
int enB = 5; //PWM
int in3 = 7;
int in4 = 6;

void setup() {
  //salidas
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // establecer giro de motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //Velocidad de motor A
  analogWrite(enA, 200);
  delay(3000); //tiempo de giro del motor A
  analogWrite(enA, 0); 

  //establecer giro de motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //Velocidad de motor B
  analogWrite(enB, 200);
  delay(3000); //tiempo de giro del motor B
  analogWrite(enB, 0);
  
}
