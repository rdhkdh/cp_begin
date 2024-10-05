#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1e7+1, true);

void sieveOfEratosthenes(int N)
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

}

int countNSubtractorizations(int N)
{
    if(N<=4) {return 0;}

    int count=0;
    for(int i=3;i<=N-2;i++)
    {
        if(isPrime[i] && isPrime[i+2])
        {
            count++;
        }
    }

    if(N>=5) {count++;} //for 2

    return count;
}

int main()
{
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("prime_subtractorization_output.txt", "w", stdout);

    int t, n;
    cin >> t;
    int og = t;

    sieveOfEratosthenes(1e7+1);

    while (t--)
    {
        cin >> n;

        cout << "Case #" << og - t << ": " << countNSubtractorizations(n) << endl;
    }
}
