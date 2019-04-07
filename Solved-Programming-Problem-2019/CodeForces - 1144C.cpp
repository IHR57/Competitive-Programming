//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int arr[MAX], visited[MAX];
vector<int> v1, v2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int cnt = 1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] == arr[i+1]){
            cnt++;
            if(cnt >= 3){
                cout<<"NO"<<endl;
                return 0;
            }
            if(cnt == 2){
                v2.push_back(arr[i]);
                visited[i] = 1;
            }
        }
        else{
            cnt = 1;
        }
    }

    for(int i = 0; i < n ; i++){
        if(!visited[i]){
            v1.push_back(arr[i]);
        }
    }

    cout<<"YES"<<endl;
    cout<<v1.size()<<endl;
    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }

    cout<<endl;
    cout<<v2.size()<<endl;
    for(int i = 0; i < v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    return 0;
}

