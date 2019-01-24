//Problem ID: CodeChef - ADAPWNS (Ada Pawns)
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 21/01/19
//Problem Link: https://www.codechef.com/problems/ADAPWNS
#include <bits/stdc++.h>
#define MAX 150
using namespace std;

int main()
{
    int  g[MAX], test;
    vector<int> arr;
    char str[MAX];

    scanf("%d",  &test);


//    g[0] = 0, g[1] = 1;       //calculating Grundy number
//    for(int i = 2; i <= 128; i++){
//        int x1 = g[i-1];
//        int x2 = g[i-2];
//
//        for(int j = 0; j <= 300; j++){
//            if(j != x1 && j != x2){
//                g[i] = j;
//                break;
//            }
//        }
//    }

    while(test--){

        scanf("%s", str);

        int len = strlen(str);

        arr.clear();
        int cnt = 0, k = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == '.'){
                cnt++;
            }
            if(str[i] == 'P'){
                arr.push_back(cnt);
                cnt = 0;
            }
        }

        reverse(arr.begin(), arr.end());

        int ans = 0;
        for(int i = 0; i < arr.size(); i += 2){     //we need to check only even indices
            ans ^= arr[i] % 3;
        }

        if(ans > 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
