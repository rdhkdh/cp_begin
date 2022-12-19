//INTERVIEWBIT SOLUTION
// Space complexity= O(n), Time complexity= O(n)

int Solution::perfectPeak(vector<int> &A) 
{
    int n= A.size();
    int left_max[n-2],right_min[n-2];

    int max= A[0]; //Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains maximum element from 0 to i-1 in input array.
    for(int i=1;i<=n-2;i++)
    {
        left_max[i-1]=max;
        if(A[i]>max) {max=A[i];} 
    }

    int min= A[n-1]; //Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains minimum element from to N-1 to i+1 in input array.
    for(int i=n-2;i>=1;i--)
    {
        right_min[i-1]=min;
        if(A[i]<min) {min=A[i];} 
    }

    //Traverse input array. For every element A[i], check if A[i] is greater than leftMax[i] and smaller than rightMin[i]. If yes, return 1.
    for(int i=1;i<n-2;i++)
    {
        if( A[i]>left_max[i-1] && A[i]<right_min[i-1] ) {return 1;}
    }

    return 0;
}


// MY SOLUTION
// Space complexity= O(1), Time complexity= O(n2) Worst case, best case= Big-Omega(n)


int Solution::perfectPeak(vector<int> &A) {
    int n= A.size();
    int left_max= A[0];
    int right_min= *min_element( A.begin()+2, A.end() );
    
    for(int i=1;i<=n-2;i++)
    {
        if(A[i]>left_max)
        {
            if(A[i]<right_min) {return 1;}
            else{
                left_max=A[i];
                if(A[i+1]==right_min) 
                {
                    right_min= *min_element( A.begin()+i+2, A.end() );
                }
            }
        }
        else{
            if(A[i+1]==right_min) 
            {
                right_min= *min_element( A.begin()+i+2, A.end() );
            }
        }
    }
    return 0;
}
