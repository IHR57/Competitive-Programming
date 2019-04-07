//Problem ID: CodeForces - 643A (Bear and Colours)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 01/04/19
#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int counter[MAX], cnt[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        int Max = -1, idx = -1;
        memset(counter, 0, sizeof(counter));
        for(int j = i; j < n; j++){
            int t = ++counter[arr[j]];
            if(t > Max){
                Max = t;
                idx = j;
            }
            else if(t == Max){
                if(arr[j] < arr[idx]){
                    idx = j;
                }
            }
            cnt[arr[idx]]++;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;

    return 0;
}
