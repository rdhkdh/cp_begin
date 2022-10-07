#include<bits/stdc++.h>
using namespace std;
int main()
{
    //push_back(), pop_back()
    vector<int> v1={2,4,6,8,10};
    v1.push_back(12);
    v1.push_back(14);
    for(int i=0;i<7;i++) {cout<<v1[i]<<" ";}
    cout<<endl;
    v1.pop_back();
    for(int i=0;i<6;i++) {cout<<v1[i]<<" ";}
    cout<<endl;

    //v1.at(), get< > (v1), v1[] -methods of accessing elements

    //size(),resize(),accumulate()
    cout<<v1.size()<<endl;
    v1.resize(3);
    for(int i=0;i<v1.size();i++) {cout<<v1[i]<<" ";}
    cout<<endl;
    v1.resize(7,9);
    for(int i=0;i<v1.size();i++) {cout<<v1[i]<<" ";}
    cout<<endl;
    int sum=0;
    cout<<accumulate(v1.begin(),v1.end(),sum)<<endl; //sum of all elements
    
    //begin(),end(),rbegin(),rend()
    cout<<*v1.begin()<<" "<<*v1.end()<<endl; //end points to after the last element- accessing invalid location 
    cout<<*v1.rbegin()<<" "<<*v1.rend()<<endl; //similarly rend
    //difference between begin/end and front/back is that begin/end return pointers


    //sort()
    vector<int> v2= {4,3,76,335,21,87,54,35,0,23,40};
    sort( v2.begin(),v2.end() );
    for(int i=0; i<v2.size();i++) {cout<<v2[i]<<" ";}
    cout<<endl;

    //upper_bound()-returns iterator to next bigger value. (elem>val)
    //lower_bound()- if value present, it returns iterator to that posn. If val not present, it returns iterator to next bigger element. (elem>=val)
    //IMPORTANT: vector or array should always be sorted before using these 2 fns.
    cout<<*upper_bound(v2.begin(),v2.end(),72)<<endl;
    cout<<*upper_bound(v2.begin(),v2.end(),76)<<endl; //will NOT return 76. Will return the next bigger element.
    cout<<*lower_bound(v2.begin(),v2.end(),72)<<endl;
    cout<<*lower_bound(v2.begin(),v2.end(),76)<<endl;

    if( binary_search(v2.begin(),v2.end(),21) ) {cout<<"21 present\n";}
    else{cout<<"21 not present\n";}

    //clear(): for removing all elem and making it size 0.
    v2.clear();

    return 0;
}
