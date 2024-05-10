#include<bits/stdc++.h>
using namespace std;

long long countStrings(string S)
{
    long long N = S.size();
 
    
}

int main()
{
    string S;
    cin>>S;
    int N= S.length();

    // mp[] to store the frequency of each character
    int mp[26] = { 0 };
 
    // For storing frequencies
    for (auto i : S) {  mp[i-'a']++; }

    long long ans = 0;
    for (auto i : S) {
        ans += N - mp[i-'a'];
    }
    ans /= 2;
 
    for (int i = 0; i < 26; i++)  //because swapping 2 same characters gives the original string again
    { //hence it can be counted in this case
        if (mp[i] >= 2) {
            ans++;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}