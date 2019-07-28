#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

class LoopsyDoopsy
{
	public:
		 string getSmallestNumber(int n)
		 {
		 	string str;
		 	if(n == 1)
		 		return "0";
		 	for(int i = 0; i < n / 2; i++){
		 		str += "8";
		 	}
		 	if(n % 2)
		 		str = "4" + str;
		 	return str;
		 }
};