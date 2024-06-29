#include <iostream>
using namespace std;

double Add(double x, double y)
{
	return x + y;
}
double Sub(double x, double y)
{
	return x - y;
}
double Mul(double x, double y)
{
	return x * y;
}
double Div(double x, double y)
{
	return x / y;
}

int main()
{
	double x, y, result;
    int input;
	char op;

    do
    {

        cout << endl << "Enter first number : ";
        cin >> x;

        cout << "Enter second number : ";
        cin >> y;

        cout << "Enter the operation ( + , - , * , / ) : ";
        cin >> op;

        switch (op)
        {
        case '+':
            result = Add(x, y);
            cout << "Result: " << x << "+" << y << " = " << result << endl << endl << endl;
            cout << "============================================================================" << endl << endl;
            break;
        case '-':
            result = Sub(x, y);
            cout << "Result: " << x << "-" << y << " = " << result << endl << endl << endl;
            cout << "============================================================================" << endl << endl;
            break;
        case '*':
            result = Mul(x, y);
            cout << "Result: " << x << "*" << y << " = " << result << endl << endl << endl;
            cout << "============================================================================" << endl << endl;
            break;
        case '/':
            if (y != 0)
            {
                result = Div(x, y);
                cout << "Result: " << x << "/" << y << " = " << result << endl << endl << endl;
                cout << "============================================================================" << endl << endl;
            }
            else
            {
                cout << "Error ! Can't Divide by zero." << endl << endl << endl;
                cout << "============================================================================" << endl << endl;
            }
            break;
        default:
            cout << "Invalid operation." << endl << endl << endl;
            cout << "============================================================================" << endl << endl;
            break;
        }

        cout << "1- Perform another operation" << endl << "2- Exit" << endl ;
        cout << "Choose 1 or 2 : ";
        cin >> input;
        


    } while (input != 2);
}
