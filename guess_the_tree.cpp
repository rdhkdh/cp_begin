#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n==2)
        {
            cout<<"! 1 2\n";
            continue;
        }
        
        vector<pair<int,int>> edges;
        vector<bool> visited(n+1,false);
        stack<int> s;
        int q = 1;
        int ans;
        int a = 1, b = 2;

        while(q <= 15*n)
        {
            while(a==b) {b%=n; b++;}
            if(a>b) {swap(a,b);}
        
            pair<int,int> p = {a,b};
            while(true)
            {
                if(find(edges.begin(),edges.end(),p) == edges.end()) {break;}
                b%=n; b++;
                p.second = b;
            }

            cout<<"? "<<a<<" "<<b<<endl;
            visited[a] = true, visited[b]=true;
            cin>>ans;
            if(ans==-1) {return 0;} //exceeded number of queries
            s.push(ans);

            if(ans==a || ans==b)
            {
                edges.push_back(make_pair(a,b));
                a = b;
                s.pop();

                if(!s.empty())
                {
                    b = s.top();
                    s.pop();
                }
                else
                {
                    int index=-1;
                    for(int i=1;i<=n;i++)
                    {
                        if(!visited[i])
                        {
                            index=i;
                            break;
                        }
                    }
                    if(index==-1) {break;}
                    b = index;
                }
            }
            else
            {
                b = ans;
            }
            
            cout.flush();
            q++;

            if(edges.size()==n-1) {break;}
        }

        cout<<"! ";
        for(auto u: edges)
        {
            cout<<u.first<<" "<<u.second<<" ";
        }
        cout<<endl;
    }
}