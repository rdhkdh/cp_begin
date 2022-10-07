#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        //taking input
        int n;
        cin>>n;

        string a[n]; // Initialize String Array
        string b[n];
        string c[n];

        for(int i=0;i<n;i++) { cin>>a[i];}
        for(int i=0;i<n;i++) { cin>>b[i];}
        for(int i=0;i<n;i++) { cin>>c[i];}
        
        int pa=0,pb=0,pc=0; //points of the 3 guys
        
        //comparing a, searching in b and c
        for(int i=0;i<n;i++)
        {
            bool asb= binary_search(b,b+n,a[i]); //asb= a search b
            bool asc= binary_search(c,c+n,a[i]); //a search c
            int ASB,ASC;
            if(asb) {ASB=1;}
            else{ASB=0;}
            if(asc) {int ASC=1;}
            else{ASC=0;}

            if(ASB==1 && ASC==1) {pa=pa;} //no pts
            else if(ASB==1 && ASC==0) { pa+=1;}
            else if(ASB==0 && ASC==1) { pa+=1;} 
            else if(ASB==0 && ASC==0) {pa+=3;}
            cout<<pa<<" ";
        } cout<<endl;

        //comparing b, searching in a and c
        for(int i=0;i<n;i++)
        {
            bool bsa= binary_search(a,a+n,b[i]); //b search a
            bool bsc= binary_search(c,c+n,b[i]); //b search c
            int BSA,BSC;
            if(bsa) {BSA=1;}
            else{BSA=0;}
            if(bsc) {BSC=1;}
            else{BSC=0;}

            if(BSA==1 && BSC==1) {pb=pb;} //no pts
            else if(BSA==1 && BSC==0) { pb+=1;}
            else if(BSA==0 && BSC==1) { pb+=1;} 
            else if(BSA==0 && BSC==0) {pb+=3;}
            cout<<pb<<" ";
        } cout<<endl;

        //comparing c, searching in a and b
        for(int i=0;i<n;i++)
        {
            bool csa= binary_search(a,a+n,c[i]); //c search a
            bool csb= binary_search(b,b+n,c[i]); //c search b
            int CSA,CSB;
            if(csa) {CSA=1;}
            else{CSA=0;}
            if(csb) {CSB=1;}
            else{CSB=0;}

            if(CSA==1 && CSB==1) {pc=pc;} //no pts
            else if(CSA==1 && CSB==0) { pc+=1;}
            else if(CSA==0 && CSB==1) { pc+=1;} 
            else if(CSA==0 && CSB==0) {pc+=3;}
            cout<<pc<<" ";
        } cout<<endl;

        cout<<pa<<" "<<pb<<" "<<pc<<endl;


    }//end of while
}//end of main
