/*
  @
  @   Date               :        29.08.2018 / Wednesday
  @
  @   Contact            :        Writing by Muhammet Rasit KIYAK                    @https://www.linkedin.com/in/mrstkyk/
  @                               mrstkyk@gmail.com 
  @
  @   Description        :        This Library for TMP75B Temperature Sensor on Texas Instruments
  @                               Dependency library is HAL for STM32 series (__STM32L4xx_HAL_I2C_H)
  @
*/

#include "TMP75B.h" 

uint8_t DeviceID=DeviceID1;


/*  
   @Brief         Read temperature basically
   @Description   Function gives to us ambient temperature for 0.0625 resolution
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  Float
 */
float TMP75B_getTemperature(I2C_HandleTypeDef i2c)
{
      static uint8_t buf[3];
      buf[0]=TemperatureRegister;
      
      HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,0,100);
      HAL_Delay(1);
      HAL_I2C_Master_Receive(&i2c,DeviceID<<1,buf,1,100);
      
      return ((((buf[0]<<8)|buf[1])>>4)*0.0625);
}

/*  
   @Brief         Set Configuration of sensor
   @Description   You can change speed, alert, interrupt...etc with this function
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  None
 */
void TMP75B_setConfiguration(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[3];
    
    buf[0]=ConfigurationRegister;
    buf[1]=0x00;//Default value, you can change all bits
    buf[2]=0xFF;//Reserved
    
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,2,100);
}

/*  
   @Brief         Read Content of Configuration
   @Description   Read Content of Configuration
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint8_t
 */
uint8_t TMP75B_getConfiguration(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];
    buf[0]=ConfigurationRegister;
    
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,0,100);
    HAL_Delay(1);
    HAL_I2C_Master_Receive(&i2c,DeviceID<<1,buf,1,100);
    
    return buf[1];
}

/*  
   @Brief         Set Low limit temperature
   @Description   Set Low limit temperature for interrupt
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t           ->  MSB
                  uint8_t           ->  LSB
   @Return value  None
 */
void TMP75B_setLowLimit(I2C_HandleTypeDef i2c,uint8_t MSB,uint8_t LSB)
{
    static uint8_t buf[3];
    
    buf[0]=TemperatureLowLimit;
    buf[1]=MSB;
    buf[2]=LSB<<4;
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,2,100);
}

/*  
   @Brief         Read Content of Low Lİmit Register
   @Description   Get Low limit temperature for interrupt
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP75B_getLowLimit(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];
    
    buf[0]=TemperatureLowLimit;
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,0,100);
    HAL_Delay(1);
    HAL_I2C_Master_Receive(&i2c,DeviceID<<1,buf,1,100);
    
    return ((buf[0]<<8)|(buf[1]<<4));
}

/*  
   @Brief         Set High limit temperature
   @Description   Set High limit temperature for interrupt
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t           ->  MSB
                  uint8_t           ->  LSB
   @Return value  None
 */
void TMP75B_setHighLimit(I2C_HandleTypeDef i2c,uint8_t MSB,uint8_t LSB)
{
    static uint8_t buf[3];
    
    buf[0]=TemperatureHighLimit;
    buf[1]=MSB;
    buf[2]=LSB<<4;
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,2,100);
}

/*  
   @Brief         Get High limit temperature
   @Description   Get Low limit temperature for interrupt
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t           ->  MSB
                  uint8_t           ->  LSB
   @Return value  None
 */
uint16_t TMP75B_getHighLimit(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];
    
    buf[0]=TemperatureHighLimit;
    HAL_I2C_Master_Transmit(&i2c,DeviceID<<1,buf,0,100);
    HAL_Delay(1);
    HAL_I2C_Master_Receive(&i2c,DeviceID<<1,buf,1,100);
    
    return ((buf[0]<<8)|(buf[1]<<4)); 
}
