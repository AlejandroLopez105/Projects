// motor A
int enA = 10; //Habilita motor A = PWM
int in1 = 9; // Sentido de giro
int in2 = 8; // Sentido de giro

// motor B
int enB = 5; //Habilita motor B = PWM
int in3 = 7;
int in4 = 6;

void setup ()
{
  //Todos los pines como salidas 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

 //Gira el motor A en la direeción deseada ("in1, HIGH"-dirección horaria, "in2, HIGH"-dirección antihoraria)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Setea la velocidad deseada del motor A
  analogWrite(enA, 100);
  // Gira el motor B en la dirección deseada
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //setea la velocidad deseada del motor B
  analogWrite(enB, 200);
  delay(3000); // Tiempo de giro de los motores 

  //Apagar los motores
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

  
