#include <bits//stdc++.h>
#define MAX 100005
using namespace std;

int sequence[MAX];
int L[MAX], lisSequence[MAX];

int LIS(int length)
{
    for(int i = 0; i < length; i++)
        L[i] = 1;       //initialize

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(sequence[j] > sequence[i]){      //if right element is greater than left
                L[j] = max(L[j] , L[i] + 1);
            }
        }
    }

    int maxLength = 0;
    for(int i = 0; i < length; i++){
        if(L[i] > maxLength)
            maxLength = L[i];
    }

    return maxLength;
}

void findSequence(int maxLength, int n)
{
    int i = 0;
    for(int j = 1; j < n; j++){
        if(L[j] > L[i])
            i = j;      //finding the index of maximum element
    }

    int top = L[i] - 1;     //0 based index
    lisSequence[top] = sequence[i];
    top--;

    for(int j = i - 1; j >= 0; j--){
        if(sequence[j] < sequence[i] && L[j] == L[i] - 1){
            i = j;
            lisSequence[top] = sequence[i];
            top--;
        }
    }

    for(i = 0; i < maxLength; i++)
        printf("%d\n", lisSequence[i]);
}

int main()
{
    int test, flag = 0;
    char str[50];

    scanf("%d", &test);
    getchar();

    gets(str);

    while(test--){
        int index = 0;      //set index 0
        while(gets(str) && strlen(str)){
            sequence[index++] = atoi(str);
        }
        if(flag)
            printf("\n");
        flag = 1;

        int maxLength = LIS(index);      //maximum length of increasing subsequence
        printf("Max hits: %d\n", maxLength);

        findSequence(maxLength, index);        //printing the sequence
    }

    return 0;
}
