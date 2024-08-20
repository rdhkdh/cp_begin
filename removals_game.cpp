#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        
        int a[n], b[n];
        for(int i=0;i<n;i++) { cin>>a[i]; }
        for(int i=0;i<n;i++) { cin>>b[i]; }


        int startA=0, endA=n-1;
        int startB=0, endB=n-1;
        set<int> deletedA, deletedB;

        while(startB != endB)
        {
            //A's turn
            if(a[startA]==b[startB] || a[startA]==b[endB])
            {
                deletedA.insert(a[startA]);
                startA++;
            }
            else if(a[endA]==b[startB] || a[endA]==b[endB])
            {
                deletedA.insert(a[endA]);
                endA--;
            }
            else // if none are equal
            {
                deletedA.insert(a[startA]);
                startA++;
            }

            //B's turn
            if(deletedA.find())
            {

            }
            else if()
            {

            }

            if(a[startA]==b[startB] || a[startA]==b[endB])
            {
                deletedA.insert(a[startA]);
                startA++;
            }
            else if(a[endA]==b[startB] || a[endA]==b[endB])
            {
                deletedA.insert(a[endA]);
                endA--;
            }
            else // if none are equal
            {
                deletedA.insert(a[startA]);
                startA++;
            }
        }   
    }
}