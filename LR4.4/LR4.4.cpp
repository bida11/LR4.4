// Біда О. М., ІК-12. ЛР 4.4, варіант 1. Функція за графіком.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    double R, xp, xk, dx;
    cout << "R, xp, xk, dx: ";
    if (!(cin >> R >> xp >> xk >> dx) || !isfinite(R)
        || !isfinite(xp) || !isfinite(xk) || !isfinite(dx)
        || R <= 0 || R >= 6 || dx <= 0 || xp > xk
        || (xk - xp) / dx > 1000000) {
        cerr << "Require 0 < R < 6 and valid grid\n";
        return 1;
    }
    const int m = int(floor((xk - xp) / dx + 1e-10));
    cout << "TABLE graph y(x)\n" << setw(12) << "x"
        << setw(16) << "y" << '\n';
    cout << fixed << setprecision(6);
    for (int j = 0; j <= m; ++j) {
        const double x = xp + j * dx;
        double y;
        if (x <= -6 - R) y = 0;
        else if (x <= -6)
            y = -sqrt(max(0.0, R * R - (x + 6) * (x + 6)));
        else if (x <= -R) y = R * (x + R) / (6 - R);
        else if (x <= 0) y = sqrt(max(0.0, R * R - x * x));
        else if (x <= 3) y = R * (1 - x / 3);
        else y = R * (x - 3) / 6;
        cout << setw(12) << x << setw(16) << y << '\n';
    }
}
