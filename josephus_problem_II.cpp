#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    indexed_set s;
    int n,k; 
    cin>>n>>k;
    for (int i = 1; i <= n; i++) { s.insert(i); }

    int ind = k%n;
    while(n--) {
        auto y = s.find_by_order(ind);
        cout<<*y<<' ';
        s.erase(y);
        if (n) { ind = (ind%n + k)%n; }
    }   
}