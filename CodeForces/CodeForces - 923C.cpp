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
#define MAX 300005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int n, arr[MAX], p[MAX], res[MAX];

int node[9000005][2], cnt[9000005];
int root, nodeNo;

void init()     //initialize root node
{
    root = 0;
    nodeNo = 0;

    node[root][0] = node[root][1] = -1;
}

void insertWord(string str)
{
    int len = str.size(), id;
    int current = root;   

    cnt[current]++;

    for(int i = 0; i < len; i++){
        id = str[i] - '0';
        if(node[current][id] == -1){
            node[current][id] = ++nodeNo;
            node[nodeNo][0] = node[nodeNo][1] = -1;
        }
        current = node[current][id];
        cnt[current]++;
    }

}

ii searchWord(string str)
{
    int len = str.size(), id;
    int current = root;     

    int ans = 0, removedVal = 0;;
    for(int i = 0; i < len; i++){
        id = str[i] - '0';        
        if(node[current][id] == -1 || cnt[node[current][id]] <= 0){
            ans += (1<<(len - i - 1));
            id = !id;
        }
        removedVal += (id * (1<<(len - i - 1)));
        current = node[current][id];
    }

    return mk(ans, removedVal);
}

void deleteWord(string str) 
{
    int len = str.size(), id;
    int current = root;     

    cnt[current]--;
    for(int i = 0; i < len; i++){
        id = str[i] - '0';        
        current = node[current][id];
        cnt[current]--;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
 
    init();
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
 
    for(int i = 0; i < n; i++) {
        cin>>p[i];
        string str = "";
        for(int j = 29; j >= 0; j--) {
            (check(p[i], j)) ? str += "1" : str += "0";
        }
        insertWord(str);
    }
 
    for(int i = 0; i < n; i++) {
        string str = "";
        for(int j = 29; j >= 0; j--) {
            (check(arr[i], j)) ? str += "1" : str += "0";
        }
        ii temp = searchWord(str);
        res[i] = temp.ff;
        str = "";
        for(int j = 29; j >= 0; j--) {
            (check(temp.ss, j)) ? str += "1" : str += "0";
        }
        deleteWord(str);
    }
 
    for(int i = 0; i < n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
 
    return 0;
}