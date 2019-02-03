#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;
    int res = (n * (n - 1)) / 2;

    if(k >= res){
        cout<<"no solution"<<endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout<<1<<" "<<i<<endl;
        }
    }

    return 0;

}
