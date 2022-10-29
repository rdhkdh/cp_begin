#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    long long int p[n];

    for(int i=0;i<n;i++) { cin>>p[i]; }
    for(int i=0;i<n;i++) { cin>>a[i]; }
    for(int i=0;i<n;i++) { cin>>b[i]; }

    set<long long int> s1,s2,s3;
    for(int i=0;i<n;i++) 
    { 
        if(a[i]==1 || b[i]==1) {s1.insert(p[i]);}
        if(a[i]==2 || b[i]==2) {s2.insert(p[i]);}
        if(a[i]==3 || b[i]==3) {s3.insert(p[i]);}
    }

    int m;
    cin>>m;
    int c[m];
    for(int i=0;i<m;i++) {cin>>c[i];}

    for(int i=0;i<m;i++) 
    {
        
        if(c[i]==1)
        {
            if(s1.empty()) {cout<<-1<<" ";}
            else 
            {
                cout<< *s1.begin() <<" ";
                set<long long int>::iterator it2,it3;
                it2= s2.find(*s1.begin());
                it3= s3.find(*s1.begin());

                if( it2 != s2.end() ) {s2.erase(it2);}
                if( it3 != s3.end() ) {s3.erase(it3);}

                s1.erase(s1.begin());
            }
            
        }

        if(c[i]==2)
        {
            if(s2.empty()) {cout<<-1<<" ";}
            else 
            {
                cout<< *s2.begin() <<" ";
                set<long long int>::iterator it1,it3;
                it1= s1.find(*s2.begin());
                it3= s3.find(*s2.begin());

                if( it1 != s1.end() ) {s1.erase(it1);}
                if( it3 != s3.end() ) {s3.erase(it3);}

                s2.erase(s2.begin());
            }
            
        }

        if(c[i]==3)
        {
            if(s3.empty()) {cout<<-1<<" ";}
            else 
            {
                cout<< *s3.begin() <<" ";
                set<long long int>::iterator it1,it2;
                it1= s1.find(*s3.begin());
                it2= s2.find(*s3.begin());

                if( it1 != s1.end() ) {s1.erase(it1);}
                if( it2 != s2.end() ) {s2.erase(it2);}

                s3.erase(s3.begin());
            }
            
        }
    }
}