#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1005
using namespace std;

struct value
{
    int x, y;       //x = number of divisor ; y = number
};

bool compare(value A, value B)          //given condition in the problem statement
{
    if(A.x == B.x){             //if number of divisor are same
        return A.y > B.y;       //then the number which is greater will get priority
    }
    return A.x < B.x;
}

int main()
{
    value Rank[MAX];

    int count =  0;

    for(int i = 0; i < 1000; i++){      //number of divisor of number 1 to 1000
        for(int j = 1; j < i + 1; j++){
            if((i + 1) % j == 0){
                count++;
            }
        }
        Rank[i].x = count;
        Rank[i].y = i + 1;
        count = 0;
    }

    sort(Rank, Rank + 1000, compare);

    int test, cases = 1, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        printf("Case %d: %d\n", cases++, Rank[n-1].y);
    }

    return 0;
}
