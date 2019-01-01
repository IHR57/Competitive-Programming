#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    char str1[MAX], str2[MAX];
    int counter1[30], counter2[30], counter3[30];

    while(scanf("%s %s", str1, str2) == 2){
        memset(counter1, 0, sizeof(counter1));
        memset(counter2, 0, sizeof(counter2));
        int len1 = strlen(str1), len2 = strlen(str2);

        for(int i = 0; i < len1; i++){
            counter1[str1[i] - 'a']++;
        }

        for(int i = 0; i < len2; i++){
            counter2[str2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            counter3[i] = min(counter1[i], counter2[i]);
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < counter3[i]; j++){
                printf("%c", i + 97);
            }
        }
        printf("\n");
    }

    return 0;
}
