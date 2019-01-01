#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

vector<int> v;
vector<int> temp;
vector<int> mat[5000];
int arr[20], t, n, idx = 0;

void genSub(int k)
{
    if(k == n + 1){
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }
        if(sum == t){
            vector<int> vi;
            int flag = 1;
            vi = v;
            sort(vi.begin(), vi.end());     //we have to print the result in decreasing order
            for(int i = 1; i < idx; i++){
                if(vi == mat[i])
                    flag = 0;
            }
            if(flag){     ///this line has a problem need to work
                for(int i = 0; i < vi.size(); i++){
                    mat[idx].push_back(vi[i]);
                }
                idx++;
            }
            temp = vi;
        }
        return;
    }

    genSub(k + 1);
    v.push_back(arr[k]);
    genSub(k + 1);
    v.pop_back();
}

int main()
{
    while(scanf("%d %d", &t, &n) == 2){
        if(n == 0)
            break;
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }

        printf("Sums of %d:\n", t);
        idx = 1;
        genSub(1);      //generating all subset and calculating result

        if(mat[1].size() == 0)
            printf("NONE\n");
        else{
            for(int i = idx -1; i >= 1; i--){
                for(int j = mat[i].size() - 1; j > 0; j--){
                    printf("%d+", mat[i][j]);
                }
                printf("%d\n", mat[i][0]);
            }
        }
        for(int i = 0; i < idx; i++)
            mat[i].clear();
        temp.clear();
        v.clear();
    }

    return 0;
}
