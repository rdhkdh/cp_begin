#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarysearch(int arr[], int low, int high, int key)
{
	/*If the given element is the greatest then return the index of the last element. */
	if (arr[high] <= key)
		return high;
	/*If the given element is the smallest then return the index of the first element. */
	if (arr[low] > key)
		return low;
	/*Calculate the mid of the array. */
	int mid = low + (high - low) / 2;
	if (arr[mid] <= key && arr[mid + 1] > key)
		return mid;
	/*If the given element is larger than the mid element of the array then traverse the right subarray. */
	if (arr[mid] < key)
		return binarysearch(arr, mid + 1, high, key);
	/*Else traverse the left subarray. */
	return binarysearch(arr, low, mid - 1, key);
}

vector<int> printelements(int arr[], int n, int k, int key)
{
    vector<int> res;
	int left = binarysearch(arr, 0, n - 1, key);
	int right = left + 1;
	int count = 0;
	if (arr[left] == key)
		left--;
	/*Keep printing the elements closest to the given element. */
	while (count < k && left >= 0 && right < n)
	{
		if (key - arr[left] < arr[right] - key)
		{ res.push_back(arr[left]); left--; } 
		else
        { res.push_back(arr[right]); right++; }

		count++;
	}

	/*Keep printing the left out elements in left subarray. */
	while (count < k && left >= 0)
	{
		res.push_back(arr[left]); left--;
		count++;
	}

	/*Keep printing the left out elements in right subarray. */
	while (count < k && right < n)
	{
		res.push_back(arr[right]); right++;
		count++;
	}

    return res;
}

int32_t main()
{
    int n,q;
    cin>>n>>q;

    int a[n];
    int b[q];
    int k[q];

    for(int i=0;i<n;i++) {cin>>a[i];}
    for(int i=0;i<q;i++)
    {
        cin>>b[i]>>k[i];
    }

    sort(a,a+n);

    for(int i=0;i<q;i++)
    {
        vector<int> res = printelements(a,n,k[i],b[i]);
        if(binary_search(a,a+n,b[i]))
        {
            int y = res[k[i]-2];
            cout<<abs(b[i]-y)<<endl;
            continue;
        }

        int y = res[k[i]-1];
        cout<<abs(b[i]-y)<<endl;
    }

    
}