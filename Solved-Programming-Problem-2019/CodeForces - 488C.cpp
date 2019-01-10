//Problem ID: CodeForces - 488C (Fight the Monster)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 10/01/19
#include <bits/stdc++.h>
#define MAX 205
using namespace std;

const int inf = 1<<28;
int ans;
int hpM, hpY, atkM, atkY, defM, defY;
int hp_cost, atk_cost, def_cost;

bool check(int a, int b, int c)
{
    int x = hpM, y = atkM, z = defM;
    if(a > 0 && x <= 0){
        return true;
    }
    if(a < 0)
        return false;
    if(b <= z)
        return false;
    if(y <= c)
        return true;
    int temp1 = (a + ((y - c) - 1)) / (y - c);
    int temp2 = (x + ((b - z) - 1)) / (b - z);

    if(temp1 > temp2)
        return true;
    return false;
}

int main()
{
    scanf("%d %d %d", &hpY, &atkY, &defY);
    scanf("%d %d %d", &hpM, &atkM, &defM);
    scanf("%d %d %d", &hp_cost, &atk_cost, &def_cost);

    ans = inf;

    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= MAX; j++){
            for(int k = 0; k <= MAX; k++){
                if(check(hpY+i, atkY+j, defY+k)){
                    int cost = (i * hp_cost) + (j * atk_cost) + (k * def_cost);
                    ans = min(ans, cost);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
