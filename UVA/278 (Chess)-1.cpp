#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, ans, row, col;
    char str[10];

    scanf("%d", &test);

    while(test--){
        scanf("%s %d %d", str, &row, &col);
        if(str[0] == 'r' || str[0] == 'Q'){
            ans = min(row, col);
        }
        else if(str[0] == 'k'){
            ans = (((row + 1) / 2) * ((col + 1) / 2)) + ((row / 2) * (col / 2));
        }
        else if(str[0] == 'K'){
            ans = ((row + 1)/2) * ((col+1) / 2);
        }

        printf("%d\n", ans);
    }

    return 0;
}
