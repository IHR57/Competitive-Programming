//Problem ID: AtCoder - abc124_d (Handstand)
//Programmer: IQBAL HOSSAIN     Description: Constructive Algorithms
//Date: 13/05/19
//Problem Link: https://atcoder.jp/contests/abc124/tasks/abc124_d
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

string str, st;
int counter[MAX], pos[MAX], cs[MAX];

int main()
{
    int n, k;

    cin>>n>>k;
    cin>>str;

    char prev = str[0];
    st += str[0];
    int cnt = 1, idx = 0;
    for(int i = 1; i < n; i++){
        if(str[i] != prev){
            prev = str[i];
            counter[idx++] = cnt;
            st += str[i];
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    counter[idx++] = cnt;

    int c = 0;
    for(int i = 0; i < idx; i++){
        if(st[i] == '0'){
            pos[c++] = i;
        }
        cs[i+1] = cs[i] + counter[i];
    }

    if(k >= c){
        cout<<n<<endl;
        return 0;
    }

    int x = 0, y = k - 1, Max = 0;
    while(y < c){
        int res = cs[pos[y]+1] - cs[pos[x]];
        if(pos[x] - 1 >= 0)
            res += counter[pos[x]-1];
        if(pos[y] + 1 < idx)
            res += counter[pos[y]+1];
        if(res > Max)
            Max = res;
        x++, y++;
    }

    cout<<Max<<endl;

    return 0;
}
