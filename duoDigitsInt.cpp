#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef uint64_t bls_t;

bool isDuoDigital(bls_t n)
{
    bls_t d1 = n % 10;
    bls_t d2;
    bls_t d;
    bool d2IsValid = false;

    n /= 10;
    while (n != 0)
    {
        d = n % 10;
        if (d != d1)
        {
            if (!d2IsValid)
            {
                d2 = d;
                d2IsValid = true;
            }
            else if (d != d2)
            {
                return false;
            }
        }
        n /= 10;
    }
    return true;
}
bls_t d(bls_t n)
{
    bls_t m = n;
    uint32_t iterations = 0;
    uint32_t iterationsDivMillion = 0;

    while (!isDuoDigital(m))
    {
        ++iterations;
        m += n;
        if (iterations >= 10000000)
        {
            iterations = 0;
            iterationsDivMillion += 10;
            cout << "d(" << n << ") " << iterationsDivMillion << "million iterations\n";
        }
    }
    return m;
}

bls_t bigD(bls_t k)
{
    bls_t s = 0;

    for(bls_t n = 1; n <= k; ++n)
    {
        s += d(n);
    }
    return s;
}
int main(int argc, char *argv[])
{
    bls_t k = 500;

    #if 0
    bls_t v = 100;

    cout << "Getting d(" << v << ")\n";
    bls_t x1 = d(v);
    cout << "d(" << v << ") = " << x1 << "\n";
    #endif // 0

    if (argc > 1)
    {
        k = (bls_t)strtoul(argv[1], NULL, 0);
    }

    cout << "Computing BigD(" << k << ")\n";

    bls_t s = bigD(k);

    cout << "BigD(" << k << ") = " << s << "\n";

    return 0;
}
