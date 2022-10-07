#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s1={2,3,5,7,11,13,335,467,856,659,900,1231}; //elem access done using iterators.

    //begin(), end(), rbegin(), rend()
    cout<<*s1.begin()<<" "<<*s1.end()<<endl; //end- garbage value
    cout<<*s1.rbegin()<<" "<<*s1.rend()<<endl; //rend- garbage value
    
    //find()
    for( auto it2= s1.find(5); it2!=s1.end(); it2++)
    {
        cout<<*it2<<" ";
    }
    cout<<endl;

    //insert(), erase()
    s1.erase(5);
    auto it3=s1.find(335), it4=s1.find(900);
    s1.erase(it3,it4);
    s1.insert(24);
    s1.insert(12);
    s1.insert(13);
    for(auto iterator1= s1.begin(); iterator1!=s1.end(); iterator1++)
    {
        cout<<*iterator1<<" ";
    }
    cout<<endl;

    //size()
    cout<<s1.size()<<endl;

    //lower_bound(), upper_bound(),
    cout<<*s1.upper_bound(13)<<" "<<*s1.upper_bound(15)<<endl;
    cout<<*s1.lower_bound(13)<<" "<<*s1.lower_bound(15)<<endl;

    //clear()
    s1.clear();
}