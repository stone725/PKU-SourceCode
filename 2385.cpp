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
int n, w;
static int dp[ 1001 ][ 31 ][ 2 ];
static vector<bool> _array;

int solve( int now, int moved, bool is_one ) {
	if ( now == n ) {
		if ( moved ) {
			return -INF;
		}
		return 0;
	}
	if ( dp[ now ][ moved ][ is_one ] >= 0 ) {
		return dp[ now ][ moved ][ is_one ];
	}
	int res = 0;
	res = max( res, solve( now + 1, moved, is_one ) + ( _array[ now ] == is_one ) );
	if ( moved ) {
		res = max( solve( now + 1, moved - 1, !is_one ) + ( _array[ now ] == !is_one ), res );
	}
	return dp[ now ][ moved ][ is_one ] = res;
}

int main() {
	NCLR( dp );
	
	scanf( "%d %d", &n, &w );
	_array.resize( n );
	for ( int i = 0; i < n; i++ ) {
		char a;
		scanf( "%d", &a );
		_array[ i ] = a - 1;
	}
	printf( "%d\n", solve( 0, w, false ) );
	return 0;
}