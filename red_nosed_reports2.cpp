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

bool is_safe(vector<int> v)
{
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

    if(ans=="Safe") {return true;}
    return false;
}

bool check(vector<int> v)
{
    bool res = is_safe(v);
    if(res==true) {return true;}

    // if not safe, remove 1 elem and check again

    int flag=0; //flag=0 for increasing, flag=1 for decreasing
    if(v[1]-v[0] < 0) {flag=1;}

    for(int i=1; i<v.size(); i++)
    {
        if(flag==0) //inc sequence
        {
            int diff = v[i]-v[i-1];
            if(diff<0 || !(diff>=1 && diff<=3)) 
            {
                vector<int> v1 = v;
                v1.erase(v1.begin()+i);
                bool t1 = is_safe(v1);

                vector<int> v2 = v;
                v2.erase(v2.begin()+i-1);
                bool t2 = is_safe(v2);

                if(t1||t2) {return true;}

                break;
            }
        }
        if(flag==1) //dec sequence
        {
            int diff = v[i]-v[i-1];
            diff = -diff; //making it +ve

            if(diff<0 || !(diff>=1 && diff<=3)) 
            {
                vector<int> v1 = v;
                v1.erase(v1.begin()+i);
                bool t1 = is_safe(v1);

                vector<int> v2 = v;
                v2.erase(v2.begin()+i-1);
                bool t2 = is_safe(v2);

                if(t1||t2) {return true;}

                break;
            }
        }
    }

    return false;
}

int main()
{
    freopen("red_nosed_reports_input.txt", "r", stdin);
    freopen("red_nosed_reports_output.txt", "w", stdout);

    string str;
    int count=0; //no of safe reports

    while(getline(cin, str))
    {
        vector<int> v = get_levels(str);
        bool ans = check(v);

        if(ans==true) 
        {
            cout<<"Safe"<<endl;
            count++;
        } 
        else{
            cout<<"Unsafe"<<endl;
        }
    }

    cout<<count<<endl;
}