// EdBDemo_C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "EdBApi.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

int main()
{
	int clientID = EdB_Login("116.228.149.86", 7708, "10.11", "280079160", "830406", "", "16");
	cout << "Login:  " << clientID << "\n";
	string queryData = EdB_QueryData("280079160", clientID, 2014);
	cout << "QueryData：" << queryData << "\n";
	string sendOrder = EdB_SendOrder(clientID, 15, "280079160", "70000", "70000", 1, 1.0);
	cout << "SendOrder" << sendOrder << "\n";
	string getPrice = EdB_GetPrice(clientID, "70000");
	cout << "GetPrice" << getPrice << "\n";
	string cancelOrder = EdB_CancelOrder(clientID, "280079160", queryData.c_str(), 1);
	cout << "CancelOrder" << cancelOrder << "\n";

	return 0;
}

