#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n]; // 0 indexed
    int position[n+1]; //1 to n

    for(int i=0;i<n;i++) 
    {
        cin>>a[i]; 
        position[a[i]]=i+1; // 1 indexed
    }
    int x[m],y[m]; //posn nos 1-indexed
    for(int i=0;i<m;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>y[i]) {swap(x[i],y[i]);} //keep x[i] as smaller position
    }

    int round=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<n && position[a[i]+1]<position[a[i]]) {round++;}
    } //gets initial number of rounds

    for(int i=0;i<m;i++)
    {
        int A=a[x[i]-1],B=a[y[i]-1];
        if(abs(A-B)>=2)
        {
            int flag_x1=1,flag_x2=1,flag_y1=1,flag_y2=1; //natural increasing order

            if( A-1 >=1 )
            {
                if( position[A-1]<position[A] ) {flag_x1=1;} //natural increasing order
                else{flag_x1=0;} // an inversion exists
            }
            if( A+1 <=n )
            {
                if( position[A]<position[A+1] ) {flag_x2=1;} //natural increasing order
                else{flag_x2=0;} // an inversion exists
            }

            if( B-1 >=1 )
            {
                if( position[B-1]<position[B] ) {flag_y1=1;} //natural increasing order
                else{flag_y1=0;} // an inversion exists
            }
            if( B+1 <=n )
            {
                if( position[B]<position[B+1] ) {flag_y2=1;} //natural increasing order
                else{flag_y2=0;} // an inversion exists
            }

            position[A] = y[i];
            position[B] = x[i];
            swap(a[x[i]-1], a[y[i]-1]);
            swap(A,B);

            if( A-1 >=1 )
            {
                if( position[ A-1 ]<position[ A ] && flag_x1==0) {round--;}
                if( position[ A-1 ]>position[ A ] && flag_x1==1) {round++;}
            }
            if( A+1 <=n )
            {
                if( position[ A ]<position[ A+1 ] && flag_x2==0) {round--;}
                if( position[ A ]>position[ A+1 ] && flag_x2==1) {round++;}
            }

            if( B-1 >=1 )
            {
                if( position[ B-1 ]<position[ B ] && flag_y1==0) {round--;}
                if( position[ B-1 ]>position[ B ] && flag_y1==1) {round++;}
            }
            if( B+1 <=n )
            {
                if( position[ B ]<position[ B+1 ] && flag_y2==0) {round--;}
                if( position[ B ]>position[ B+1 ] && flag_y2==1) {round++;}
            }
        }
        else // |A-B|=1
        {
            int flag_x1=1,flag_x2=1,flag_y1=1; //natural increasing order
            if( A-1 >=1 )
            {
                if( position[A-1]<position[A] ) {flag_x1=1;} //natural increasing order
                else{flag_x1=0;} // an inversion exists
            }
            if( A+1 <=n )
            {
                if( position[A]<position[A+1] ) {flag_x2=1;} //natural increasing order
                else{flag_x2=0;} // an inversion exists
            }
            if( A+2 <=n )
            {
                if( position[A+1]<position[A+2] ) {flag_y1=1;} //natural increasing order
                else{flag_y1=0;} // an inversion exists
            }

            position[A] = y[i];
            position[B] = x[i];
            swap(a[x[i]-1], a[y[i]-1]);
            swap(A,B);

            if( A-1 >=1 )
            {
                if( position[ A-1 ]<position[ A ] && flag_x1==0) {round--;}
                if( position[ A-1 ]>position[ A ] && flag_x1==1) {round++;}
            }
            if( A+1 <=n ) //effectively B
            {
                if( position[ A ]<position[ A+1 ] && flag_x2==0) {round--;}
                if( position[ A ]>position[ A+1 ] && flag_x2==1) {round++;}
            }
            if( A+2 <=n ) // B+1
            {
                if( position[ A+1 ]<position[ A+2 ] && flag_y1==0) {round--;}
                if( position[ A+1 ]>position[ A+2 ] && flag_y1==1) {round++;}
            }
        }
        

        cout<<round<<endl;
    }
}