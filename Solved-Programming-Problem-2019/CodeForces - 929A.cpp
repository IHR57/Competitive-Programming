//Problem ID: CodeForces - 929A (Bicycle Rental)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 30/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    int flag = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(i){
            if(arr[i] - arr[i-1] > k){
                flag = 1;
            }
        }
    }

    if(flag){
        cout<<-1<<endl;
        return 0;
    }

    int temp = k, cnt = 1;
    for(int i = 0; i < n - 1; i++){
        if(arr[i+1] - arr[i] <= temp){
            temp -= (arr[i+1] - arr[i]);
        }
        else{
            cnt++;
            temp = k;
            temp -= (arr[i+1] - arr[i]);
        }
    }

    cout<<cnt<<endl;

    return 0;
}
