#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> s1;

    //empty(),insert(),erase(),clear()
    //begin(),end(),size(),max_size()

    s1.insert(11);
    s1.insert(17);
    s1.insert(32);
    s1.insert(59);
    s1.insert(11);
    s1.insert(59);
    for(auto it1=s1.begin(); it1 !=s1.end(); it1++)
    {
        cout<<*it1<<" ";
    }
    cout<<endl;
    cout<<"size= "<<s1.size()<<" max_size= "<<s1.max_size()<<endl;    

    s1.erase(17);
    s1.erase(59);
    for(auto it1=s1.begin(); it1 !=s1.end(); it1++)
    {
        cout<<*it1<<" ";
    }
    cout<<endl;
    cout<<"size= "<<s1.size()<<" max_size= "<<s1.max_size()<<endl;

    s1.clear();
    if (s1.empty()) {cout<<"multiset is empty after clearing\n";}
    
}