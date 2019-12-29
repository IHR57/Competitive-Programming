//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    string str;

    cin>>n>>str;

    int a = 0, b = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'a')
            a++;
        if(str[i] == 'b')
            b++;
        if(i & 1){
            if(a != b){
                cnt++;
                if(a > b){
                    str[i] = 'b';
                    a--;
                    b++;
                }
                else{
                    str[i] = 'a';
                    b--;
                    a++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    cout<<str<<endl;

    return 0;
}
