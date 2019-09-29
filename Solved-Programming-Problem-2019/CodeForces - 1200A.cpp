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

int arr[10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    set<int> s1, s2;
    for(int i = 0; i < 10; i++){
        s1.insert(i);
        s2.insert(10-i-1);
    }

    string str;

    cin>>str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'L'){
            int t = *s1.begin();
            arr[t] = 1;
            s1.erase(t);
            s2.erase(t);
        }
        else if(str[i] == 'R'){
            int t = *s2.rbegin();
            arr[t] = 1;
            s1.erase(t);
            s2.erase(t);
        }
        else{
            int t = str[i] - 48;
            s1.insert(t);
            s2.insert(t);
            arr[t] = 0;
        }
    }

    for(int i = 0; i < 10; i++)
        cout<<arr[i];
    cout<<endl;

    return 0;
}
