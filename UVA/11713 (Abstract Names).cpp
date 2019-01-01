#include <bits//stdc++.h>

int main()
{
    int test;
    char str1[30], str2[30];

    scanf("%d", &test);

    for(int i=1; i<=test; i++){
        scanf("%s", str1);
        scanf("%s", str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);

        int flag = 0;

        if(len1 == len2){
            for(int i=0; i<len1; i++){
                if(str1[i] == str2[i]){
                    flag = 1;
                }
                else if((str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u') &&
                        (str2[i]=='a' || str2[i]=='e' || str2[i]=='i' || str2[i]=='o' || str2[i]=='u')){
                        flag = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
