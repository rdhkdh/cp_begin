#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        //original value= i for L, n-1-i for R
        //gain = (n-1-i)-i for L, i-(n-1-i) for R

        vector <int> gain; //to store gain
        int total=0; //total value of line

        for(int i=0;i<n;i++)
        {
            if (s[i] == 'L') {
			gain.push_back((n - 1 - i) - i);
			total += i;
		}
		else {
			gain.push_back(i - (n - 1 - i));
			total += n - 1 - i;
		}
        }
        //sort all the gains in desc order
        sort(gain.begin(),gain.end(), greater<int>()); 

        for(int k=0;k<n;k++)
        {
            if(gain[k]>0) {total+=gain[k];} //if gain is +ve, add to total value of line
            cout<<total<<" ";
        }
        cout<<endl;

    }
}