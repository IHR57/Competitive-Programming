//Problem ID: CodeForces - 620C (Pearls in Row)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 06/04/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

int arr[MAX], idx[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    set<int> s;

    cin>>n;

    int k = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(s.count(arr[i]) == 0){
            s.insert(arr[i]);
        }
        else{
            idx[k++] = i + 1;
            s.clear();
        }
    }

    if(k == 0){
        cout<<-1<<endl;
        return 0;
    }
    idx[k-1] = n;
    cout<<k<<endl;
    cout<<"1"<<" "<<idx[0]<<endl;
    for(int i = 0; i < k - 1; i++){
        cout<<idx[i] + 1<<" "<<idx[i+1]<<endl;
    }

    return 0;
}
