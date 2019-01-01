#include <stdio.h>
#include <algorithm>
#include <math.h>

int main()
{
    int test, row, col, cases = 1, ans;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);

        if(row == 1 || col == 1){
            ans = row * col;
        }
        else if((row % 2 != 0 && col % 2 != 0) || (row % 2 == 0 && col % 2 != 0)){
            ans = row * ((col+1) / 2) - (row / 2);
            if(row == 2)
                ans = ans + 1;
        }
        else if(row % 2 == 0 && col % 2 == 0){
            ans = row * (col / 2);
            if((row == 2 && col % 4 != 0) || (col == 2 && row % 4 != 0))
                ans = ans + 2;
        }
        else if(row % 2 != 0 && col % 2 == 0){
            ans = row * (col / 2);
            if(col == 2)
                ans = ans + 1;
        }


        printf("Case %d: %d\n", cases++, ans);
    }

    return 0;
}
