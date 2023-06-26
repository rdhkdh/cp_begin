#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> generateMatrix(int A) {
    int sq; //no of squares
    if(A%2==0) { sq= A/2; }
    else { sq= (A+1)/2; }
    
    vector<vector<int>> v;
    int arr[A][A]={};
    int top=0,bottom=A-1,left=0,right=A-1;
    
    int r,c;
    int dirn=1; // 1=right,2=down,3=left,4=up
    
    int num=1;
    for(int i=1;i<=sq;i++)
    {
        r=top,c=left;
        if(dirn==1) //right
        {
            while(c<=right)
            {
                arr[r][c]=num; num++; c++; 
            }
            dirn=2; c=right; r++;
        }
        if(dirn==2) //down
        {
            while(r<=bottom)
            {
                arr[r][c]=num; num++; r++; 
            }
            dirn=3; r=bottom; c--;
        }
        if(dirn==3) //left
        {
            while(c>=left)
            {
                arr[r][c]=num; num++; c--; 
            }
            dirn=4; c=left; r--;
        }
        if(dirn==4) //up
        {
            while(r>top)
            {
                arr[r][c]=num; num++; r--; 
            }
            dirn=1;
        }
        left++; right--; top++; bottom--;
    }
    
    for(int i=0;i<A;i++)
    {
        vector<int> temp;
        for(int k=0;k<A;k++)
        {
            temp.push_back(arr[i][k]);
        }
        v.push_back(temp);
    }
    
    return v;
}

int main()
{
    vector<vector<int>> v= generateMatrix(5);
}