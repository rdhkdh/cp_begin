#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dial = 50;
    string s;
    int count = 0;

    while(cin >> s)
    {
        char c = s[0];
        int val = stoi(s.substr(1));

        count += (val / 100); 

        val %= 100;

        if(c == 'L')
        {
            if(val > 0 && dial>0 && dial - val <= 0) count++;
            dial = ((dial - val) % 100 + 100) % 100;
        }
        else // R
        {
            if(val > 0 && dial>0 && dial + val >= 100) count++;
            dial = (dial + val) % 100;
        }
    }

    cout << count << endl;
}