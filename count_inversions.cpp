#include<bits/stdc++.h>
using namespace std;

void merge(int array[], int const left, int const mid, int const right, int &count)
{
    auto const p = mid - left + 1;
    auto const q = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[p],
         *rightArray = new int[q];
  
    // Copy data to temp arrays leftArray[] 
    // and rightArray[]
    for (auto i = 0; i < p; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < q; j++)
        rightArray[j] = array[mid + 1 + j];
  
    // Initial index of first sub-array
    // Initial index of second sub-array
    auto i_p = 0, 
         i_q = 0; 
  
    // Initial index of merged array
    int indexOfMergedArray = left; 
  
    // Merge the temp arrays back into 
    // array[left..right]
    while (i_p < p && 
           i_q < q) 
    {
        if (leftArray[i_p] <= 
            rightArray[i_q]) 
        {
            array[indexOfMergedArray] = leftArray[i_p];
            i_p++;
        }
        else 
        {
            array[indexOfMergedArray] = rightArray[i_q];
            count= count + (p - i_p);
            i_q++;
        }
        indexOfMergedArray++;
    }
      
    // Copy the remaining elements of
    // left[], if there are any
    while (i_p < p) 
    {
        array[indexOfMergedArray] = 
        leftArray[i_p];
        i_p++;
        indexOfMergedArray++;
    }
  
    // Copy the remaining elements of
    // right[], if there are any
    while (i_q < q) 
    {
        array[indexOfMergedArray] = 
        rightArray[i_q];
        i_q++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], 
               int const begin, 
               int const end, int &count)
{
    // Returns recursively
    if (begin >= end)
        return; 
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid,count);
    mergeSort(array, mid + 1, end,count);
    merge(array, begin, mid, end,count);
}

int main() {
    int count=0;
    int n; cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++)
    {int x; cin>>x; A.push_back(x);}


    //int n=A.size();
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=A[i];
    }
    
    mergeSort(a,0,n-1,count);
    
    cout<< count;
}
