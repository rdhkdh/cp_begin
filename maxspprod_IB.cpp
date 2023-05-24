/*
don't know mistake - followed algo as described
*/

int Solution::maxSpecialProduct(vector<int> &A) {
    stack<pair<int,int>> s;
    vector<pair<int,int>> v;
    int n= A.size();
    int lsv[n],rsv[n];
    
    for(int i=0;i<n;i++)
    {
        v.push_back( make_pair(A[i],i) );
        sort(v.begin(),v.end()); //asc order by value
        for(int j=0;j<v.size()-1;j++)
        {
            s.push(v[j]); //desc order by value
        }
        
        while(!s.empty() && s.top().first<=A[i] )
        {
            s.pop(); v.pop_back();
        }
        lsv[i] = (s.empty()) ? 0:s.top().second;
        s.push(v[i]);
    }
    
    v.clear();
    stack<pair<int,int>> s2;
    
    for(int i=n-1;i>=0;i--)
    {
        v.push_back( make_pair(A[i],i) );
        sort(v.begin(),v.end()); //asc order by value
        for(int j=0;j<v.size()-1;j++)
        {
            s2.push(v[j]); //desc order by value
        }
        
        while(!s2.empty() && s2.top().first<=A[i] )
        {
            s2.pop(); v.pop_back();
        }
        rsv[i] = (s2.empty()) ? 0:s2.top().second;
        s2.push(v[i]);
    }
    
    long long int temp, m=1000000007;
    
    for(int i=0;i<n;i++)
    {
        temp = rsv[i]*lsv[i];
        temp = temp%1000000007;
        m= max(temp,m);
    }
    
    return m%1000000007;
    
}
