#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int counter[10] = {0}, n, u, v;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>u>>v;
        counter[u]++;
        counter[v]++;
    }

    bool flag = false;
    for(int i = 1; i <= 5; i++){
        if(counter[i] <= 1 || counter[i] >= 3){
            flag = true;
        }
    }

    (flag) ? cout<<"WIN"<<endl : cout<<"FAIL"<<endl;

    return 0;
}
