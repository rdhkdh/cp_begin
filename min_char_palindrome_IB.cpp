// Time limit exceeded - do by KMP, LPS

bool check_palindrome(string s)
{
    string s1=s;
    reverse(s.begin(),s.end());
    if(s1==s)
    {return true;}
    return false;
}

int Solution::solve(string A) {
    int n=A.length();
    int latest_yes=0;
    for(int i=n-1;i>=0;i--)
    {
        if( check_palindrome(A.substr(0,i+1)) )
        {
            latest_yes=i;
            break;
        }
    }
    return n-1-latest_yes;
}
