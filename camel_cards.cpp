// day 7, advent of code 2023
#include <bits/stdc++.h>
using namespace std;

map<char,int> priority {
    {'2',1},
    {'3',2},
    {'4',3},
    {'5',4},
    {'6',5},
    {'7',6},
    {'8',7},
    {'9',8},
    {'T',9},
    {'J',10},
    {'Q',11},
    {'K',12},
    {'A',13}
};

bool custom_sort(pair<string,int> a, pair<string,int> b)
{
    //ascending order of priority- smaller priority, smaller rank. 1- weakest, n- strongest
    if(priority[a.first[0]] < priority[b.first[0]]) {return true;}
    else if(
        a.first[0]==b.first[0] && 
        priority[a.first[1]] < priority[b.first[1]]
    ) {return true;}
    else if(
        a.first[0]==b.first[0] &&
        a.first[1]==b.first[1] && 
        priority[a.first[2]] < priority[b.first[2]]
    ) {return true;}
    else if(
        a.first[0]==b.first[0] &&
        a.first[1]==b.first[1] &&
        a.first[2]==b.first[2] && 
        priority[a.first[3]] < priority[b.first[3]]
    ) {return true;}
    else if(
        a.first[0]==b.first[0] &&
        a.first[1]==b.first[1] &&
        a.first[2]==b.first[2] &&
        a.first[3]==b.first[3] &&
        priority[a.first[4]] < priority[b.first[4]]
    ) {return true;}

    return false;
}

int main()
{
    /* 
    type=0, five of a kind      aaaaa
    type=1, four of a kind      aaaab
    type=2, full house          aaabb
    type=3, three of a kind     aaabc       
    type=4, two pair            aabbc
    type=5, one pair            aabcd
    type=6, high card           abcde
    */ 
    vector<pair<string,int>> type[7];     // hand, bid

    FILE* fp = fopen("../advent_of_code2023/q7_input.txt","r");
    int b;
    char* inp;
    string str;

    while(!feof(fp))
    {
        fscanf(fp,"%s %d\n",inp,&b);
        str = inp;

        map<char,int> freq;
        for(int i=0;i<5;i++) { freq[str[i]]++; }

        if(freq.size()==1) { type[0].push_back(make_pair(str,b)); }
        if(freq.size()==2)
        {
            if( freq.begin()->second ==4 || freq.begin()->second ==1 )
            {
                type[1].push_back(make_pair(str,b));
            }
            else{
                type[2].push_back(make_pair(str,b));
            }
        }
        if(freq.size()==3)
        {
            int flag=0;
            for(auto u: freq)
            {
                if(u.second==3) { type[3].push_back(make_pair(str,b)); flag=1; break;}
            }
            if(flag==0) { type[4].push_back(make_pair(str,b)); }
        }
        if(freq.size()==4) {type[5].push_back(make_pair(str,b));}
        if(freq.size()==5) {type[6].push_back(make_pair(str,b));}

    }

    fclose(fp);

    for(int i=0;i<7;i++)
    {
        sort(type[i].begin(),type[i].end(),custom_sort);
    }

    int rank = 0;
    long long winnings=0;
    for(int i=6;i>=0;i--)
    {
        for(int j=0;j<type[i].size();j++)
        {
            rank++;
            cout<<type[i][j].second<<" "<<rank<<endl;
            winnings += (type[i][j].second * rank); //bid*rank
        } 
    }

    cout<<winnings<<endl;
}