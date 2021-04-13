#include <16f877a.h>
#fuses HS, NOWDT, NOPROTECT, NOPUT, NOLVP, NOBROWNOUT
#use delay(CLOCK=4000000)
#use I2C(master, sda=pin_c4, scl=pin_c3, SLOW)
#use RS232(BAUD=9600,BITS=8,PARITY=N,STOP=1,XMIT=PIN_C6,RCV=PIN_C7)

#use standard_io(D)
/*#define LCD_RS    PIN_D1
#define LCD_E     PIN_D0
#define LCD_D4    PIN_D4
#define LCD_D5    PIN_D5
#define LCD_D6    PIN_D6
#define LCD_D7    PIN_D7*/

#define IR_1 PIN_B7
#define IR_2 PIN_B6

//#include <lcd.c>
#include <string.h>
#include "MPU_FUNCTIONS.c"

void Finger_Detection();
void accel_and_gyro_detections();
float Acc_x, Acc_y, Acc_z ,Gyr_x, Gyr_y, Gyr_z;//data variables
void main(void){
   SET_TRIS_B(0XC0);//IR PINS LIKE INPUTS
   //lcd_init();
   mpu_init();
   while(1){
      Acc_x = mpu_get_Acc_x();
      Acc_y = mpu_get_Acc_y();
      Acc_z = mpu_get_Acc_z();
      Gyr_x = mpu_get_Gyr_x();
      Gyr_y = mpu_get_Gyr_y();
      Gyr_z = mpu_get_Gyr_z();

      Finger_Detection();
      accel_and_gyro_detections();
      //lcd_putc('\f');
      //lcd_gotoxy(1,1);
      //printf(lcd_putc, "A(%0.2f,%0.2f,%0.2f)", Acc_x, Acc_y, Acc_z);
      //printf(lcd_putc, "Ax: %0.8f", Acc_x);
      printf("\n\rAcceleracion");
      printf("\n\r\tX: %0.2f", Acc_x);
      printf("\n\r\tY: %0.2f", Acc_y);
      printf("\n\r\tZ: %0.2f", Acc_z);
      /*printf("\n\rAx: %0.8f", Acc_x);
      printf("\n\rAy: %0.8f", Acc_y);*/
      //lcd_gotoxy(1,2);
      //printf(lcd_putc, "G(%0.2f,%0.2f,%0.2f)", Gyr_x, Gyr_y, Gyr_z);
      //printf(lcd_putc, "Gx: %0.8f", Gyr_x);
      //printf("\n\rGyro: (%0.8f,%0.8f,%0.8f)", Gyr_x, Gyr_y, Gyr_z);
      printf("\n\rRotacion");
      printf("\n\r\tX: %0.2f", Gyr_x);
      printf("\n\r\tY: %0.2f", Gyr_y);
      printf("\n\r\tZ: %0.2f", Gyr_z);
      printf("\n\r");
      printf("\n\r");
      delay_ms(200);
   }

}
void Finger_Detection(){
   //lcd_putc('\f');
   if(input(IR_1) == 0){
      //lcd_gotoxy(1,1);
      //printf(lcd_putc, "ForefingerActive");
      printf("\n\rDedo indice activo");
      }
   if(input(IR_2) == 0){
      //lcd_gotoxy(1,2);
      //printf(lcd_putc, "MidfingerActive");
      printf("\n\rDedo medio activo");
      }
   delay_ms(500);
}
void accel_and_gyro_detections(){
      if(Acc_x >= 0.5){
         printf("\n\rAceleracion sobre el eje X");
      }
      if(Acc_x < -0.5){
         printf("\n\rDesaceleracion sobre el eje X");
      }
      if(Acc_y >= 0.5){
         printf("\n\rAceleracion sobre el eje Y");
      }
      if(Acc_y < -0.5){
         printf("\n\rDesaceleracion sobre el eje Y");
      }
      if(Acc_z >= 0.5){
         printf("\n\rAceleracion sobre el eje Z");
      }
      if(Acc_z < -0.5){
         printf("\n\rDesaceleracion sobre el eje Z");
      }
      
      if(Gyr_x >30){
         printf("\n\rGiro positivo sobre el eje X"); 
      }
      if(Gyr_x <-30){
         printf("\n\rGiro negativo sobre el eje X"); 
      }
      if(Gyr_y >30){
         printf("\n\rGiro positivo sobre el eje Y"); 
      }
      if(Gyr_y <-30){
         printf("\n\rGiro negativo sobre el eje Y"); 
      }
      if(Gyr_z >30){
         printf("\n\rGiro positivo sobre el eje Z"); 
      }
      if(Gyr_z <-30){
         printf("\n\rGiro negativo sobre el eje Z"); 
      }
}

