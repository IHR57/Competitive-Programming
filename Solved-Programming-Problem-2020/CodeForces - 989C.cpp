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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

char res[51][51];
int a, b, c, d;

void assignColor(int start, int End, char color)
{
    for(int i = start; i <= End; i++) {
        for(int j = 1; j <= 50; j++) {
            res[i][j] = color;
        }
    }
}

void reAssign(int start, int End, int checkedVal, char changedColor)
{
    for(int i = start; i <= End; i += 2) {
        for(int j = 1; j <= 50; j += 2) {
            if(checkedVal) {
                res[i][j] = changedColor;
                checkedVal--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>a>>b>>c>>d;

    a--, b--, c--, d--;
    assignColor(1, 12, 'C');
    assignColor(13, 25, 'D');
    assignColor(26, 38, 'A');
    assignColor(39, 50, 'B');


    reAssign(1, 12, a, 'A');
    reAssign(13, 25, b, 'B');
    reAssign(26, 38, c, 'C');
    reAssign(39, 50, d, 'D');

    cout<<50<<" "<<50<<endl;
    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= 50; j++) {
            cout<<res[i][j];
        }
        cout<<endl;
    }

    return 0;
}
