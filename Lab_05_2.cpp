// Lab_05_2.cpp 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double S);
double A(const double x, const int n, double R);

int main()
{
    double xp, xk, x, dx, eps, a = 0, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
        << setw(10) << "atanh(1/x)" << "   |"
        << setw(7) << "S" << "      |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {

        s = S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << atanh(1 / x) << "   |"
            << setw(10) << setprecision(5) << s << "   |"
            << setw(5) << n << "   |"
            << endl;

        x += dx;
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s) {
    n = 0;
    s = 0;

    double R = 1.0 / (x);
    s = R;
    do {
        n++;
        //R *= (2.0 * n - 1) / ((2.0 * n + 1) * x * x);

        R = A(x, n, R);
        s += R;
    } while (fabs(R) >= eps);
    return s;
}

double A(const double x, const int n, double R)
{
    R *= (2.0 * n - 1) / ((2.0 * n + 1) * x * x);
    return R;
}
// test change
