#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

double dist[MAX];
const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r, x[MAX];

    cin>>n>>r;

    for(int i = 0; i < n; i++){
        cin>>x[i];
    }

    cout<<setiosflags(ios::fixed)<<setprecision(8);
    cout<<(double) r<<" ";
    dist[0] = (double) r;

    for(int i = 1; i < n; i++){
        bool flag = false;
        int Min = inf, idx;
        for(int j = i - 1; j >= 0; j--){
            if(abs(x[i] - x[j]) <= 2 * r){
                int temp = abs(x[i] - x[j]);
                double t = dist[j] + sqrt((2 * r) * (2 * r) - (temp * temp));
                if(t > dist[i]){
                    dist[i] = t;
                }
                flag = true;
            }
        }
        if(!flag)
            dist[i] = (double) r;
        cout<<dist[i]<<" ";
    }

    cout<<endl;

    return 0;
}
