/*
 * EEPROM_Program.c
 *
 *  Created on: Nov 1, 2024
 *      Author: amany_Elseadwy
 *
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include"STD_TYPE.h"
#include"BIT_MAC_FUC.h"
#include"TWI_Interface.h"
#include"EEPORM_Interface.h"
#include"EEPROM_Private.h"
#include"EEPROM_Config.h"

void EEPROM_voidWriteData(u8 Copy_u8Adress , u8 Copy_u8Data){

MTWI_voidSendStartCondition();
MTWI_voidSendSlaveAddWriteOper(CHIP_ADDRESS);
MTWI_voidMasterSendDataWithACK(Copy_u8Adress);
MTWI_voidMasterSendDataWithACK(Copy_u8Data);
MTWI_voidSendStopCondition();
_delay_ms(10);

}

u8 EEPROM_voidReadData(u8 Copy_u8Adress )
{

u8 Local_u8Data;
	MTWI_voidSendStartCondition();
	MTWI_voidSendSlaveAddWriteOper(CHIP_ADDRESS);
	MTWI_voidMasterSendDataWithACK(Copy_u8Adress);
    MTWI_voidSendRepeatedStartCondition();
    MTWI_voidSendSlaveAddReadOper(CHIP_ADDRESS);
Local_u8Data=MTWI_voidMasterRecieveDataWithNACK();

MTWI_voidSendStopCondition();
return Local_u8Data;

}
