#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int main()
{
    int test, caseno = 1, n, ans;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int val, cnt = 0, ans = 0;
        for(int i = 0; i < n; i++){
            cin>>val;
            ans ^= val;
            if(val == 1)
                cnt++;
        }

        if((ans == 0 && cnt != n) || (cnt == n && n % 2 == 1)){
            printf("Second\n");
        }
        else{
            printf("First\n");
        }
    }

    return 0;
}
