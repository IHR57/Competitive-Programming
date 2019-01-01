#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define PI 3.141592653589793238
using namespace std;

int main()
{
    int test, caseNo = 1;
    double ax, ay, bx, by, cx, cy, dx, dy, diffx, diffy, area;

    scanf("%d", &test);

    while(test--){
        scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
        diffx = cx - bx;
        diffy = cy - by;
        dx = ax + diffx;
        dy = ay + diffy;


        double lengthAB = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
        double lengthBC = sqrt((cx - bx) * (cx - bx) + (cy - by) * (cy - by));
        double lengthAC = sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));

        double s = (lengthAB + lengthBC + lengthAC ) / 2;
        area = s * (s - lengthAB) * (s - lengthBC) * (s - lengthAC);
        area = sqrt(area);

        printf("Case %d: %.lf %.lf %.lf\n", caseNo++, dx, dy, area * 2.0);
    }

    return 0;
}
