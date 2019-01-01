// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, counter[MAX] = {0}, value;
    vector<int> arr;

    cin>>n;

    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>value;
        sum ^= value;
    }

    //cout<<sum<<endl;

    if(sum == 0){
        cout<<"Agasa"<<endl;
    }
    else{
        cout<<"Conan"<<endl;
    }

    return 0;
}
