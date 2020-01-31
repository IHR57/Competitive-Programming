#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

struct BinaryHeapLeaf{
vector <int> maxDiff(int N)
{
    int sum = 0, idx = 0;
    for(int i = 0; i < 50; i++){
        sum += (1<<i);
        if(sum >= N){
            if(sum == N || sum == N + 1){
                idx = i;
            }
            else
                idx = i - 1;
            break;
        }
    }

    vector<int> res;
    res.pb((N + 1) >> 1);
    res.pb(N - idx);

    return res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, maxDiff(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, maxDiff(Arg0)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, maxDiff(Arg0)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, maxDiff(Arg0)); }
	void test_case_4() { int Arg0 = 47; int Arr1[] = {24, 43 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, maxDiff(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
BinaryHeapLeaf ___test;
___test.run_test(-1);
return 0;
}
