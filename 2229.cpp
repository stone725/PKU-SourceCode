#include <cstdio>
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <iterator>
#include <functional>

using namespace std;
#define FOR(i, s, n) for(int i = s; i < (int)n; i++)
#define per(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, s, n) for(int i = s; i >= (int)n; i--)
#define FORIT(i, A) for (auto i : A)
#define PRINT(x) cout << (x) << "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MP make_pair
#define EACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define NCLR(a) memset((a), -1 ,sizeof(a))
#define dump(x) cout << #x << " = " << (x) << "\n";
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n";
#define sq(n) (n) * (n)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef priority_queue<int> maxpq;
typedef priority_queue< int, vector<int>, greater<int> > minpq;
typedef pair<double, double> P;
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 29;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

static int dp[ 1000001 ][ 23 ];
static int MOD = 1000000000;

int solve( int now, int b ) {
	if ( now <= 0 ) {
		return now == 0;
	}
	if ( dp[ now ][ b ] >= 0 ) {
		return dp[ now ][ b ];
	}
	int res = 0;
	for ( int i = b; i >= 0; i-- ) {
		int a = 1;
		for ( int j = 0; j < i; j++ ) {
			a *= 2;
		}
		if ( now - a < 0 ) {
			continue;
		}
		res += solve( now - a, i );
		res %= MOD;
	}
	return dp[ now ][ b ] = res;
}

int main() {
	NCLR( dp );
	int a;
	scanf( "%d", &a );
	printf( "%d\n", solve( a, 20 ) );
	return 0;
}