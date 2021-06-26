#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bool isDuoDigital(uint32_t n)
{
    uint32_t d1 = n % 10;
    uint32_t d2;
    uint32_t d;
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
uint32_t d(uint32_t n)
{
    uint32_t m = n;
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
            printf("d(%d) %d million iterations\n", n, iterationsDivMillion);
        }
    }
    return m;
}

uint32_t bigD(uint32_t k)
{
    uint32_t s = 0;

    for(uint32_t n = 1; n <= k; ++n)
    {
        s += d(n);
    }
    return s;
}
int main(int argc, char *argv[])
{
    uint32_t k = 500;

    #if 0
    uint32_t v = 100;

    printf("Getting d(%d)\n", v);
    uint32_t x1 = d(v);
    printf("d(%d) = %d\n", v, x1);

    #endif // 0

    if (argc > 1)
    {
        k = (uint32_t)strtoul(argv[1], NULL, 0);
    }

    printf("Computing BigD(%d)\n", k);

    uint32_t s = bigD(k);

    printf("BigD(%d) = %d\n", k, s);

    return 0;
}
