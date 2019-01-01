#include <iostream>
#include <cstdio>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n, x, y, velocity;
    double distance, Min = 2147483647.0;

    cin>>a>>b;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>x>>y>>velocity;
        distance = sqrt((x-a) * (x-a) + (y - b) *(y-b));
        //cout<<distance<<endl;
        double time = distance / velocity;
        if(time <= Min){
            Min = time;
        }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(20);
    cout<<Min<<endl;

    return 0;
}
