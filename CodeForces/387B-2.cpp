// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define debug (cout<<"I AM HERE:)"<<endl)
#define MAX 3005
using namespace std;

int a[MAX], b[MAX], mark[MAX] = {0};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    int cnt = 0;

    sort(a, a + n);
    sort(b, b + m);

    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < m; j++){
            if(!mark[j]){
                if(b[j] >= a[i]){
                    mark[j] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag)
            cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
