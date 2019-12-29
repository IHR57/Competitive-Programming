//Problem ID: LightOJ - 1396 (Palindromic Numbers III)
//Programmer: IQBAL HOSSAIN 	Description: Greedy
//Date: 20/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

char str[MAX], st[MAX];
int fg;

void Print(char s[])
{
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		printf("%c", s[i]);
	}
	printf("\n");
}

void compute()
{
	int len = strlen(st);
	int n = (len - 1) / 2;
	int j = n, k = len - n - 1;
	while(true){
		if(j < 0 || k >= len)
			break;
		if(st[j] == st[k]){
			j--, k++;
		}
		else
			break;
	}
	if(j < 0){
		j = n, k = len - n - 1;
		if(len % 2){
			int temp = (st[n] - 48) + 1;
			if(temp >= 10){
				fg = 1;
				st[len] = '\0';
				return;
			}
			st[n] = (temp + 48);
		}
		else{
			int temp = (st[n] - 48) + 1;
			if(temp >= 10){
				fg = 1;
				st[len] = '\0';
				return;
			}
			st[n] = (temp + 48);
			st[n+1] = (temp + 48);
		}
	}
	else{
		if((st[j] - 48) > (st[k] - 48)){
			st[k] = st[j];
			j--, k++;
		}
		else{
			if(len % 2){
				int temp = (st[n] - 48) + 1;
				if(temp >= 10){
					fg = 1;
					st[len] = '\0';
					return;
				}
				st[n] = (temp + 48);
			}
			else{
				int temp = (st[n] - 48) + 1;
				if(temp >= 10){
					fg = 1;
					st[len] = '\0';
					return;
				}
				st[n] = (temp + 48);
				st[n+1] = (temp + 48);
			}
		}
		while(j >= 0){
			st[k] = st[j];
			j--, k++;
		}

	}
	st[len] = '\0';
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test, caseno = 1;

	scanf("%d",  &test);

	while(test--){
		scanf("%s", str);
		int len = strlen(str);
		int n = (len - 1) >> 1;
		int j = n, k = len - n - 1;
		while(true){
			if(j < 0 || k >= len)
				break;
			if(str[j] == '9' && str[k] == '9'){
				j--, k++;
			}
			else
				break;
		}
		printf("Case %d: ", caseno++);
		int flag = 0;

		strcpy(st, str);
		if(j < 0){
			printf("1");
			for(int i = 0; i < len - 1; i++)
				printf("0");
			printf("1\n");
			continue;
		}
		else if(j != n){
			if((str[j]-48) <= (str[k]-48)){
				for(int i = j + 1; i < k; i++){
					str[i] = '0';
				}
				int temp = (str[j] - 48) + 1;
				str[j] = temp + 48;
				str[k] = temp + 48;
				j--, k++;
			}
			else{
				int temp = str[j] - 48;
				str[j] = temp + 48;
				str[k] = temp + 48;
				j--, k++;
			}
			while(j >= 0){
				str[k] = str[j];
				j--, k++;
			}
			flag = 1;
		}
		st[len] = '\0';
		fg = 0;
		compute();
		if(fg == 1){
			Print(str);
		}
		else if(flag){
			if(strcmp(str, st) < 0)
				Print(str);
			else
				Print(st);
		}
		else{
			Print(st);
		}
	}

	return 0;
}