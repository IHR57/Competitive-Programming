//Problem ID: CodeForces - 465C (No to Palindromes!)
//Programmer: IQBAL HOSSAIN     Description: String
//Date: 02/01/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	char str[MAX], apbt[]= "abcdefghijklmnopqrstuvwxyz";
	int l1, l2, idx, flag = 0, n, p;

	cin>>n>>p;
	cin>>str;

	for(int i = n - 1; i >= 0; i--){
		idx = str[i] - 'a';
		l1 = i - 1;
		l2 = i - 2;
		for(int j = idx + 1; j < p; j++){
			if(l1 >= 0){
				if(str[l1] == apbt[j]){
					continue;
				}
				if(l2 >= 0){
					if(str[l2] == apbt[j]){
						continue;
					}
				}
			}
			str[i] = apbt[j];
			flag = 1;
			idx = i;
			break;
		}
		if(flag)
			break;
	}

	if(flag){
        for(int i = idx + 1; i < n; i++){
            for(int j = 0; j < p; j++){
                if(str[i-1] == apbt[j] || str[i-2] == apbt[j]){
                    continue;
                }
                str[i] = apbt[j];
                break;
            }
        }
        cout<<str<<endl;
	}
	else{
        cout<<"NO"<<endl;
	}

	return 0;
}
