#include "MPU_REGISTERS.h"                 
void mpu_write(int add, int data){
   i2c_start();
   i2c_write(w_Add);
   i2c_write(add);
   i2c_write(data);
   i2c_stop();
}
void mpu_init(){
   mpu_write(PWR_MGMT_1, 0x80);//reseteamos el dispositivo, registro 107
   delay_ms(100);
   mpu_write(PWR_MGMT_1, 0x00);//Internal 8MHz oscillator is selected as source
   delay_ms(100);
   mpu_write(CONFIG, 0x01);//Frame Synchro=input disable, Digital Low Pass Filter = [Accel(184Hz, 2ms), Gyro(188Hz, 1.9ms)]
   delay_ms(10);
   mpu_write(GYRO_CONFIG, 0x00);//+/- 250°/s
}
int16 mpu_read(int add){
   int val;
   i2c_start();
   i2c_write(w_Add);
   i2c_write(add);//register that we want to read
   i2c_start();
   i2c_write(r_Add);
   val = i2c_read(0);//with NACK
   i2c_stop();
   return val;
}
//Note that we have to make the division because the 
//gravitational accel is 1g--> 16384
//la escala del acelerómetro está configurada a 2g y la aceleración se da en una variable con signo de 16 bits (-32768 a +32768), 
//además, la aceleración gravitacional es +1g, por lo que el sensor estará midiendo cerca de 16384 sobre el eje z cuando se encuentra en reposo.
float mpu_get_Acc_x(){
   signed int16 val;//we are going to obtain values from -32768 to +32768 
   float Acc_x;
   val = mpu_read(ACCEL_XOUT_H);
   val = (val << 8) + mpu_read(ACCEL_XOUT_L);  
   Acc_x = (float)val/(float)16384; 
   return Acc_x;
}
float mpu_get_Acc_y(){
   signed int16 val;
   float Acc_y;
   val = mpu_read(ACCEL_YOUT_H);
   val = (val << 8) + mpu_read(ACCEL_YOUT_L);  
   Acc_y = (float)val/(float)16384; 
   return Acc_y;
}
float mpu_get_Acc_z(){
   signed int16 val;
   float Acc_z;
   val = mpu_read(ACCEL_ZOUT_H);
   val = (val << 8) + mpu_read(ACCEL_ZOUT_L);  
   Acc_z = (float)val/(float)16384; 
   return Acc_z;
}
float mpu_get_Gyr_x(){
   signed int16 val;
   float Gyr_x;
   val = mpu_read(GYRO_XOUT_H);
   val = (val << 8) + mpu_read(GYRO_XOUT_L);  
   Gyr_x = (float)val/(float)131;//the LSB Sensitivity is 131 LSB/°/s 
   return Gyr_x;
}
float mpu_get_Gyr_y(){
   signed int16 val;
   float Gyr_y;
   val = mpu_read(GYRO_YOUT_H);
   val = (val << 8) + mpu_read(GYRO_YOUT_L);  
   Gyr_y = (float)val/(float)131;//the LSB Sensitivity is 131 LSB/°/s 
   return Gyr_y;
}
float mpu_get_Gyr_z(){
   signed int16 val;
   float Gyr_z;
   val = mpu_read(GYRO_ZOUT_H);
   val = (val << 8) + mpu_read(GYRO_ZOUT_L);  
   Gyr_z = (float)val/(float)131;//the LSB Sensitivity is 131 LSB/°/s 
   return Gyr_z;
}
//Temp in °C = ((TEMP_OUT as signed quantity)/340) + 36.53
float mpu_get_T(){
   signed int16 val;
   float Temp;
   val = mpu_read(TEMP_OUT_H);
   val = (val<<8) + mpu_read(TEMP_OUT_L);
   Temp = ((float)val/(float)340) + (float)36.53;
   return Temp;
}
