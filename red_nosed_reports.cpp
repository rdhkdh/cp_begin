#include<bits/stdc++.h>
using namespace std;

vector<int> get_levels(string str)
{
    string temp="";
    vector<int> res;

    for(auto u: str)
    {
        if(u==' ')
        {
            res.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += u;
        }
    }
    res.push_back(stoi(temp));

    return res;
}

int main()
{

    freopen("red_nosed_reports_input.txt", "r", stdin);
    freopen("red_nosed_reports_output.txt", "w", stdout);

    string str;
    int count=0;

    while(getline(cin, str))
    {
        vector<int> v = get_levels(str);

        int flag=0; //flag=0 for increasing, flag=1 for decreasing
        if(v[1]-v[0] < 0) {flag=1;}
        string ans = "Safe";

        for(int i=1; i<v.size(); i++)
        {
            if(flag==0) //inc sequence
            {
                int diff = v[i]-v[i-1];
                if(diff<0)
                {
                    ans = "Unsafe";
                    break;
                }
                if(!(diff>=1 && diff<=3))
                {
                    ans = "Unsafe";
                    break;
                }
            }
            if(flag==1) //dec sequence
            {
                int diff = v[i]-v[i-1];
                diff = -diff; //making it +ve

                if(diff<0)
                {
                    ans = "Unsafe";
                    break;
                }
                if(!(diff>=1 && diff<=3))
                {
                    ans = "Unsafe";
                    break;
                }
            }
        }

        cout<<ans<<endl;
        if(ans=="Safe") {count++;}
    }

    cout<<count<<endl;
}