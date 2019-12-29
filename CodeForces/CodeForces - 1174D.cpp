#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int mark[(1<<19)];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;

    cin>>n>>x;

    mark[0] = 1;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i < (1 << n); i++){
        int temp = i ^ x;
        if(!mark[i] && !mark[temp]){
            v.push_back(i);
        }
        mark[temp] = mark[i] = 1;
    }

    cout<<v.size() - 1<<endl;
    for(int i = 1; i < v.size(); i++){
        cout<<(v[i] ^ v[i-1])<<" ";
    }
    cout<<endl;

    return 0;
}
