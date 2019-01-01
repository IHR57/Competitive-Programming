//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
	int s[2500], d[2500], n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
        scanf("%d %d", &s[i], &d[i]);
	}

	int last = 0;
	for(int i = 0; i < n; i++){
        for(int k = 0; k <= 1000000; k++){
            int j = s[i] + k * d[i];
            //cout<<j<<endl;
            if(j > last){
                last = j;
                //cout<<last<<endl;
                break;
            }
        }
	}

	printf("%d\n", last);

	return 0;
}
