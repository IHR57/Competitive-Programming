#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int h;
    bool isPerfect = true;

    cin>>h;
    int cnt = 0;
    for(int i = 0; i <= h; i++){
        cin>>arr[i];
        if(i && arr[i-1] > 1 && arr[i] > 1){
            isPerfect = false;
        }
    }

    if(isPerfect){
        cout<<"perfect"<<endl;
        return 0;
    }

    cout<<"ambiguous"<<endl;

    cnt = 0;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j < arr[i]; j++){
            cout<<cnt<<" ";
        }
        cnt += arr[i];
    }

    cout<<endl;

    cnt = 0;
    bool flag = false;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j < arr[i]; j++){
            if(!flag && i > 0 && arr[i] > 1 && arr[i-1] > 1){
                cout<<cnt - 1<<" ";
                flag = true;
            }
            else{
                cout<<cnt<<" ";
            }
        }
        cnt += arr[i];
    }

    cout<<endl;

    return 0;
}
