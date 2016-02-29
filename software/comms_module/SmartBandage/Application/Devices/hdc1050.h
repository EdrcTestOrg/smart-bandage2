/*
 * hdc1050.h
 *
 *  Created on: Feb 17, 2016
 *      Author: michaelblouin
 */

#ifndef APPLICATION_DEVICES_HDC1050_H_
#define APPLICATION_DEVICES_HDC1050_H_

#include "hci_tl.h"
#include "../Board.h"
#include <ti/sysbios/knl/Semaphore.h>

#define HDC1050_REG_TEMPERATURE		0x00
#define HDC1050_REG_HUMIDITY    	0x01
#define HDC1050_REG_CONFIGURATION	0x02
#define HDC1050_REG_SERIALID_LOW	0xFB
#define HDC1050_REG_SERIALID_MID	0xFC
#define HDC1050_REG_SERIALID_HIGH	0xFD
#define HDC1050_REG_MANUFACTURER_ID 0xFE
#define HDC1050_REG_DEVICE_ID		0xFF

#define HDC1050_REG_CONFIGURATION_RST  15
#define HDC1050_REG_CONFIGURATION_HEAT 13
#define HDC1050_REG_CONFIGURATION_MODE 12
#define HDC1050_REG_CONFIGURATION_BTST 11
#define HDC1050_REG_CONFIGURATION_TRES 10
#define HDC1050_REG_CONFIGURATION_HRES  8

#define HDC1050_REG_CONFIGURATION_HEAT_EN   1
#define HDC1050_REG_CONFIGURATION_HEAT_DSBL 0

#define HDC1050_REG_CONFIGURATION_MODE_TEMP_OR_HUM 0
#define HDC1050_REG_CONFIGURATION_MODE_SEQUENTIAL  1

#define HDC1050_REG_CONFIGURATION_BTST_BHI 0
#define HDC1050_REG_CONFIGURATION_BTST_BLO 1

#define HDC1050_REG_CONFIGURATION_TRES_14BIT 0
#define HDC1050_REG_CONFIGURATION_TRES_11BIT 1

#define HDC1050_REG_CONFIGURATION_HRES_14BIT 0
#define HDC1050_REG_CONFIGURATION_HRES_11BIT 1
#define HDC1050_REG_CONFIGURATION_HRES_8BIT  2

#define HDC1050_CONV_TIME_HRES_14BIT 6.5
#define HDC1050_CONV_TIME_HRES_11BIT 3.85
#define HDC1050_CONV_TIME_HRES_8BIT  2.5
#define HDC1050_CONV_TIME_TRES_14BIT 6.35
#define HDC1050_CONV_TIME_TRES_11BIT 3.65

#define HDC1050_MANUFACTURER_ID 0x5449
#define HDC1050_DEVICE_ID       0x1050

#define HDC1050_I2C_ADDRESS 0b1000000

typedef struct {
	uint16_t temperature;
	uint16_t humidity;
	uint16_t configuration;
	uint8_t  address;
	uint32_t readReadyTime;
} HDC1050_DEVICE;

SB_Error hdc1050_startTempHumidityConversion(HDC1050_DEVICE *device, Semaphore_Handle *semaphore);
SB_Error hdc1050_readTempHumidity(HDC1050_DEVICE *device, Semaphore_Handle *semaphore);

#endif /* APPLICATION_DEVICES_HDC1050_H_ */