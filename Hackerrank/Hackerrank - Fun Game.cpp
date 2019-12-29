//Problem ID: HackerRank - Fun Game
//Programmer: IQBAL HOSSAIN     Description: Greedy/Game
//Date: 10/05/19
//Problem Link: https://www.hackerrank.com/challenges/fun-game-1/problem
#include <bits/stdc++.h>
#define MAX 1005
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;

vector<pii> vp;
bool compare(pii A, pii B)
{
    return A.first < B.first;
}

int main()
{
    int test, n, a[MAX], b[MAX];
    scanf("%d", &test);

    set<pii> s1, s2;

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &b[i]);
        }
        for(int i = 0; i < n; i++){
            vp.push_back(mp(a[i] + b[i], i));
        }

        int sum1 = 0, sum2 = 0;
        sort(vp.begin(), vp.end(), compare);

        bool flag = true;
        for(int i = n - 1; i >= 0; i--){
            if(flag){
                sum1 += a[vp[i].second];
                flag = false;
            }
            else{
                sum2 += b[vp[i].second];
                flag = true;
            }
        }

        if(sum1 > sum2)
            printf("First\n");
        else if(sum2 > sum1)
            printf("Second\n");
        else
            printf("Tie\n");
        vp.clear();
    }

    return 0;
}
