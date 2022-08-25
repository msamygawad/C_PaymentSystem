// #pragma once

#ifndef SERVER_H
#define SERVER_H

#include <stdint.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"

typedef struct 
{
	ST_cardData_t serverData;
	float bankMoney;
	uint8_t suspendedFlag;
    
}clientsDataBase_t;
/* 
clientsDataBase_t dataBaseArr[5] ={ {{"Abdelhai Mohamed Tahoon", "20522522545621556", "04/25"}, 80000, 0},
								   	{{"Abdelrahman Tarek Atia" , "20522522512354234", "04/25"}, 80000, 0},
									{{"Maged Ahmed Elgazzzar"  , "20522522545621444", "04/25"}, 90000, 0},
									{{"Mohamed Samy Abdelgawad", "20522522549999999", "04/25"}, 20000, 0},
									{{"Amr Ragab Eisa Ragab"   , "20577522546666666", "07/23"}, 84000, 0}
								  };

 */
typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;



typedef enum EN_serverError_t {
	SERV_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;

typedef struct ST_accountsDB_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(ST_transaction_t* transData);

#endif