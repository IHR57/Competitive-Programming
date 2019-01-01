#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    cout<<min(n, m) + 1<<endl;

    int temp = min(n, m) + 1;

    int k = 0;
    for(int i = 1; i <= temp; i++){
        cout<<temp - i<<" "<<k++<<endl;
    }

    return 0;
}
