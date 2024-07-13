#include<bits/stdc++.h> 
#define MAX 1000001
using namespace std; 

int numofAP(int a[], int n) 
{ 
	// initializing the minimum value and 
	// maximum value of the array. 
	int minarr = INT_MAX, maxarr = INT_MIN; 

	// Finding the minimum and maximum 
	// value of the array. 
	for (int i = 0; i < n; i++) 
	{ 
		minarr = min(minarr, a[i]); 
		maxarr = max(maxarr, a[i]); 
	} 

	// dp[i] is going to store count of APs ending 
	// with arr[i]. 
	// sum[j] is going to store sum of all dp[]'s 
	// with j as an AP element. 
	int dp[n], sum[MAX]; 

	// Initialize answer with n + 1 as single elements 
	// and empty array are also DP. 
	int ans = n + 1; 

	// Traversing with all common difference. 
	for (int d=(minarr-maxarr); d<=(maxarr-minarr); d++) 
	{ 
		memset(sum, 0, sizeof sum); 

		// Traversing all the element of the array. 
		for (int i = 0; i < n; i++) 
		{ 
			// Initialize dp[i] = 1. 
			dp[i] = 1; 

			// Adding counts of APs with given differences 
			// and a[i] is last element. 
			// We consider all APs where an array element 
			// is previous element of AP with a particular 
			// difference 
			if (a[i] - d >= 1 && a[i] - d <= 1000000) 
				dp[i] += sum[a[i] - d]; 

			ans += dp[i] - 1; 
			sum[a[i]] += dp[i]; 
		} 
	} 

	return ans-1; 
} 

// Driver code 
int main() 
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {cin>>a[i];}

	cout << numofAP(a, n) << endl; 
	return 0; 
} 
