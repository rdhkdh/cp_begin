#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cottontail_climb_part_1_input.txt", "r", stdin);
    freopen("cottontail_climb_part_1_output.txt", "w", stdout);

    int t;
    cin>>t;
    int og = t;

    long long int a,b,m;


    while(t--)
    {
        cin>>a>>b>>m;

        int dig_a = to_string(a).length();
        int dig_b = to_string(b).length();

        map<int, vector<long long>> mp;
        mp[1] = {1,2,3,4,5,6,7,8,9};
        mp[3] = {121, 232, 343, 454, 565, 676, 787, 898};
        mp[5] = {12321, 23432, 34543, 45654, 56765, 67876, 78987};
        mp[7] = {1234321, 2345432, 3456543, 4567654, 5678765, 6789876};
        mp[9] = {123454321, 234565432, 345676543, 456787654, 567898765};
        mp[11] = {12345654321, 23456765432, 34567876543, 45678987654};
        mp[13] = {1234567654321, 2345678765432, 3456789876543};
        mp[15] = {123456787654321, 234567898765432};
        mp[17] = {12345678987654321};


        // int count=0;
        // if(dig_b-dig_a >= 2)
        // {
        //     for(auto u: mp[dig_a])
        //     {
        //         if(a <= u) //found a peak in that range
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        //     for(int d = dig_a; d<=dig_b; d+=2)
        //     {
        //         for(auto u: mp[d])
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        //     for(auto u: mp[dig_b])
        //     {
        //         if(u <= b) //found a peak in that range
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        // }
        // else if(dig_b-dig_a==1)
        // {   
        //     for(auto u: mp[dig_a])
        //     {
        //         if(a <= u) //found a peak in that range
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        //     for(auto u: mp[dig_b])
        //     {
        //         if(u <= b) //found a peak in that range
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        // }
        // else if(dig_b-dig_a==0)
        // {
        //     for(auto u: mp[dig_a])
        //     {
        //         if(a <= u && u<=b) //found a peak in that range
        //         {
        //             if(u%m==0) {count++;}
        //         }
        //     }
        // }

        int count=0;
        for(auto u: mp)
        {
            for(auto v: u.second)
            {
                if(a<=v && v<=b)
                {
                    if(v%m==0) {count++;}
                }
            }
        }

        cout<<"Case #"<<og-t<<": "<<count<<endl;
    }
}