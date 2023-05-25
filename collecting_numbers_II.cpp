#include<bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{   
    int n,m; 
    cin>>n>>m;
    
    int position[n+2] = {0}, a[n+1] = {0};
    position[n+1] = n+1; //posn[0]=0
    for (int i = 1; i <= n; i++) {
		cin>>a[i];
		position[a[i]] = i;
    }
    int round = 1;
    for (int i = 2; i <= n; i++) {
		if (position[i-1] > position[i]) {round++;}
    }

    while(m--) 
    {
		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (position[r-1] <= position[r] && position[r-1] > y) round++;
		if (position[r-1] > position[r] && position[r-1] <= y) round--;
		if (position[r] <= position[r+1] && y > position[r+1]) round++;
		if (position[r] > position[r+1] && y <= position[r+1]) round--;		
		position[r] = y;
		if (position[s-1] <= position[s] && position[s-1] > x) round++;
		if (position[s-1] > position[s] && position[s-1] <= x) round--;
		if (position[s] <= position[s+1] && x > position[s+1]) round++;
		if (position[s] > position[s+1] && x <= position[s+1]) round--;	
		position[s] = x;
		cout<<round<<endl;
    }
}