#include <stdio.h>
#include <string.h>

void sortString(char* str)
{
    int len = strlen(str);
    char temp;

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            int a = str[i] - 48;
            int b = str[j] - 48;
            if(a < b){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    int test, cases = 1;
    char str1[110], str2[110], tempstr1[110], tempstr2[110];

    scanf("%d", &test);
    getchar();

    while(test--){
        gets(str1);
        gets(str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);

        int j = 0;
        for(int i = 0; i < len1; i++){
            if(str1[i] != ' '){
                tempstr1[j++] = str1[i];
            }
        }
        tempstr1[j++] = '\0';
        //printf("%s\n", tempstr1);

        j = 0;

        for(int i = 0; i < len2; i++){
            if(str2[i] != ' '){
                tempstr2[j++] = str2[i];
            }
        }

        tempstr2[j++] = '\0';
        //printf("%s\n", tempstr2);

        len1 = strlen(tempstr1);
        len2 = strlen(tempstr2);
        //printf("%d %d\n", len1, len2);

        int i;
        for(i = 0; i < len1; i++){
            if(tempstr1[i] >= 'a' && tempstr1[i] <= 'z')
                tempstr1[i] = 'A' + (tempstr1[i] - 'a');
        }
        tempstr1[i] = '\0';

        for(i = 0; i < len2; i++){
            if(tempstr2[i] >= 'a' && tempstr2[i] <= 'z')
                tempstr2[i] = 'A' + (tempstr2[i] - 'a');
        }
        tempstr2[i] = '\0';

        //printf("%s %s\n", tempstr1, tempstr2);

        sortString(tempstr1);
        sortString(tempstr2);

        if(strcmp(tempstr1, tempstr2) == 0){
            printf("Case %d: Yes\n", cases++);
        }
        else
            printf("Case %d: No\n", cases++);
    }

    return 0;
}
