//Problem ID: CodeForces - 1036D (Vasya and Arrays)
//Programmer: IQBAL HOSSAIN     Description: Greedy/Tow Pointers
//Date: 15/04/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;
int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    int i = 0, j = 0, cnt = 0;
    while(true){
        if((i >= n && j < m) || (i < n && j >= m)){
            cout<<-1<<endl;
            return 0;
        }
        if(a[i] == b[j]){
            cnt++;
            i++, j++;
        }
        else{
            ll sum1 = 0, sum2 = 0;
            sum1 += (ll) a[i];
            sum2 += (ll) b[j];
            while(true){
                if(sum1 == sum2){
                    cnt++;
                    i++, j++;
                    break;
                }
                else if(sum1 > sum2){
                    j++;
                    if(j >= m){
                        cout<<-1<<endl;
                        return 0;
                    }
                    sum2 += (ll) b[j];
                }
                else if(sum1 < sum2){
                    i++;
                    if(i >= n){
                        cout<<-1<<endl;
                        return 0;
                    }
                    sum1 += (ll) a[i];
                }
            }
        }
        if(i >= n && j >= m)
            break;
    }

    cout<<cnt<<endl;

    return 0;
}
