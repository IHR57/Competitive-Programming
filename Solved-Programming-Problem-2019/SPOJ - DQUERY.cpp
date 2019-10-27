//Date: 08/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

const int Block = 555;
int arr[MAX], cnt[MAX], ans = 0, res[MAX];

struct node
{
    int L, R, idx;
}query[MAX];


bool compare(node A, node B)
{
    if(A.L / Block != B.L / Block)
        return (A.L / Block) < (B.L / Block);
    return A.R < B.R;
}

void add(int pos)
{
    cnt[arr[pos]]++;
    if(cnt[arr[pos]] == 1){
        ans++;
    }
}

void remove(int pos)
{
    cnt[arr[pos]]--;
    if(cnt[arr[pos]] == 0)
        ans--;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d",  &arr[i]);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &query[i].L, &query[i].R);
        query[i].L--, query[i].R--;
        query[i].idx = i;
    }

    sort(query, query + m, compare);

    int currentL = 0, currentR = 0;
    for(int i = 0; i < m; i++){
        int L = query[i].L, R = query[i].R;
        while(currentL < L){
            remove(currentL);
            currentL++;
        }
        while(currentL > L){
            add(currentL - 1);
            currentL--;
        }
        while(currentR <= R){
            add(currentR);
            currentR++;
        }
        while(currentR > R + 1){
            remove(currentR - 1);
            currentR--;
        }
        res[query[i].idx] = ans;
    }

    for(int i = 0; i < m; i++){
        printf("%d\n", res[i]);
    }

    return 0;
}