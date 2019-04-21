#include <bits/stdc++.h>
#define MAX 400005
#define MOD 1000000007
#define pb push_back
using namespace std;

vector<int> v;
int dp[2][505];
int temp[100005], counter[MAX];

bool isPrime(int n)
{
    if(n == 0 || n == 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int cnt = 0;

    memset(temp, -1, sizeof(temp));

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int sum = (i + j + k);
                if(isPrime(sum)){
                    int res = i * 100 + j * 10 + k;
                    if(res >= 100 && res < 1000)
                        counter[3]++;
                    for(int l =  0; l < 10; l++){
                        if(isPrime(j+k+l) && isPrime(i+j+k+l)){
                            res = i * 1000 + j * 100 + k * 10 + l;
                            if(res >= 1000 && res < 10000)
                                counter[4]++;
                            for(int m = 0; m < 10; m++){
                                if(isPrime(k+l+m) && isPrime(j+k+l+m) && isPrime(i+j+k+l+m)){
                                    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
                                    int t = (i * 10000) + (j * 1000) + (k * 100) + (l * 10) + m;
                                    //cout<<t<<endl;
                                    v.pb(t);
                                    temp[t] = cnt;
                                    if(t >= 10000 && t < 100000)
                                        dp[1][cnt] = 1;
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //cout<<cnt<<endl;

    for(int i = 5; i < MAX; i++){
        int s = i & 1, t = !s;
        memset(dp[t], 0, sizeof(dp[t]));
        for(int j = 0; j < cnt; j++){
            int x = dp[s][j];
            if(x == 0)
                continue;
            counter[i] = (counter[i] + x) % MOD;
            for(int k = 0; k < 10; k++){
                int tt = (v[j] * 10 + k) % 100000;
                int id = temp[tt];
                if(id != -1){
                    dp[t][id] = (dp[t][id] + x) % MOD;
                }
            }
        }
    }
    counter[1] = 9, counter[2] = 90;
    //cout<<cnt<<endl;

    int n, test;

    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);
        printf("%d\n", counter[n]);
    }
    return 0;
}
