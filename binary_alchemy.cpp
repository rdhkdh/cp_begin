#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> A(n);

    for(int i=0;i<n;i++)
    {
        vector<int> v;
        int x;
        for(int j=0;j<i+1;j++)
        {
            cin>>x;
            v.push_back(x-1); //0-indexed
        }
        A[i] = v;
    }

    int elem = 0;
    for(int i=0;i<n;i++)
    {
        if(elem>i)
        {
            elem = A[elem][i];
        }
        else
        {
            elem = A[i][elem];
        }
    }

    cout<<elem+1<<endl;
}