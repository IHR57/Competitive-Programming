//Problem ID: CodeForces - 926C (Is this a Zebra)
//Programmer: IQBAL HOSSAIN     Description: Implementation/Greedy
//Date: 05/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int flag = 0, n, Max = 0, cnt = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(!i && arr[i] == 1){
            flag = 1;
        }
        if(flag)
            arr[i] = 1 - arr[i];
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 0)
            Max++;
        else
            break;
    }

    for(int i = 0; i < n; ){
        if(arr[i] == 0){
            cnt = 0;
            while(arr[i] == 0 && i < n){
                cnt++;
                i++;
            }
            if(cnt != Max){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else if(arr[i] == 1){
            cnt = 0;
            while(arr[i] == 1 && i < n){
                cnt++;
                i++;
            }
            if(cnt != Max){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
