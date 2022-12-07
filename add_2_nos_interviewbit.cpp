int Solution::addNumbers(int A, int B) {
    int m,n;
    m= floor(log10(A)+1);
    n= floor(log10(B)+1);
    int result;
    
    if(m>=n) //B is smaller no.
    {
        string sum;
        int carry=0;
        
        while(n--)
        { 
           int d1= B%10;
           int d2= A%10;
           int s= (d1+d2+carry)%10;
           carry= (d1+d2+carry)/10;
           sum= sum + to_string(s);
           
           B=B/10; A=A/10; 
        }
        
        int t= m-n;
        while(t--)
        {
            int d=A%10;
            int s2= (d+0+carry)%10;
            carry= (d+0+carry)/10;
            sum = sum + to_string(s2);
            A=A/10;
        }
        
        
        sum= sum + to_string(carry);
        
        reverse(sum.begin(),sum.end());
        result= stoi(sum);
    }
    
    if(m<n) //A is smaller no.
    {
        string sum;
        int carry=0;
        
        while(m--)
        { 
           int d1= B%10;
           int d2= A%10;
           int s= (d1+d2+carry)%10;
           carry= (d1+d2+carry)/10;
           sum= sum + to_string(s);
           
           B=B/10; A=A/10; 
        }
        
        int t= n-m;
        while(t--)
        {
            int d=B%10;
            int s2= (d+0+carry)%10;
            carry= (d+0+carry)/10;
            sum = sum + to_string(s2);
            B=B/10;
        }
        
        
        sum= sum + to_string(carry);
        
        reverse(sum.begin(),sum.end());
        result= stoi(sum);
    }
    
    return result;
}
