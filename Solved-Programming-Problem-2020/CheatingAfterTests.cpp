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

struct CheatingAfterTests{
int cheat(vector <int> report)
{
    int sum = 0;
    int Max = 0;
    for(int i = 0; i < report.size(); i++){
        sum += report[i];
        int tt = report[i];
        int x = report[i] / 10;
        int tx = x * 10 + 9;
        Max = max(Max, tx - tt);
        if(x > 0){
            tx = 90 + (tt % 10);
            Max = max(Max, tx - tt);
        }
    }

    return sum + Max;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {51, 47, 93}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 241; verify_case(0, Arg1, cheat(Arg0)); }
	void test_case_1() { int Arr0[] = {99, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 198; verify_case(1, Arg1, cheat(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 5, 7, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; verify_case(2, Arg1, cheat(Arg0)); }
	void test_case_3() { int Arr0[] = {93, 97, 92, 99, 92, 93}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 573; verify_case(3, Arg1, cheat(Arg0)); }
	void test_case_4() { int Arr0[] = {94, 6, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 113; verify_case(4, Arg1, cheat(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
CheatingAfterTests ___test;
___test.run_test(-1);
return 0;
}
