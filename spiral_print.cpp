//fails for corner cases- check

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) 
{
    vector<int> result;
    int m= A.size();
    int n= A[0].size();
    int t=0,b=m,l=0,r=n;
    int dir=0;
    
    while(t<=b && l<=r)
    {
        if(dir==0)
        {
            for(int i=l;i<r;i++) {result.push_back(A[t][i]);}
            t++;
            dir=1;
        }
        if(dir==1)
        {
            for(int i=t;i<b;i++) {result.push_back(A[i][r-1]);}
            r--;
            dir=2;
        }
        if(dir==2)
        {
            for(int i=r-1;i>=l && (b-1-t)>=0; i--) 
            {result.push_back(A[b-1][i]);}
            b--;
            dir=3;
        }
        if(dir==3)
        {
            for(int i=b-1;i>=t && (r-1-l)>=0; i--) 
            {result.push_back(A[i][l]);}
            l++;
            dir=0;
        }
    }
    return result;
}
