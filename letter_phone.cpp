#include<bits/stdc++.h>
using namespace std;

int main() {
    string A;
    cin>>A;
    int n=A.length();
    vector<string> res;
    vector<string> temp;
    
    res.push_back("");
    for(int i=0;i<n;i++)
    {
        int x= int(A[i])-48;
        string s5="";
        switch(x)
        {
            case 2: 
                for(auto u: res)
                {
                    s5=u; s5+='a'; temp.push_back(s5);
                    s5=u; s5+='b'; temp.push_back(s5);
                    s5=u; s5+='c'; temp.push_back(s5);
                }
                res= temp;
                temp.clear();
                break;
            case 3: 
                for(auto u: res)
                {
                    s5=u; s5+='d'; temp.push_back(s5);
                    s5=u; s5+='e'; temp.push_back(s5);
                    s5=u; s5+='f'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;
            case 4: 
                for(auto u: res)
                {
                    s5=u; s5+='g'; temp.push_back(s5);
                    s5=u; s5+='h'; temp.push_back(s5);
                    s5=u; s5+='i'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;
            case 5: 
                for(auto u: res)
                {
                    s5= u; s5+='j'; temp.push_back(s5);
                    s5=u; s5+='k'; temp.push_back(s5);
                    s5=u; s5+='l'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;
            case 6: 
                for(auto u: res)
                {
                    s5= u; s5+='m'; temp.push_back(s5);
                    s5=u; s5+='n'; temp.push_back(s5);
                    s5=u; s5+='o'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;
            case 7: 
                for(auto u: res)
                {
                    s5= u; s5+='p'; temp.push_back(s5);
                    s5=u; s5+='q'; temp.push_back(s5);
                    s5=u; s5+='r'; temp.push_back(s5);
                    s5=u; s5+='s'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;  
            case 8: 
                for(auto u: res)
                {
                    s5= u; s5+='t'; temp.push_back(s5);
                    s5=u; s5+='u'; temp.push_back(s5);
                    s5=u; s5+='v'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;       
            case 9: 
                for(auto u: res)
                {
                    s5= u; s5+='w'; temp.push_back(s5);
                    s5=u; s5+='x'; temp.push_back(s5);
                    s5=u; s5+='y'; temp.push_back(s5);
                    s5=u; s5+='z'; temp.push_back(s5); 
                }
                res= temp;
                temp.clear();
                break;          
            case 0: 
                for(auto u: res)
                {
                    s5= u; s5+='0'; temp.push_back(s5);
                }
                res= temp;
                temp.clear();
                break; 
            case 1: 
                for(auto u: res)
                {
                    s5= u; s5+='1'; temp.push_back(s5);
                }
                res= temp;
                temp.clear();
                break;   
        }
    }
    
    sort(res.begin(),res.end());
    for(auto u: res) {cout<<u<<endl;}
}
