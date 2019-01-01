#include <stdio.h>
#include <string.h>

int main()
{
    char number[100], store[100];/*declaration of number and store*/
    int T, i, length, k=1, j;/*k for counting case number*/

    scanf("%d", &T);
    while(T--){
        scanf("%s", number);
        length=strlen(number);
        for(i=length-1, j=0; i>=0; i--){
            store[j]=number[i];/*store the last value of number as first value of store*/
            j++;
        }
        store[j]='\0';/*assign null character at the end of store*/
        if(strcmp(number, store)==0){
            printf("Case %d: Yes\n", k);
        }
        else
            printf("Case %d: No\n", k);
        k++;
    }

    return 0;

}
