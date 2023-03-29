#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int uncalled=1;

    vector<int> called;
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        switch(t)
        {
            case 1:
                called.push_back(uncalled);
                uncalled++;
                break;
            case 2:
                int x;
                cin>>x;
                called.erase( find(called.begin(),called.end(),x) );
                break;
            case 3:
                cout<<*called.begin()<<"\n";
                //called.erase(min_element(called.begin(),called.end()));
                break;
        }
    }

}