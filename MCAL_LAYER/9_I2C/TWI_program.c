/*
 * TWI_program.c
 *
 *  Created on: Nov 1, 2024
 *      Author: amany_Elsedawy
 */

#include"STD_TYPE.h"
#include"BIT_MAC_FUC.h"
#include"TWI_Interface.h"
#include"TWI_Private.h"
#include"TWI_register.h"
#include"TWI_Config.h"

void MTWI_void_InitMaster(void){
if(SlAVE_ADDRESS==NO_ADDRESS){
   asm("NOP");

}else{
	 TWAR=SlAVE_ADDRESS<<1;


}
CLR_BIT(TWSR,1);
CLR_BIT(TWSR,0);
	//after calculation TWBR->12

TWBR=2;


}

void MTWI_void_InitSlave(void){
 TWAR=SlAVE_ADDRESS<<1;



}

void MTWI_voidSendStartCondition(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	 while (!(TWCR & (1<<TWINT))){

        asm("NOP");
	 }

}

void MTWI_voidSendRepeatedStartCondition(void){

}

void MTWI_voidSendSlaveAddWriteOper(u8 Copy_u8SlaveAdd){
	 TWDR = Copy_u8SlaveAdd<<1;
      CLR_BIT(TWDR,0);
	 TWCR = (1<<TWINT) | (1<<TWEN);
	 while (!(TWCR & (1<<TWINT))){

	        asm("NOP");
		 }


}

void MTWI_voidSendSlaveAddReadOper(u8 Copy_u8SlaveAdd){
	      TWDR = Copy_u8SlaveAdd<<1;
	      SET_BIT(TWDR,0);
		 TWCR = (1<<TWINT) | (1<<TWEN);
		 while (!(TWCR & (1<<TWINT))){

		        asm("NOP");
			 }


}

void MTWI_voidMasterSendDataWithACK(u8 Copy_u8DataByte){
	 TWDR = Copy_u8DataByte;
	 TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);

	 while (!(TWCR & (1<<TWINT))){

			        asm("NOP");
				 }


}
void MTWI_voidMasterSendDataWithNACK(u8 Copy_u8DataByte){
	TWDR = Copy_u8DataByte;
		 TWCR = (1<<TWINT) | (1<<TWEN) ;

		 while (!(TWCR & (1<<TWINT))){

				  asm("NOP");
			}


}

u8 MTWI_voidMasterRecieveDataWithACK(void){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT))){

		 asm("NOP");
	}

         return TWDR;


}

u8 MTWI_voidMasterRecieveDataWithNACK(void){
	TWCR = (1<<TWINT) | (1<<TWEN) ;
		while (!(TWCR & (1<<TWINT))){

			 asm("NOP");
	}

	         return TWDR;





}

void  MTWI_voidSendStopCondition(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}
