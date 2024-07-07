#include<bits/stdc++.h>
using namespace std;
#define int long long

struct point
{
    int x;
    int y;
    int z;

    // Overload the - operator for point subtraction
    point operator-(const point& other) const {
        return point{x - other.x, y - other.y, z - other.z};
    }

    // Overload a function for the dot product
    int dot(const point& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
};

int32_t main()
{
    int a,b,c,d,e,f;
    int a1,b1,c1,d1,e1,f1;

    cin>>a>>b>>c>>d>>e>>f;
    cin>>a1>>b1>>c1>>d1>>e1>>f1;

    //check for same faces
    if( (d1<max(a,d) && min(a,d)<d1) && e1==e && f1==f ) 
    {
        cout<<"Yes\n";
    }

    if()
    {

    }

    //first cuboid
    struct point vertex[8];
    vertex[0].x = a; vertex[0].y = b; vertex[0].z = c; //P1
    vertex[1].x = a; vertex[1].y = e; vertex[1].z = c; //P2
    vertex[2].x = a; vertex[2].y = e; vertex[2].z = f; //P3
    vertex[3].x = a; vertex[3].y = b; vertex[3].z = f; //P4
    vertex[4].x = d; vertex[4].y = b; vertex[4].z = c; //P5
    vertex[5].x = d; vertex[5].y = e; vertex[5].z = c; //P6
    vertex[6].x = d; vertex[6].y = e; vertex[6].z = f; //P7
    vertex[7].x = d; vertex[7].y = b; vertex[7].z = f; //P8

    //second cuboid
    struct point vertex1[8];
    vertex1[0].x = a1; vertex1[0].y = b1; vertex1[0].z = c1; //P1'
    vertex1[1].x = a1; vertex1[1].y = e1; vertex1[1].z = c1; //P2'
    vertex1[2].x = a1; vertex1[2].y = e1; vertex1[2].z = f1; //P3'
    vertex1[3].x = a1; vertex1[3].y = b1; vertex1[3].z = f1; //P4'
    vertex1[4].x = d1; vertex1[4].y = b1; vertex1[4].z = c1; //P5'
    vertex1[5].x = d1; vertex1[5].y = e1; vertex1[5].z = c1; //P6'
    vertex1[6].x = d1; vertex1[6].y = e1; vertex1[6].z = f1; //P7'
    vertex1[7].x = d1; vertex1[7].y = b1; vertex1[7].z = f1; //P8'


    //check for first cuboid
    struct point u = vertex[0] - vertex[1]; //P1-P2
    struct point v = vertex[0] - vertex[3]; //P1-P4
    struct point w = vertex[0] - vertex[4]; //P1-P5

    int up1 = u.dot(vertex[0]); //u.P1
    int up2 = u.dot(vertex[1]); //u.P2

    int vp1 = v.dot(vertex[0]); //v.P1
    int vp4 = v.dot(vertex[3]); //v.P4

    int wp1 = w.dot(vertex[0]); //w.P1
    int wp5 = w.dot(vertex[4]); //w.P5

    for(int i=0;i<8;i++)
    {
        int ux = u.dot(vertex1[i]);
        int vx = v.dot(vertex1[i]);
        int wx = w.dot(vertex1[i]);

        if(
            (min(up1,up2)<ux && ux<max(up1,up2)) &&
            (min(vp1,vp4)<vx && vx<max(vp1,vp4)) &&
            (min(wp1,wp5)<wx && wx<max(wp1,wp5))
        )
        {
            cout<<"Yes\n";
            return 0;
        }
    }

    //check for second cuboid
    u = vertex1[0] - vertex1[1]; //P1-P2
    v = vertex1[0] - vertex1[3]; //P1-P4
    w = vertex1[0] - vertex1[4]; //P1-P5

    up1 = u.dot(vertex1[0]); //u.P1
    up2 = u.dot(vertex1[1]); //u.P2

    vp1 = v.dot(vertex1[0]); //v.P1
    vp4 = v.dot(vertex1[3]); //v.P4

    wp1 = w.dot(vertex1[0]); //w.P1
    wp5 = w.dot(vertex1[4]); //w.P5

    for(int i=0;i<8;i++)
    {
        int ux = u.dot(vertex[i]);
        int vx = v.dot(vertex[i]);
        int wx = w.dot(vertex[i]);

        if(
            (min(up1,up2)<ux && ux<max(up1,up2)) &&
            (min(vp1,vp4)<vx && vx<max(vp1,vp4)) &&
            (min(wp1,wp5)<wx && wx<max(wp1,wp5))
        )
        {
            cout<<"Yes\n";
            return 0;
        }
    }

    cout<<"No\n";

    return 0;
}