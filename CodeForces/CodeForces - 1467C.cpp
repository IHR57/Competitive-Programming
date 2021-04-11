//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 300005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX][3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n1, n2, n3;

    cin>>n1>>n2>>n3;

    ll min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    ll sum1 = 0, sum2 = 0, sum3 = 0;

    for(int i = 0; i < n1; i++) {
        cin>>arr[i][0];
        sum1 += arr[i][0];
        min1 = min(min1, (ll) arr[i][0]);
    }
    for(int i = 0; i < n2; i++) {
        cin>>arr[i][1];
        sum2 += arr[i][1];
        min2 = min(min2, (ll) arr[i][1]);
    }
    for(int i = 0; i < n3; i++) {
        cin>>arr[i][2];
        sum3 += arr[i][2];
        min3 = min(min3, (ll) arr[i][2]);
    }

    ll ans = 0;
    ll minx = min((sum1 - min1), min(min2, min3));
    ans = ((sum2 - min2) + (sum3 - min3) - min1) + (sum1 - min1) + min2 + min3 - (2 * minx);
    minx =  min((sum2 - min2), min(min1, min3));
    ans = max(ans, ((sum1 - min1) + (sum3 - min3) - min2) + (sum2 - min2) + min1 + min3 - (2 * minx));
    minx =  min((sum3 - min3), min(min1, min2));
    ans = max(ans, ((sum1 - min1) + (sum2 - min2) - min3) + (sum3 - min3) + min1 + min2 - (2 * minx));

    cout<<ans<<endl;

    return 0;
}
