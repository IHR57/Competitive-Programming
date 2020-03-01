//Date: 05/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, n, x;
    string str;

    cin>>test;

    while(test--){
        cin>>n>>x;
        cin>>str;
        int len = str.size();
        str += str;
        int res = 0;
        for(int i = 0; i < 2 * len; i++){
            (str[i] == '0') ? res++ : res--;
            if(i < len)
                arr[i][0] = res;
            else
                arr[i-len][1] = res;
        }

        bool isInfinite = false;
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(arr[i][0] == arr[i][1] && arr[i][0] == x){
                isInfinite = true;
                break;
            }
            int diff = arr[i][1] - arr[i][0];
            if((diff > 0 && x >= arr[i][0]) || (diff < 0 && x <= arr[i][0])){
                int tx = (x - arr[i][0]);
                if(abs(tx) % abs(diff) == 0){
                    cnt++;
                }
            }
        }
        if(x == 0)
            cnt++;

        (isInfinite) ? cout<<-1<<endl : cout<<cnt<<endl;

    }

    return 0;
}