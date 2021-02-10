#include<iostream>
#include<deque>
#include<queue>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<iomanip>
#include<map>
#include<unordered_map>
 
#include<unordered_map>
#include<algorithm>
#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
 
#define ii pair<int,int>
#define f first
#define s second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define iii pair<int, ii >
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt", "w", stdout);
#define eps 1e-9
#define id pair<int ,double > 
#define di pair<double, int>
 
#define pi 3.14159265359
#define nl (no<<1)
#define nr ( (no<<1)|1)
#define mid l + ( (r-l)>>1)
 
using namespace std;
 
const int maxn = 2e5 + 100 ;
const int MAX = 5e3 + 10;
typedef long long ll;
typedef vector< int> vi;		

ll n;

ll p(double n ){
	return n* ( n + 1) / 2;
}

pair <int,int > solve(ll n ){
	int l = 1 , r = 1e9;
	while ( l < r ){
		if ( p(mid ) < n ){
			l = mid + 1;
		}else {
			r = mid;
		}
	}
	
	int dif = abs ( p(mid ) - n );
	if (l&1) 
		return  {1 + dif, l - dif};
	
	return {l -dif, 1 + dif };
}


int main(){
 
	while ( cin >> n ){
		ii x = solve ( n);
		cout << "TERM "<< n << " IS " << x.f << '/' << x.s << '\n';
	}
}


