//Problem ID: CodeForces - 408C (Triangle)
//Programmer: IQBAL HOSSAIN     Description: Geometry
//Date: 16/01/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    for(int i = 1; i < a; i++){
        for(int j = 1; j < a; j++){
            if(i * i + j * j == a * a){
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 1; i < b; i++){
        for(int j = 1; j < b; j++){
            if(i * i + j * j == b * b){
                for(int k = 0; k < v.size(); k++){
                    if(v[k].second != j && ((v[k].first * (-i)) + (v[k].second * j)) == 0){
                        printf("YES\n");
                        printf("0 0\n%d %d\n%d %d\n", v[k].first, v[k].second, -i, j);
                        return 0;
                    }
                }
            }
        }
    }

    printf("NO\n");

    return 0;
}
