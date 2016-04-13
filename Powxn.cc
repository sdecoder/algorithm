#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution_opt {
public:
    double power(double x, long n)
    {
        if (n == 0)
            return 1;
        double value = x;
        double result = 1;
        while (n > 0) {

            if (n & 0x1 != 0) {
                result *= value;
            }
            value = value * value;
            n = n >> 1;
        }
        return result;
    }

    double myPow(double x, int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long p = (long)n;
        if (p < 0)
            return 1.0 / power(x, -p);
        else
            return power(x, p);
    }
};

class Solution {
public:
    double power(double x, int n)
    {
        if (n == 0)
            return 1;

        double v = power(x, n / 2);

        if (n % 2 == 0)
            return v * v;
        else
            return v * v * x;
    }

    double pow(double x, int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
};

int main(int argc, char const* argv[])
{
    Solution_opt s;
    return 0;
}