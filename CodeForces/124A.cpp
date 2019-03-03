#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n>>a>>b;

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        int Front = n - i;
        int rear = (n - Front - 1);
        if(Front >= a && rear <= b)
            cnt++;
        else
            break;
    }

    cout<<cnt<<endl;

    return 0;
}
