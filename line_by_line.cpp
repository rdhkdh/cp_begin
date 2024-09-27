#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("line_by_line_input.txt","r",stdin);
    freopen("line_by_line_output.txt","w",stdout);

    int t;
    cin>>t;
    int og=t;

    double p,n;

    while(t--)
    {
        cin>>n>>p;
        double result = p * (pow(100.0 / p, 1.0 / n) - 1);

        cout << fixed << setprecision(6);
        cout << "Case #" << og-t << ": " << result << endl;
    }
}