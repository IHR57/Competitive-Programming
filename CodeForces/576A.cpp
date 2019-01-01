#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    vector<int> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = 0;

    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> ans;

    for(int i = 1; i <= n; i++){
        if(is_prime[i]){
            int temp = 1;
            while(temp <= n/i){
                temp *= i;
                ans.push_back(temp);
            }
        }
    }

    cout<<ans.size()<<endl;

    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
