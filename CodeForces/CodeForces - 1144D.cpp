//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int counter[MAX], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, idx, Max = -1;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        counter[arr[i]]++;
        if(counter[arr[i]] > Max){
            Max = counter[arr[i]];
            idx = i;
        }
    }

    int temp = arr[idx];


    cout<<(n - Max)<<endl;

    for(int i = idx - 1; i >= 0; i--){
        if(arr[i] != arr[i+1]){
            if(arr[i] < arr[i+1]){
                cout<<1<<" "<<(i + 1)<<" "<<(i + 1) + 1<<endl;
                arr[i] = arr[i+1];
            }
            else if(arr[i] > arr[i+1]){
                cout<<2<<" "<<(i + 1)<<" "<<(i + 1) + 1<<endl;
                arr[i] = arr[i+1];
            }
        }
    }
    for(int i = idx + 1; i < n; i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] < arr[i-1]){
                cout<<1<<" "<<i + 1<<" "<<(i - 1) + 1<<endl;
                arr[i] = arr[i-1];
            }
            else if(arr[i] > arr[i-1]){
                cout<<2<<" "<<i + 1<<" "<<(i - 1) + 1<<endl;
                arr[i] = arr[i-1];
            }
        }
    }

    return 0;
}

