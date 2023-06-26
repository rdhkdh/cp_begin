#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a = 1, b = 0;
    while(n > 0) {
    	for (int i = 2; i <= n; i+=2) {
    		cout<<a*i + b<<' ';
    	}
        /* (n & 1) = bitwise and => masks all 
        preceding bits and just indicates last bit, hence useful in telling whether n is odd/even */
    	if (n%2==1)
        { 
            //cout<<a + b<<' ', b += a;
            cout<<a + b<<' '; 
            b += a; 
        }
    	else {b = b-a;}
    	a = 2*a; // can be written as a<<=1
    	n = n/2; //can be written as n>>=1
    }
}