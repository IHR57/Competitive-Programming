//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 400005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int ans = 0;

    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < n; j++) {
            b[j] = arr[j] & ((1<<(i + 1)) - 1);
        }

        sort(b, b + n);
        int t = 1<<i;

        int cnt = 0, x = 0, y = 0, z = 0;
        for(int j = n - 1; j >= 0; j--) {
            while(x < n && b[x] + b[j] < t)
                x++;
            while(y < n && b[y] + b[j] < (2 * t))
                y++;
            while(z < n && b[z] + b[j] < (3 * t))
                z++;
            cnt += max(0, min(j, y) - x);
            cnt += max(0, j - z);
        }
        if(cnt & 1)
            ans |= t;
    }

    cout<<ans<<endl;

    return 0;
}

