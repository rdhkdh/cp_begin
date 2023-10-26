#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int lcm(std::vector<int> numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 1,
        [](int x, int y) { return (x * y) / gcd(x, y); });
}

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int main()
{
    string s;
    getline(cin,s);
    set<int> num;
    
    string temp="";
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ') 
        {
            num.insert(stoi(temp));
            temp="";
            continue;
        }
        else{
            temp += s[i];
        }
    }
    num.insert(stoi(temp));

    //for(auto u: num) {cout<<u<<" ";}
    int q = *num.begin();
    num.erase(num.begin());

    vector<int> v;
    for(auto u: num) {v.push_back(u);}
    int l = lcm(v);

    if(isPrime(l+q)) {cout<<l+q<<endl;}
    else{cout<<"None\n";}
}