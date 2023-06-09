#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int n; cin>>n;
    
    // int half_step=1,start=0;
    // while(n>0)
    // {
    //     for(int i=2;i<=n;i+=2)
    //     {
    //         cout<< start+ (half_step*i)<<" ";
    //     }
    //     if(n!=0) { cout<<half_step+start<<" "; start= start+ half_step;} 
    //     else {start = start - half_step;}
        
    //     n= n/2;
    //     half_step = 2* half_step;
    // }
    int n; cin>>n;
    int a = 1, b = 0;
    while(n > 0) {
    	for (int i = 2; i <= n; i+=2) {
    		cout<<a*i + b<<' ';
    	}
    	if (n&1) cout<<a + b<<' ', b += a;
    	else b -= a;
    	a <<= 1;
    	n >>= 1;
    }
}