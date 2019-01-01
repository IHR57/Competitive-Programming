#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int term1, term2, Final, attendance, ct[10];
    int test, cases = 1;
    double avg, sum;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d %d", &term1, &term2, &Final, &attendance);

        sum = (double) (term1 + term2 + Final + attendance);

        for(int i = 0; i < 3; i++){
            scanf("%d", &ct[i]);
        }

        sort(ct, ct+3);     //sorting for simplify

        //the average of best two class test marks
        avg = (double) (ct[1] + ct[2]) / 2.0;

        sum = sum + avg;

        printf("Case %d: ", cases++);
        if(sum >= 90)
            printf("A\n");
        else if(sum >= 80 && sum < 90)
            printf("B\n");
        else if(sum >= 70 && sum < 80)
            printf("C\n");
        else if(sum >= 60 && sum < 70)
            printf("D\n");
        else
            printf("F\n");
    }

    return 0;
}
