//Problem ID: LightOJ 1023 (Discovering Permutations)
//Programmer: IQBAL HOSSAIN     Description: Permutation (Backtracking)
//Date: 30-01-17
#include <bits//stdc++.h>
using namespace std;
int n;
int taken[30];
int position[30];
char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int counter, k;

void genPermutation(int idx)
{
    if(idx == n){
        for(int i = 0; i < n; i++){
            cout<<str[position[i]];
        }
        cout<<endl;
        counter++;
        return;
    }
    else
    {
        for(int i = 0; i < n; i++){
            if(counter == k)
                break;
            if(!taken[i]){
                taken[i] = 1;
                position[idx] = i;
                genPermutation(idx+1);
                taken[i] = 0;
            }
        }
    }
}

int main()
{
    int test, cases = 1;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d", &n, &k);
        memset(taken, 0, sizeof(taken));
        counter = 0;        //initialize  counter as zero
        printf("Case %d:\n", cases++);
        genPermutation(0);
    }

    return 0;

}
