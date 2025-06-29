/*
 * TWI_Interface.h
 *
 *  Created on: Nov 1, 2024
 *  Author:amany_Elsedawy
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void MTWI_void_InitMaster(void);

void MTWI_void_InitSlave(void);

void MTWI_voidSendStartCondition(void);

void MTWI_voidSendRepeatedStartCondition(void);

void MTWI_voidSendSlaveAddWriteOper(u8 Copy_u8SlaveAdd);

void MTWI_voidSendSlaveAddReadOper(u8 Copy_u8SlaveAdd);

void MTWI_voidMasterSendDataWithACK(u8 Copy_u8DataByte);
void MTWI_voidMasterSendDataWithNACK(u8 Copy_u8DataByte);

u8 MTWI_voidMasterRecieveDataWithACK(void);

u8 MTWI_voidMasterRecieveDataWithNACK(void);

void  MTWI_voidSendStopCondition(void);


#endif /* TWI_INTERFACE_H_ */
