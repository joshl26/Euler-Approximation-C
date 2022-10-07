#include <iostream>
#include <cmath>

double e = 2.71828182845904523536028747135266249775724709369995;

/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
#define f(x, y) 2 - pow(e, -4 * x) - 2 * y

#define f1(x) 1 + (0.5 * pow(e, -4 * x)) - (0.5 * pow(e, -2 * x))

using namespace std;

int main()
{
    float x01, x02, y01, y02, xn, h, yn1, yn2, slope1, slope2, ak;
    double err, error_tot;
    int i, n;

    x01 = x02 = 0;
    y01 = y02 = 1;
    xn = 1;
    n = 10;

    /*
    cout << "Enter Initial Condition" << endl;
    cout << "x01 = ";
    cin >> x01;
    cout << "y01 = ";
    cin >> y01;
    cout << "x02 = ";
    cin >> x02;
    cout << "y02 = ";
    cin >> y02;

    cout << "Enter calculation point xn = ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    */

    /* Calculating step size (h) */
    h = (xn - x01) / n;

    /* Euler's Method */

    /*cout << "\nx0\ty0\tslope\tyn\n";*/
    cout << "\nx\tY\tZ\tAk\n";
    cout << "------------------------------\n";

    for (i = 0; i < n + 1; i++)
    {
        slope1 = f(x01, y01);
        slope2 = f1(x02);
        yn1 = y01 + h * slope1;
        yn2 = y02 + h * slope2;

        ak = abs(y01 - slope2) / slope2;

        cout << x01 << "\t" << y01 << "\t" << slope2 << "\t" << ak << endl;
        y01 = yn1;
        y02 = yn2;
        x01 = x01 + h;
        x02 = x02 + h;

        err = err + ak;
    }

    /* Displaying result */
    cout << "\nValue of y at x = " << xn << " is " << yn1;

    error_tot = ((err) / (n + 1));

    cout << "\nValue of error is " << error_tot;

    return error_tot;
}
