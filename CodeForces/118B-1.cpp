#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n + 1; i++){
        int value = 0;
        for(int j = (2 * (n - i + 1)) ; j >= 1; j--){
            cout<<" ";
        }
        for(int j = 1; j < 2 * i - 1; j++){
            cout<<value<<" ";
            if(j <= (2 * i - 1) / 2)
                value++;
            else
                value--;
        }
        cout<<value<<endl;
    }
    for(int i = 1; i <= n; i++){
        int value = 0;
        for(int j = 1; j <= (2 * i); j++){
            cout<<" ";
        }
        int temp = 2 * (n - i + 1) - 1;
        for(int j = 1; j < temp; j++){
            cout<<value<<" ";
            if(j <= temp / 2)
                value++;
            else
                value--;
        }
        cout<<value<<endl;
    }
}
