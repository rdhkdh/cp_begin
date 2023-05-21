int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    int n=A.size();
    int a,b,res;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]=="+")
        {
            a= s.pop(); 
            b=s.pop();
            res= b+a;
            s.push(res);
        }
        else if(A[i]=="-")
        {
            a= s.pop(); 
            b=s.pop();
            res= b-a;
            s.push(res);
        }
        else if(A[i]=="/")
        {
            a= s.pop(); 
            b=s.pop();
            res= b/a;
            s.push(res);
        }
        else if(A[i]=="*")
        {
            a= s.pop(); 
            b=s.pop();
            res= b*a;
            s.push(res);
        }
        else
        {
            int x= stoi(A[i]);
            s.push(x);
        }
    }
    
    int ans = s.pop();
    return ans;
    
}
