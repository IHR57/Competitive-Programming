// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> v;
int visit[MAX] = {0};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int p, q, l, r;

    cin>>p>>q>>l>>r;

    int a, b;
    for(int i = 0; i < p; i++){
        cin>>a>>b;
        for(int j = a; j <= b; j++){
            visit[j] = 1;
        }
    }

    for(int i = 0; i < q; i++){
        cin>>a>>b;
        for(int j = a; j <= b; j++){
            v.push_back(j);
        }
    }

    int sum = 0;

    for(int i = l; i <= r; i++){
        bool flag = false;
        for(int j = 0; j < v.size(); j++){
            if(i + v[j] > 1000)
                break;
            if(visit[i + v[j]]){
                flag = true;
                break;
            }
        }
        if(flag)
            sum++;
    }

    cout<<sum<<endl;

    return 0;
}
