#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{

		cout << "\nClient Card:\n\n";
		cout << "----------------------\n\n";
		cout << "Full Name     :" << Client.FullName();
		cout << "\nAcc. Number :" << Client.AccountNumber();
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n\n----------------------";
	}

	static string _ReadClientAccountNumber(string Message)
	{
		string AccountNumber;
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount? ";
		float Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

public:

	static void ShowTranferScreen()
	{
		clsScreen::_DrawScreenHeader("\tTransferScreen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadClientAccountNumber("\nPlease Enter Account Number To Transfer From: "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadClientAccountNumber("\nPlease Enter Account Number To Transfer To: "));
		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perfrom this operation? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer Done Succssefully\n";
			}
			else
			{
				cout << "\nTransfer Faild\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
		
	}
};
