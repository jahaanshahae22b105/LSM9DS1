#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS1.h>

Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

void setup() {
  
  Serial.begin(9600);
  SPI.begin();
  
  if (!lsm.begin()) {
    Serial.println("Please Connect IMU");
    while (1);
  }
}

void loop() {
  
  /*Gets values from accelerometer, gyroscope and magnometer and stores them in the respective event variables */
  event aevent, gevent, mevent;
  lsm.readAccelerometer(aevent);
  lsm.readGyro(gevent);
  lsm.readMagnetometer(mevent);

  /*Prints values on Serial Output*/
  Serial.println("Acceleration :");
  Serial.print("X=");
  Serial.print(accel_event.acceleration.x);
  Serial.print(", Y=");
  Serial.print(accel_event.acceleration.y);
  Serial.print(", Z=");
  Serial.println(accel_event.acceleration.z);
  

  Serial.println("Gyroscope : ");
  Serial.print("X=");
  Serial.print(gyro_event.gyro.x);
  Serial.print(", Y=");
  Serial.print(gyro_event.gyro.y);
  Serial.print(", Z=");
  Serial.println(gyro_event.gyro.z);
  

  Serial.println("Magnetometer : ");
  Serial.print("X=");
  Serial.print(mag_event.magnetic.x);
  Serial.print(", Y=");
  Serial.print(mag_event.magnetic.y);
  Serial.print(", Z=");
  Serial.println(mag_event.magnetic.z);

  delay(100);
}
