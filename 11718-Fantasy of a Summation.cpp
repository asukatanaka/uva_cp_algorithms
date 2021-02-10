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

ll n, k, mod;
int test = 1, t;


ll w ( ll n ){
	return (n + mod)  % mod;
}

ll pwr (ll n ,ll e ){
	ll r = 1;
	while ( e) {
		if ( e&1){
			r =  w( r * n);
		}
		n = w( n * n );
		e>>=1;
	}
	return r;
}

int main (){
	fast_io
 
	cin >> t;
	while ( t-- ){
		cin >> n >> k >> mod;
		
		ll answer = 0;
		for(int i = 0 ;i < n;i++){
			ll x; cin >> x;
			answer += w( w(x) * w( w (pwr ( n , k-1))  * w(k) ) );
			answer = w ( answer );
		}
		
		cout <<"Case "<< test++ << ": " << answer << '\n';
	}
	
 return 0;
}
 
