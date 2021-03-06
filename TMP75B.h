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

#ifndef      _TMP75B_H_	
#define      _TMP75B_H_	

	/*
	Check the model of your MCU model
	*/
	#ifndef     __STM32L4xx_HAL_I2C_H
	#define     __STM32L4xx_HAL_I2C_H
	#endif	

	#define     TMP75B_DeviceID1 0x48    //GND     GND     GND
	#define     TMP75B_DeviceID2 0x49    //GND     GND     VCC
	#define     TMP75B_DeviceID3 0x4A    //GND     VCC     GND
	#define     TMP75B_DeviceID4 0x4B    //GND     VCC     VCC
	#define     TMP75B_DeviceID5 0x4C    //VCC     GND     GND
	#define     TMP75B_DeviceID6 0x4D    //VCC     GND     VCC
	#define     TMP75B_DeviceID7 0x4E    //VCC     VCC     GND
	#define     TMP75B_DeviceID8 0x4F    //VCC     VCC     VCC
	
	/*
	Pointer Registers
	*/
	#define     TemperatureRegister     0x00
	#define     ConfigurationRegister   0x01
	#define     TemperatureLowLimit     0x02
	#define     TemperatureHighLimit    0x03
	
	/*  
	   @Brief         Read temperature basically
	   @Description   Function gives to us ambient temperature for 0.0625 resolution
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	   @Return value  Float
	 */
	float TMP75B_getTemperature(I2C_HandleTypeDef i2c);
	
	/*  
	   @Brief         Set Configuration of sensor
	   @Description   You can change speed, alert, interrupt...etc with this function
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	   @Return value  None
	 */
	void TMP75B_setConfiguration(I2C_HandleTypeDef i2c);
	
	/*  
	   @Brief         Read Content of Configuration
	   @Description   Read Content of Configuration
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	   @Return value  uint8_t
	 */
	uint8_t TMP75B_getConfiguration(I2C_HandleTypeDef i2c);
	
	/*  
	   @Brief         Set Low limit temperature
	   @Description   Set Low limit temperature for interrupt
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	                  uint8_t           ->  MSB
	                  uint8_t           ->  LSB
	   @Return value  None
	 */
	void TMP75B_setLowLimit(I2C_HandleTypeDef i2c,uint8_t MSB,uint8_t LSB);
	
	/*  
	   @Brief         Read Content of Low Lİmit Register
	   @Description   Get Low limit temperature for interrupt
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	   @Return value  uint16_t
	 */
	uint16_t TMP75B_getLowLimit(I2C_HandleTypeDef i2c);
	
	/*  
	   @Brief         Set High limit temperature
	   @Description   Set High limit temperature for interrupt
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	                  uint8_t           ->  MSB
	                  uint8_t           ->  LSB
	   @Return value  None
	 */
	void TMP75B_setHighLimit(I2C_HandleTypeDef i2c,uint8_t MSB,uint8_t LSB);
	
	/*  
	   @Brief         Get High limit temperature
	   @Description   Get Low limit temperature for interrupt
	   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
	                  uint8_t           ->  MSB
	                  uint8_t           ->  LSB
	   @Return value  None
	 */
	uint16_t TMP75B_getHighLimit(I2C_HandleTypeDef i2c);

#endif

