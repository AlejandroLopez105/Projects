/*
some registers that we will need
_H-->HIGH bits, _L--> LOW bits of an internal 
register value
There are 16-bits
*/
#define PWR_MGMT_1     0x6B//nos permite configurar el modo de energía y la fuente del reloj
#define CONFIG         0x1A//Configuraciones iniciales
#define GYRO_CONFIG    0x1B//rango de trabajo del giroscopio
#define ACCEL_CONFIG   0x1C//rango de trabajo del acelerómetro
#define ACCEL_XOUT_H   0x3B
#define ACCEL_XOUT_L   0x3C
#define ACCEL_YOUT_H   0x3D
#define ACCEL_YOUT_L   0x3E
#define ACCEL_ZOUT_H   0x3F
#define ACCEL_ZOUT_L   0x40
#define TEMP_OUT_H     0x41
#define TEMP_OUT_L     0x42
#define GYRO_XOUT_H    0x43
#define GYRO_XOUT_L    0x44
#define GYRO_YOUT_H    0x45
#define GYRO_YOUT_L    0x46
#define GYRO_ZOUT_H    0x47
#define GYRO_ZOUT_L    0x48
 

#define w_Add       0xD0
#define r_Add       0xD1
                             //the 7-bit address for MPU6050 is:0x68, but we 
                             //have to add 1 read/write bit    
                             
