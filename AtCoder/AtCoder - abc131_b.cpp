#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, l;

    cin>>n>>l;

    vector<int> arr;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        arr.push_back(l + i - 1);
        sum += l + i - 1;
    }

    int Min = 1e6, idx;
    for(int i = 0; i < arr.size(); i++){
        int temp = sum - arr[i];
        if(abs(sum - temp) < Min){
            Min = abs(sum- temp);
            idx = i;
        }
    }

    cout<<sum - arr[idx]<<endl;

    return  0;
}
