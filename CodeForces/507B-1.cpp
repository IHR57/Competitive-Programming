#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

double dis(int x1, int y1, int x2, int y2)
{
    return (double) sqrt((double) (x2 - x1) * (x2 - x1) + (double) (y2 - y1) * (y2 - y1));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r, x, y, xNew, yNew;

    cin>>r>>x>>y>>xNew>>yNew;

    double dist = dis(x, y, xNew, yNew);
    //cout<<dist<<endl;
    double result = (ceil) (dist / (2 * r));

    cout<<result<<endl;

    return 0;
}
