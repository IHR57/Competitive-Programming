// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int st1, st2, en1, en2, n, m;
    char str[MAX];

    cin>>n>>m;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < m; j++){
            if(str[j] == 'B'){
                cnt++;
                if(cnt == 1)
                    st1 = i, st2 = j;
                en1 = i, en2 = j;
            }
        }
    }

    if(cnt == 1){
        cout<<st1+1<<" "<<st2+1<<endl;
        return 0;
    }
    else{
        int temp = (int) sqrt(cnt) + 1;
        temp = (temp - 1) / 2;
        cout<<st1 + temp + 1<<" "<<en2 - temp + 1<<endl;
    }

    return 0;
}
