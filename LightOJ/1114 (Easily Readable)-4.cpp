#include <bits/stdc++.h>
#define MAX 120005
using namespace std;

int root, nodeNo;
int node[MAX][60], isWord[MAX];
char str1[150], str2[MAX];

void init()     //initialize root node
{
    root = 0;
    nodeNo = 0;

    for(int i = 0; i < 52; i++){
        node[root][i] = -1;
    }

    for(int i = 0; i < MAX; i++){
        isWord[i] = 0;
    }
}

void insertWord(char* str)
{
    int len = strlen(str), id;
    int current = root;     //copy root node

    //cout<<str<<endl;
    for(int i = 0; i < len; i++){
        if(str[i] > 'Z')
            id = str[i] - 'a' + 26;
        else
            id = str[i] - 'A';
        if(node[current][id] == -1){
            node[current][id] = ++nodeNo;
            for(int j = 0; j < 53; j++){
                node[nodeNo][j] = -1;
            }
        }
        current = node[current][id];
    }

    isWord[current]++;
    //cout<<current<<endl;
}

int searchWord(char* str)
{
    int len = strlen(str), id;
    int current = root;     //copy root node

    //cout<<str<<endl;
    for(int i = 0; i < len; i++){
        if(str[i] > 'Z')
            id = str[i] - 'a' + 26;
        else
            id = str[i] - 'A';
        if(node[current][id] == -1){
            return -1;
        }
        current = node[current][id];
    }

    return isWord[current];
}

int main()
{
	int test, caseNo = 1, n, q, result;
	char *temp;

	scanf("%d", &test);

	while(test--){
		scanf("%d", &n);
		gets(str1);

        init();
		for(int i = 0; i < n; i++){
			int len = strlen(gets(str1));
			if(len > 2){
				sort(str1 + 1, str1 + len - 1);
			}
			//cout<<str<<endl;
			insertWord(str1);
		}

        printf("Case %d:\n", caseNo++);
		scanf("%d", &q);
		gets(str1);

		for(int i = 0; i < q; i++){
            gets(str2);
            result = 1;
            temp = strtok(str2, " ");

            while(temp){
                int len = strlen(temp);
                if(len > 2)
                    sort(temp + 1, temp + len - 1);
                int k = searchWord(temp);
                if(k != -1)
                    result *= k;
                else{
                    result = 0;
                    break;
                }
                temp = strtok(0, " ");
            }

            printf("%d\n", result);
		}
	}

	return 0;
}
