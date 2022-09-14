#include <iostream>
#include <cmath>

using namespace std;

double f1(double x)
{
    return -x * x * x + 10 * x + 5;
}

double fp1(double x)
{
    return -3 * x * x + 10;
}

double f2(double x)
{
    return x * x * x * (x + sin(x * x - 1) - 1) - 1;
}

double fp2(double x)
{
    return x * x * (2 * x * x * cos(x * x - 1) + 3 * sin(x * x - 1) + 4 * x - 3);
}

double f3(double x)
{
    return 3 * x * x * x + 5 * x * x + 1;
}

double fp3(double x)
{
    return 9 * x * x + 10 * x;
}

int main()
{

    double x0;
    double x1;//dla siecznych
    double x[7];
    double y[7];
    double X[8];
    double Y[8];
    cout << "Podaj x0:" << endl;
    cin >> x0;
    x1 = x0 - 0.1;


    cout << "Funkcja 1 - metoda stycznych dla przedzialu [2, 6]" << endl << "f(x) = -x^3 + 10x + 5" << endl;

    x[0] = x0;
    y[0] = f1(x[0]);
    cout << "x0" << " = " << x[0] << endl << "y0" << " = " << y[0] << endl << endl;

    for (int i = 0; i <= 5; i++)
    {
        x[i + 1] = x[i] - (f1(x[i]) / fp1(x[i]));
        if (x[i + 1] < 2 || x[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            y[i + 1] = f1(x[i + 1]);
            cout << "x" << i + 1 << " = " << x[i + 1] << endl << "y" << i + 1 << " = " << y[i + 1] << endl << endl;
        }
    }
    
    cout << "-----------------------------------------------" << endl << endl;

    cout << "Funkcja 2 - metoda stycznych dla przedzialu [2, 6]" << endl << "f(x) = x^3*(x+sin(x^2-1)-1)-1" << endl;

    x[0] = x0;
    y[0] = f2(x[0]);
    cout << "x0" << " = " << x[0] << endl << "y0" << " = " << y[0] << endl << endl;

    for (int i = 0; i <= 5; i++)
    {
        x[i + 1] = x[i] - (f2(x[i]) / fp2(x[i]));
        if (x[i + 1] < 2 || x[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            y[i + 1] = f2(x[i + 1]);
            cout << "x" << i + 1 << " = " << x[i + 1] << endl << "y" << i + 1 << " = " << y[i + 1] << endl << endl;
        }
    }

    cout << "-----------------------------------------------" << endl << endl;

    cout << "Funkcja 3 - metoda stycznych dla przedzialu [0, 6]" << endl << "f(x) = 3x^3 + 5x + 1" << endl;

    x[0] = x0;
    y[0] = f3(x[0]);
    cout << "x0" << " = " << x[0] << endl << "y0" << " = " << y[0] << endl << endl;

    for (int i = 0; i <= 5; i++)
    {
        x[i + 1] = x[i] - (f3(x[i]) / fp3(x[i]));
        if (x[i + 1] < 0 || x[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            y[i + 1] = f3(x[i + 1]);
            cout << "x" << i + 1 << " = " << x[i + 1] << endl << "y" << i + 1 << " = " << y[i + 1] << endl << endl;
        }
    }

    cout << "-----------------------------------------------" << endl << endl;

    cout << "Funkcja 1 - metoda siecznych dla przedzialu [2, 6]" << endl << "f(x) = -x^3 + 10x + 5" << endl;
    
    X[0] = x0;
    X[1] = x1;
    Y[0] = f1(X[0]);
    Y[1] = f1(X[1]);
    cout << "x0" << " = " << X[0] << endl << "y0" << " = " << Y[0] << endl << endl;
    cout << "x1" << " = " << X[1] << endl << "y1" << " = " << Y[1] << endl << endl;

    for (int i = 1; i <= 6; i++)
    {
        X[i + 1] = X[i] - (f1(X[i])*(X[i]-X[i-1])/(f1(X[i])-f1(X[i-1])));
        if (X[i + 1] < 2 || X[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            Y[i + 1] = f1(X[i + 1]);
            cout << "x" << i + 1 << " = " << X[i + 1] << endl << "y" << i + 1 << " = " << Y[i + 1] << endl << endl;
        }
    }

    cout << "-----------------------------------------------" << endl << endl;

    cout << "Funkcja 2 - metoda siecznych dla przedzialu [2, 6]" << endl << "f(x) = x^3*(x+sin(x^2-1)-1)-1" << endl;

    X[0] = x0;
    X[1] = x1;
    Y[0] = f2(X[0]);
    Y[1] = f2(X[1]);
    cout << "x0" << " = " << X[0] << endl << "y0" << " = " << Y[0] << endl << endl;
    cout << "x1" << " = " << X[1] << endl << "y1" << " = " << Y[1] << endl << endl;

    for (int i = 1; i <= 6; i++)
    {
        X[i + 1] = X[i] - (f2(X[i]) * (X[i] - X[i - 1]) / (f2(X[i]) - f2(X[i - 1])));
        if (X[i + 1] < 2 || X[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            Y[i + 1] = f2(X[i + 1]);
            cout << "x" << i + 1 << " = " << X[i + 1] << endl << "y" << i + 1 << " = " << Y[i + 1] << endl << endl;
        }
    }

    cout << "-----------------------------------------------" << endl << endl;

    cout << "Funkcja 3 - metoda siecznych dla przedzialu [0, 6]" << endl << "f(x) = 3x^3 + 5x + 1" << endl;

    X[0] = x0;
    X[1] = x1;
    Y[0] = f3(X[0]);
    Y[1] = f3(X[1]);
    cout << "x0" << " = " << X[0] << endl << "y0" << " = " << Y[0] << endl << endl;
    cout << "x1" << " = " << X[1] << endl << "y1" << " = " << Y[1] << endl << endl;

    for (int i = 1; i <= 6; i++)
    {
        X[i + 1] = X[i] - (f3(X[i]) * (X[i] - X[i - 1]) / (f3(X[i]) - f3(X[i - 1])));
        if (X[i + 1] < 0 || X[i + 1] > 6)
        {
            cout << "wyszlismy poza przedzial" << endl << endl;
        }
        else
        {
            Y[i + 1] = f3(X[i + 1]);
            cout << "x" << i + 1 << " = " << X[i + 1] << endl << "y" << i + 1 << " = " << Y[i + 1] << endl << endl;
        }
    }

    cout << "-----------------------------------------------" << endl << endl;

    return 0;
}