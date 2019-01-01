#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000005];
    int n, i, j, cases = 1, k, temp, len, flag, m;

    while(gets(str)){
        scanf("%d", &n);
        len = strlen(str);

        printf("Case %d:\n", cases++);

        for(k=0; k<n; k++){
            scanf("%d %d", &i, &j);
            flag = 1;

            if(i==j){
                printf("Yes\n");
                continue;
            }

            if(i>j){
                for(m=j; m<=i; m++){
                    if(str[m]!=str[i]){
                        flag = 0;
                        printf("No\n");
                        break;
                    }
                }
            }
            else{
                for(m=i; m<=j; m++){
                    if(str[m]!=str[i]){
                        flag = 0;
                        printf("No\n");
                        break;
                    }
                }
            }
            if(flag)
                printf("Yes\n");
        }
        getchar();
    }

    return 0;
}
