#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int test, n, u, d, arr[MAX];

int jump(int idx)
{
    int cnt = 0;

    for(int i = idx + 1; i < n; i++){
        if(arr[i] < arr[idx])
            cnt++;
        else
            break;
    }

    return cnt;
}

int main()
{
    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &n, &u, &d);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        int Max = -1;
        for(int i = 0; i < n; i++){
            bool flag = true;
            int cnt = 0;
            if(i != 0){
                for(int j = 0; j < i; j++){
                    int diff = arr[j] - arr[j+1];
                    if(diff >= 0){
                        if(diff <= d)
                            cnt++;
                        else {flag = false; break;};
                    }
                    else{
                        diff = -diff;
                        if(diff <= u)
                            cnt++;
                        else {flag = false; break;};
                    }
                }
            }
            int temp = 0;
            if(flag){
                temp = jump(i);
                //cout<<temp<<endl;
                for(int j = i + temp + 1; j < n; j++){
                    int diff = arr[j-1] - arr[j];
                    if(diff >= 0){
                        if(diff <= d)
                            cnt++;
                        else break;
                    }
                    else{
                        diff = -diff;
                        if(diff <= u)
                            cnt++;
                        else break;
                    }
                }
            }
            Max = max(Max, cnt + temp);
        }

        printf("%d\n", Max + 1);
    }

    return 0;
}
