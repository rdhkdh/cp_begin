#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n;
    long long int x,y;
    cin>>n>>x>>y;

    int a[n],b[n];
    for(int i=0;i<n;i++) { cin>>a[i]; }
    for(int i=0;i<n;i++) { cin>>b[i]; }

    vector<pair<int,int>> sweet_salty;
    for(int i=0;i<n;i++)
    {
        sweet_salty.push_back(make_pair(a[i],b[i]));
    }

    sort(sweet_salty.begin(),sweet_salty.end()); //sorted by sweetness, ascending

    long long int curr_sweet=0;
    long long int curr_salty=0;
    int no_of_dishes1_sweet=0, no_of_dishes1_salty=0;
    for(int i=n-1;i>=0;i--)
    {
        curr_sweet += sweet_salty[i].first;
        no_of_dishes1_sweet++;

        if(curr_sweet>x) {break;}
    }
    for(int i=n-1;i>=0;i--)
    {
        curr_salty += sweet_salty[i].second;
        no_of_dishes1_salty++;

        if(curr_salty>y) {break;}
    }
    int no_of_dishes1 = min(no_of_dishes1_salty,no_of_dishes1_sweet);


    sort(sweet_salty.begin(), sweet_salty.end(), sortbysec); //sorted by saltiness, ascending

    curr_sweet=0;
    curr_salty=0;
    int no_of_dishes2_sweet=0, no_of_dishes2_salty=0;
    for(int i=n-1;i>=0;i--)
    {
        curr_sweet += sweet_salty[i].first;
        no_of_dishes2_sweet++;

        if(curr_sweet>x) {break;}
    }
    for(int i=n-1;i>=0;i--)
    {
        curr_salty += sweet_salty[i].second;
        no_of_dishes2_salty++;

        if(curr_salty>y) {break;}
    }
    int no_of_dishes2 = min(no_of_dishes2_salty,no_of_dishes2_sweet);

    cout<<min(no_of_dishes1,no_of_dishes2)<<endl;
}