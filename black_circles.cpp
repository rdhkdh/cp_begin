#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Circle {
    double x, y;
};

bool canReachTargetWithoutTouchingCircles(double xs, double ys, double xt, double yt, const vector<Circle>& circles) {
    double directDistance = sqrt((xt - xs) * (xt - xs) + (yt - ys) * (yt - ys));

    for (const auto& circle : circles) {
        double ds = sqrt((circle.x - xs) * (circle.x - xs) + (circle.y - ys) * (circle.y - ys));
        double dt = sqrt((circle.x - xt) * (circle.x - xt) + (circle.y - yt) * (circle.y - yt));
        
        // Check if either point is inside the circle initially (should not be as per problem statement)
        if (ds < 0 || dt < 0) {
            return false;
        }

        // Calculate the critical time when you might hit the circle
        double maxAllowedDistance = (ds + dt + directDistance) / 2.0;
        
        // If direct path is shorter than the max allowed without touching, it means it intersects
        if (maxAllowedDistance < directDistance) {
            return false;
        }
    }
    
    return true;
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin >> n;

        vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            cin >> circles[i].x >> circles[i].y;
        }

        double xs, ys, xt, yt;
        cin >> xs >> ys;
        cin >> xt >> yt;

        if (canReachTargetWithoutTouchingCircles(xs, ys, xt, yt, circles)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
