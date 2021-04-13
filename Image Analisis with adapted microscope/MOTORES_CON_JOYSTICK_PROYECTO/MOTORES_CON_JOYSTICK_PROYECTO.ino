//MOTOR A 
int enA = 9;
int in1 = 8;
int in2 = 7;

//MOTOR B
int enB = 3;
int in3 = 4;
int in4 = 5;

//JOYSTICK
int joyVert = A0; //VERTICAL
int joyHorz = A1; //HORIZONTAL

//VALORES INICIALES DEL MOTOR
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;

//VALORES DEL JOYSTICK (512 ES LA POSICION MEDIA)
int joyposVert = 512;
int joyposHorz = 512;

void setup() {
  // TODOS LOS PINES CONTROLADORES COMO SALIDA
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Iniciar con los motores desactivados y posicion hacia adelante
  
  //MOTOR A
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  //MOTOR B
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

void loop() {
  // POSICIONES X & Y DEL JOYSTICK
  joyposVert = analogRead(joyVert);
  joyposHorz = analogRead(joyHorz);

  //DETERMINAR SI SE TRATA DE UN MOVIMIENTO HACIA ATRAS O ADELANTE
  //HACERLO LEYENDO SU VALOR VERTICAL
  //APLICAR LOS RESULTADOS DEL MOTOR Y DIRECCION

  if (joyposVert < 460)
  {
    //HACIA ATRAS(MOTOR A HACIA ATRAS)
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //DETERMINAR VELOCIDAD DEL MOTOR A
    //A medida que retrocedemos, necesitamos revertir las lecturas

    joyposVert = joyposVert - 460; //ESTO PRODUCE UN NUMERO NEGATIVO
    joyposVert = joyposVert * -1; //HACE QUE EL NUMERO SEA POSITIVO

    MotorSpeed1 = map(joyposVert, 0, 460, 0, 255);
    
  }
  else if (joyposVert > 564)
  {
    //Adelante(MOTOR A HACIA ADELANTE)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //DETERMINAR LA VELOCIDAD DEL MOTOR A
    
    MotorSpeed1 = map(joyposVert, 564, 1023, 0, 255);
  }
  else
  {
    //MANTENER PARADOS LOS MOTORES
    MotorSpeed1 = 0;
    MotorSpeed2 = 0;
  }
  //AHORA DETERMINAMOS SI SE TRATA DE UN MOVIMIENTO HACIA LA DERECHA O IZQUIERDA
  //HACERLO LEYENDO SU VALOR HORIZONTAL
  //APLICAR LOS VALORES DEL MOTOR Y DIRECCIÓN

   if (joyposHorz < 460)
   {
    //MOVER A LA IZQUIERDA(MOTOR B A LA IZQUIERDA)
    //A MEDIDA QUE MOVEMOS A LA IZQUIERDA, NECESITAMOS REVERTIR LOS VALORES
    
    joyposHorz = joyposHorz - 460; //ESTO PRODUCE UN NUMERO NEGATIVO
    joyposHorz = joyposHorz * -1; //HACE QUE EL NUMERO SEA POSITIVO
    
    //DETERMINAR LA VEOCIDAD DEL MOTOR B

    //MAPEAR EL NUMERO A UN VALOR MAXIMO DE 255
    joyposHorz = map(joyposHorz, 0, 460, 0, 255);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
   }
   else if (joyposHorz > 564)
  {
    //DERECHA(MOTOR B HACIA LA DERECHA)
     //DETERMINAR LA VELOCIDAD DEL MOTOR B

    joyposHorz = map(joyposHorz, 564, 1023, 0, 255);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else
  {
    //MANTENER PARADOS LOS MOTORES
    MotorSpeed1 = 0;
    MotorSpeed2 = 0;
  }
  //Ajustar para prevenir "zumbidos" a muy baja velocidad
  if (MotorSpeed1 < 40)MotorSpeed1 = 0;
  if (MotorSpeed2 < 40)MotorSpeed2 = 0;

  //Establecer la velocidad de los motores
  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
  }
