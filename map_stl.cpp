#include<bits/stdc++.h>
using namespace std;

int main()
{
    map <int,int> m1;

    //inserting key-value pairs
    m1.insert(pair<int,int> (1,26));
    m1.insert(pair <int,int> (2,45));
    m1.insert(pair <int,int> (3,76));
    m1.insert(pair <int,int> (4,98));
    m1.insert(pair <int,int> (5,31));
    //another way:
    m1[6]=88;
    m1[7]=107;

    //defining iterator for map
    map <int,int> ::iterator it1;
    cout<<"the map entered is:"<<endl;
    for(it1=m1.begin(); it1 !=m1.end(); it1++)
    {
        cout<< it1->first <<" "<< it1->second <<endl;
    }

    //assigning elem from map1 to map2
    map<int,int> m2(m1.begin(),m1.end());

    //removing elem upto key 2
    m2.erase(m2.begin(),m2.find(3)); //can be done for single key also

    map <int,int> ::iterator it2;
    cout<<"the map 2 after modification is:"<<endl;
    for(it2=m2.begin(); it2 !=m2.end(); it2++)
    {
        cout<< it2->first <<" "<< it2->second <<endl;
    }

    cout<<"upper bound(5) key= "<< m2.upper_bound(5)->first <<endl;
    cout<<"lower bound(5) key= "<< m2.lower_bound(5)->first <<endl;



}