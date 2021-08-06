#include <Wire.h>
//SDA=A4, SCL=A5
const int MPU2 = 0x69, MPU1 = 0x68;
int16_t Acx_1, Acy_1, Acz_1, Gx_1, Gy_1, Gz_1, T_1;
int16_t Acx_2, Acy_2, Acz_2, Gx_2, Gy_2, Gz_2, T_2;
int IR_1 = 2;
int IR_2 = 4;
int IR_3 = 7;
int IR_4 = 8;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);//pwr_mgmt_1 register
  Wire.write(0);//waking up the mpu
  Wire.endTransmission(true);
  Wire.begin();
  Wire.beginTransmission(MPU2);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  pinMode(IR_1, INPUT);
  pinMode(IR_2,INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(0);
  //Finger movement detection
  IR_Status(IR_1);
  IR_Status(IR_2);
  IR_Status(IR_3);
  IR_Status(IR_4);
  //get values
  //GetValues1(MPU1);
  //Serial.print(" ");
  //Serial.print("|||");

  //GetValues2(MPU2);
  //Serial.print("\n");
  delay(30);
}

void IR_Status(int IR_DIR){
  int stat = digitalRead(IR_DIR);
  if (stat == 0){
    Serial.flush();
    Serial.println(IR_DIR);
    }
}

void GetValues1(const int MPU) {
  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);//Accel_xout_h register
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true); //14 registers to request from mpu
  //reading raw data
  Acx_1 = Wire.read() << 8 | Wire.read(); //High and Low
  Acy_1 = Wire.read() << 8 | Wire.read();
  Acz_1 = Wire.read() << 8 | Wire.read();
  Gx_1 = Wire.read() << 8 | Wire.read();
  Gy_1 = Wire.read() << 8 | Wire.read();
  Gz_1 = Wire.read() << 8 | Wire.read();
  //converting data
  float Ax1 = (float)Acx_1/(float)16384;
  float Ay1 = (float)Acy_1/(float)16384;
  float Az1 = (float)Acz_1/(float)16384;
  float Gx1 = (float)Gx_1/(float)131;
  float Gy1 = (float)Gy_1/(float)131;
  float Gz1 = (float)Gz_1/(float)131;


 
  Serial.print("AcX = ");
  Serial.print(Ax1);
  Serial.print("|AcY = ");
  Serial.print(Ay1);
  Serial.print("|AcZ = ");
  Serial.print(Az1);
  Serial.print("|Gx = ");
  Serial.print(Gx1);
  Serial.print("|Gy = ");
  Serial.print(Gy1);
  Serial.print("|Gz = ");
  Serial.print(Gz1);
}
void GetValues2(const int MPU) {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);//Accel_xout_h register
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true); //14 registers to request from mpu
  //raw data
  Acx_2 = Wire.read() << 8 | Wire.read(); //High and Low
  Acy_2 = Wire.read() << 8 | Wire.read();
  Acz_2 = Wire.read() << 8 | Wire.read();
  Gx_2 = Wire.read() << 8 | Wire.read();
  Gy_2 = Wire.read() << 8 | Wire.read();
  Gz_2 = Wire.read() << 8 | Wire.read();
  //converting
  float Ax2 = (float)Acx_2/(float)16384;
  float Ay2 = (float)Acy_2/(float)16384;
  float Az2 = (float)Acz_2/(float)16384;
  float Gx2 = (float)Gx_2/(float)131;
  float Gy2 = (float)Gy_2/(float)131;
  float Gz2 = (float)Gz_2/(float)131;
  Serial.print("AcX = ");
  Serial.print(Ax2);
  Serial.print("|AcY = ");
  Serial.print(Ay2);
  Serial.print("|AcZ = ");
  Serial.print(Az2);
  Serial.print("|Gx = ");
  Serial.print(Gx2);
  Serial.print("|Gy = ");
  Serial.print(Gy2);
  Serial.print("|Gz = ");
  Serial.print(Gz2);
}
