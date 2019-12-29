//Problem ID: CodeForces - 770A (New Password)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 25/03/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int used[MAX];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int distinct = 2;
    used[0] = 1, used[1] = 2;

    for(int i = 2; i < n; i++){
        if(distinct == k){
            for(int j = 0; j < i - 1; j++){
                if(used[j] > 0 && used[j] !=  used[i-1]){
                    used[i] = used[j];
                    break;
                }
            }
        }
        else{
            used[i] = ++distinct;
        }
    }
    for(int i = 0; i < n; i++){
        //cout<<used[i]<<endl;
        printf("%c", used[i] + 96);
    }
    printf("\n");

    return 0;
}
