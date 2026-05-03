#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long full = (1LL << n) - 1;

        printf("0\n");
        fflush(stdout);

        printf("I 0\n");
        fflush(stdout);
        long long sz;
        scanf("%lld", &sz);
        if (sz == -1)
            return 0;

        long long c = 0;
        int k;

        if (sz == 1)
        {
            // k = 1
            k = 1;
            printf("I %lld\n", full);
            fflush(stdout);
            scanf("%lld", &sz);
            if (sz == -1)
                return 0;

            for (int i = n - 1; i >= 0; i--)
            {
                long long test = c | (1LL << i);
                printf("Q %lld\n", test);
                fflush(stdout);
                long long r;
                scanf("%lld", &r);
                if (r == -1)
                    return 0;
                if (r >= 1)
                    c |= (1LL << i);
            }
            printf("A %d %lld\n", k, c);
            fflush(stdout);
        }
        else
        {

            for (int i = n - 1; i >= 0; i--)
            {
                long long test = c | (1LL << i);
                printf("Q %lld\n", test);
                fflush(stdout);
                long long r;
                scanf("%lld", &r);
                if (r == -1)
                    return 0;
                if (r >= 1)
                    c |= (1LL << i);
            }
            
            
            int bits = __builtin_popcountll(c);
            if (bits >= 2)
            {
                long long v = c & (-c);
                printf("I %lld\n", v);
                fflush(stdout);
                scanf("%lld", &sz);
                if (sz == -1)
                    return 0;
                
                k = (sz == 2) ? 2 : 3;
            }
            else
            {
                
                long long b = (c == 1) ? 2 : 1;
                long long w = c | b; // w has 2 bits
                printf("I %lld\n", w);
                fflush(stdout);
                scanf("%lld", &sz);
                if (sz == -1)
                    return 0;
                
                printf("Q %lld\n", w);
                fflush(stdout);
                long long r;
                scanf("%lld", &r);
                if (r == -1)
                    return 0;
                
                k = (r >= 1) ? 2 : 3;
            }
            printf("A %d %lld\n", k, c);
            fflush(stdout);
        }
    }
    return 0;
}