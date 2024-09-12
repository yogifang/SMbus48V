#include <Arduino.h>
#include <Wire.h>

// #define I2C_TIMEOUT 0
// #define I2C_NOINTERRUPT 0
// #define I2C_FASTMODE 0
// #define FAC 1
// #define I2C_CPUFREQ (F_CPU/FAC)

// #define SDA_PORT PORTC
////#define SDA_PIN 21
// #define SCL_PORT PORTC
////#define SCL_PIN 22
// #include <SoftI2CMaster.h>
//// put function declarations here:
#define I2C_DEV_ADDR 0x0b

struct 
{
  byte byCmd;
  byte byLen;
}typedef devCmd;

const devCmd devCmdArray[] = { 
  {0x00, 2},{0x01, 2},{0x02, 2},{0x03, 2},{0x04, 2},{0x05, 2},{0x06, 2},{0x07, 2},
  {0x08, 2},{0x09, 2},{0x0a, 2},{0x0b, 2},{0x0c, 1},{0x0d, 1},{0x0e, 1},{0x0f, 2},
  {0x10, 2},{0x11, 2},{0x12, 2},{0x13, 2},{0x14, 2},{0x15, 2},{0x16, 2},{0x17, 2},
  {0x18, 2},{0x19, 2 },{0x1a, 2},{0x1b, 2},{0x1c, 2},
  {0x20, 12},{0x21, 8},{0x22, 5},{0x23, 15},
  {0x2b, 2},{0x2c, 2},{0x2d, 2},{0x2e, 2},{0x2f, 21},  
  {0x30, 2},{0x31, 2},{0x32, 2},{0x33, 2},{0x34, 2},{0x35, 2},{0x36, 2},{0x37, 2},
  {0x38, 2},{0x39, 2},{0x3a, 2},{0x3b, 2},{0x3c, 2},{0x3d, 2},{0x3e, 2},{0x3f, 2},
  {0x4c, 2},{0x4d, 2},{0x4e, 2},{0x4f, 1},
  {0x50, 5},{0x51, 5},{0x52, 3},{0x53, 5},{0x54, 5},{0x55, 3},{0x56, 3},{0x57, 3},
  {0x58, 3},{0x59, 11},{0x5a, 33},{0x5b, 14},
  {0x60, 33},{0x61, 33},{0x62, 15},{0x63, 33},{0x64, 33},{0x65, 33},{0x66, 33},
  {0x70, 33},{0x71, 33},{0x72, 33},
  {0x80, 33},{0x81, 33}
};



uint32_t i = 0;
byte data[16];
// oftWire Wire = SoftWire();

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Wire.begin();
  Wire.setClock(60000);
}



void loop()
{
  
  // Write message to the slave

  for (int i = 0; i < sizeof(devCmdArray) / 2; i++)
  {
    Wire.beginTransmission(I2C_DEV_ADDR);
    Wire.write(devCmdArray[i].byCmd);
    Wire.endTransmission();
    Serial.print("CmdS: 0x");
    Serial.print(devCmdArray[i].byCmd, HEX);

    delay(100);
    Wire.requestFrom(I2C_DEV_ADDR, devCmdArray[i].byLen); // request data size from slave
    delay(100);
  
    
   
        while (Wire.available())
        {
          Serial.print("  ");
          Serial.print(Wire.read(), HEX);
        }
       
  
      Serial.println();
    
  }
delay(10000);

/*-----------------------------------------------------------
  Wire.beginTransmission(I2C_DEV_ADDR);

      Wire.write(0x5b);
       Wire.endTransmission();

      Wire.requestFrom(I2C_DEV_ADDR, 3);
      while (Wire.available())
      {
        Serial.print("\t");
        Serial.print(Wire.read(),HEX);
      }
      Serial.println();
  */

  // Serial.printf("endTransmission: %u\n", error);

  // Read 16 bytes from the slave
  //  uint8_t bytesReceived = Wire.requestFrom(I2C_DEV_ADDR, 16);
  // Serial.printf("requestFrom: %u\n", bytesReceived);
  // if ((bool)bytesReceived)
  // { // If received more than zero bytes
  //   uint8_t temp[bytesReceived];
  //   Wire.readBytes(temp, bytesReceived);
  //  log_print_buf(temp, bytesReceived);
  // }
}
