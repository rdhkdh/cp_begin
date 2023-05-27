#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {int x; cin>>x; A.push_back(x);}

    set<int> s[10005];
    
    for(int i=0;i<n;i++)
    {
        if(s[A[i]].size()==0) s[A[i]].insert(i);
        else if(s[A[i]].size()>=1)
        {
            s[A[i]].insert(i);
            int x = *s[A[i]].begin();
            A[x]++;
            s[A[i]+1].insert(x);
            s[A[i]].erase(s[A[i]].begin());
        }
    }
    
    for(int i=0;i<n;i++) {cout<<A[i]<<" ";}

}


// vector<int> Solution::solve(vector<int> &A) {
//     int n=A.size();
//     set<int> s[10005];
    
//     for(int i=0;i<n;i++)
//     {
//         if(s[A[i]].size()==0) s[A[i]].insert(i);
//         else if(s[A[i]].size()>=1)
//         {
//             s[A[i]].insert(i);
//             int x = *s[A[i]].begin();
//             A[x]++;
//             s[A[i]+1].insert(x);
//             s[A[i]].erase(s[A[i]].begin());
//         }
//     }
    
//     return A;
// }