#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k[MAX], f[MAX];

    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>k[i]>>f[i];
    }

    bool flag;
    int ans = -1, t;

    for(int i = 1; i <= 100; i++){
        flag = true;
        for(int j = 1; j <= m; j++){
            int temp = k[j] / i;
            if(k[j] % i != 0)
                temp++;
            if(f[j] != temp){
                flag = false;
            }
        }

        if(flag){
            if(ans == -1){
                t = n / i;
                if(n % i != 0)
                    t++;
                ans = t;
            }
            else{
                t = n / i;
                if(n % i != 0)
                    t++;
                if(ans != t){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }

    (ans == -1) ? cout<<"-1"<<endl : cout<<ans<<endl;

    return 0;
}
