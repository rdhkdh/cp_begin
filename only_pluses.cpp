#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin>>t;

    int a,b,c;
    while(t--)
    {
        cin>>a>>b>>c;

        int arr[3] = {a,b,c};
        
        int count=0;
        while(count<5)
        {
            // sort(arr,arr+3);
            // while(arr[0]<=arr[1] && count<5)
            // {
            //     arr[0]++;
            //     count++;
            // }

            if(arr[0]<=arr[1] && arr[0]<=arr[2]) {arr[0]++;}
            else if(arr[1] <= arr[0] && arr[1] <= arr[2]) {arr[1]++;}
            else { arr[2]++; }
            count++;
        }
        

        cout<<arr[0]*arr[1]*arr[2]<<endl;
        
    }
}