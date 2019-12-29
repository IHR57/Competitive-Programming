//Problem ID: LightOJ - 1198 (Karate Competition)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 14/02/19
#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int main()
{
	int test, caseno = 1, n, val, ans;
	int visited1[MAX], visited2[MAX];
	vector<int> sa, sb;

	scanf("%d",  &test);

	while(test--){
		scanf("%d", &n);

        ans = 0;
        sa.clear(); sb.clear();
		for(int i = 0; i < n; i++){
			scanf("%d", &val);
			sa.push_back(val);
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &val);
			sb.push_back(val);
		}

		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());

        while(true){
            memset(visited1, 0, sizeof(visited1));
            memset(visited2, 0, sizeof(visited2));
            int flag = 0;
            for(int i = 0; i < sa.size(); i++){
                for(int j = sb.size() - 1; j >= 0; j--){
                    if(!visited2[j]){
                        if(sa[i] > sb[j]){
                            visited1[i] = visited2[j] = 1;
                            flag = 1;
                            ans += 2;
                            break;
                        }
                    }
                }
            }
            vector<int> ta, tb;
            for(int i = 0; i < sa.size(); i++){
                if(!visited1[i]){
                    ta.push_back(sa[i]);
                }
            }
            for(int i = 0; i < sb.size(); i++){
                if(!visited2[i]){
                    tb.push_back(sb[i]);
                }
            }
            sa.clear();
            sb.clear();
            sa = ta; sb = tb;
            if(!flag)
                break;
        }

        while(true){
            memset(visited1, 0, sizeof(visited1));
            memset(visited2, 0, sizeof(visited2));
            int flag = 0;
            for(int i = 0; i < sa.size(); i++){
                for(int j = 0; j < sb.size(); j++){
                    if(!visited2[j]){
                        if(sa[i] == sb[j]){
                            visited1[i] = visited2[j] = 1;
                            flag = 1;
                            ans += 1;
                            break;
                        }
                    }
                }
            }
            vector<int> ta, tb;
            for(int i = 0; i < sa.size(); i++){
                if(!visited1[i]){
                    ta.push_back(sa[i]);
                }
            }
            for(int i = 0; i < sb.size(); i++){
                if(!visited2[i]){
                    tb.push_back(sb[i]);
                }
            }
            sa.clear();
            sb.clear();
            sa = ta; sb = tb;
            if(!flag)
                break;
        }

        printf("Case %d: %d\n", caseno++, ans);
	}

	return 0;
}

/*
2
4
2 3 4 6
1 4 5 6

10
4 2 2 1 1 4 5 4 2 4
4 3 1 2 1 2 5 5 1 3
*/
