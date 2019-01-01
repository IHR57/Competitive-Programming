#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int a[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v, arr[20], temp[20];

    cin>>v;

    for(int i = 1; i <= 9; i++){
        cin>>arr[i];
        temp[i] = v / arr[i];
    }

    int idx;
    int Max = -1;

    for(int i = 1; i <= 9; i++){
        if(temp[i] > Max){
            Max = temp[i];
            idx = i;
        }
    }

    if(!Max)
        cout<<-1<<endl;
    else{
        for(int i = 1; i <= Max; i++)
            a[i] = idx;

        int cst = (Max * arr[idx]);

        for(int i = 1; i <= Max; i++){
            for(int j = 9; j > idx; j--){
                if(cst - arr[idx] + arr[j] <= v){
                    cst = cst - arr[idx] + arr[j];
                    a[i] = j;
                    break;
                }
            }
        }

        for(int i = 1; i <= Max; i++){
            cout<<a[i];
        }
        cout<<endl;
    }

    return 0;
}
