#include<iostream>
using namespace std;
int main()
{
	char op;
	double num1;
	double num2;
	double result;
	cout << "enter either(+-*/) : ";
	cin >> op;
	cout << "enter 1st number: ";
	cin >> num1;
	cout << "enter 2nd number: ";
	cin >> num2;
	switch (op)
	{
	case '+':
		result = num1 + num2;
		cout << "result: " << result;
		break;
	case '-':
		result = num1 - num2;
		cout << "result: " << result;
		break;
	case '*':
		result = num1 * num2;
		cout << "result: " << result;
		break;
	case '/':
		result = num1 / num2;
		cout << "result: " << result;
		break;

	}


}