#include <bits/stdc++.h>
#define MAX 300005
#define BLOCK_SIZE 550
#define MOD 1000000007
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, int> pii;
pii query[MAX];

int arr[MAX], tarr[MAX], ans[BLOCK_SIZE+5][BLOCK_SIZE+5], BS, cnt[BLOCK_SIZE+5][MAX];
ll fact[MAX], inv[MAX];
int n, q, counter[MAX];
map<int, int> mp;

ll bigMod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1){
            res = (res * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

int getID(int pos)
{
    int idx = pos / BS;
    if(pos % BS != 0)
        idx++;
    return idx;
}


void preCal()
{
    int idx, res;
    for(int i = 0; i < n; i++){
        counter[arr[i]]++;
        if(i % BS == 0){
            idx = i / BS;
            for(int j = 0; j < n; j++){
                cnt[idx][j] = counter[j];
            }
        }
    }

    idx = getID(n - 1);
    for(int i = 0; i < n; i++)
        cnt[idx][i] = counter[i];
    memset(counter, 0, sizeof(counter));

    for(int i = 0; i < n; i += BS){
        idx = i / BS;
        res = 1;
        for(int j = i; j < n; j++){
            res = (res * fact[counter[arr[j]]]) % MOD;
            counter[arr[j]]++;
            res = (res * inv[counter[arr[j]]]) % MOD;
            if(j % BS == 0){
                ans[idx][j/BS] = res % MOD;
            }
        }
        ans[idx][getID(n-1)] = res % MOD;
        memset(counter, 0, sizeof(counter));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int x = 1;
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
        inv[i] = (inv[i-1] * bigMod(i, MOD - 2)) % MOD;
    }
    int l1, l2, r1, r2, L, R;

    scanf("%d %d", &n, &q);
    BS = sqrt(n) + 5;
    int idx = 1;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(mp[arr[i]] == 0){
            mp[arr[i]] = idx++;
        }
        arr[i] = mp[arr[i]] - 1;
        //counter[idx]++;
    }

    preCal();

    ll prev = 0;
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &l1, &l2, &r1, &r2);
        ll l = ((l1 * prev) % n + l2) % n;
        ll r = ((r1 * prev) % n + r2) % n;
        if(l > r)
            swap(l, r);
        L = l / BS;
        R = getID(r);
        l1 = min(n - 1, L * BS);
        r1 = min(n - 1, R * BS);
        ll res = (ll) ans[L][R];
        int k = 0;
        for(int j = l1; j < l; j++){
            counter[arr[j]]++;
            if(counter[arr[j]] == 1){
                tarr[k++] = arr[j];
            }
        }
        for(int j = r1; j > r; j--){
            counter[arr[j]]++;
            if(counter[arr[j]] == 1){
                tarr[k++] = arr[j];
            }
        }

        for(int j = 0; j < k; j++){
            int temp = tarr[j];
            int tot = cnt[R][temp] - cnt[L][temp] + (arr[l1] == temp);
            res = (res * fact[tot]) % MOD;
            tot -= counter[temp];
            res = (res * inv[tot]) % MOD;
            counter[temp] = 0;
        }
        res = (res * fact[r - l + 1]) % MOD;
        printf("%lld\n", res % MOD);
        prev = res % MOD;
    }

    

    return 0;
}