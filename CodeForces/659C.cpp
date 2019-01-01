#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, arr[MAX];
    vector<int> temp;

    cin>>n>>m;

    for(int i =  0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int sum = 0;

    for(int i = 1; ; i++){
        if(!binary_search(arr, arr + n, i)){
            sum += i;
            if(sum > m)
                break;
            temp.push_back(i);
        }
    }

    cout<<temp.size()<<endl;

    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return 0;
}
