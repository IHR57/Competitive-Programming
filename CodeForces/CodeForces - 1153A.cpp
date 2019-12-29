//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, Min = 10000000;
    int s, d, idx;

    cin>>n>>t;

    for(int i = 0; i < n; i++){
        cin>>s>>d;
        for(int j = s; ; j += d){
            if(j >= t){
                int temp = (j - t);
                if(temp < Min){
                    Min = temp;
                    idx = i + 1;
                }
                break;
            }
        }
    }

    cout<<idx<<endl;

    return 0;
}
