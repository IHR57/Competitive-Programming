#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int test, cases = 1, length, mark[105];
	char str[105];

	scanf("%d", &test);

	while(test--){
		scanf("%d", &length);
		scanf("%s", str);

		for(int i = 0; i < length; i++)
			mark[i] = 0;

		int count = 0;

		for(int i = 0; i < length; i++){
			if(str[i] == '.' && !mark[i]){
                if(i + 1 < length)
                    mark[i+1] = 1;
                if(i + 2 < length)
                    mark[i+2] = 1;
                count++;
			}
		}

		printf("Case %d: %d\n", cases++, count);
	}

	return 0;
}
