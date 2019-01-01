#include <stdio.h>
#include <algorithm>
#include <math.h>

int main()
{
    int test, row, col, cases = 1, ans;

    while(scanf("%d %d", &row, &col) == 2){
        if(row == 0 && col == 0)
            break;

        if(row == 1 || col == 1){       //special case
            ans = row * col;
        }
        else if((row % 2 != 0 && col % 2 != 0) || (row % 2 == 0 && col % 2 != 0)){
            ans = row * ((col+1) / 2) - (row / 2);      //formula
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
            if(col == 2)        //special case for 2
                ans = ans + 1;
        }


        printf("%d knights may be placed on a %d row %d column board.\n", ans, row, col);
    }

    return 0;
}
