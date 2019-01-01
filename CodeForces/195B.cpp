#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, basket;

    cin>>n>>m;

    if(m % 2 != 0){
        int mid = (m + 1) >> 1;
        int i = 0;
        for(int j = 0; j < n; j++){
            i = i % m;
            if(i == 0)
                basket = mid;
            else if(i % 2 != 0)
                basket = (mid - (i + 1) / 2);
            else
                basket = (mid + (i + 1) / 2);
            cout<<basket<<endl;
            i++;
        }
    }
    else{
        int mid = (m + 1) >> 1;
        int i = 0;
        for(int j = 0; j < n; j++){
            i = i % m;
            if(i == 0)
                basket = mid;
            else if(i % 2 != 0)
                basket = (mid + (i + 1) / 2);
            else
                basket = (mid - (i + 1) / 2);
            cout<<basket<<endl;
            i++;
        }
    }

    return 0;
}
