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
#include<bitset>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<cstdlib>
#include<unordered_set>
#include<algorithm>
#include<chrono>
 
#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
		
#define ii pair	<long long ,long long >
#define i64ii pair< long long, pair<int,int> >
#define i64i pair<long long , int >
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
 
 
typedef long long ll;	
typedef vector< int> vi;
typedef long double ld;
		
typedef  pair <ii, ii > iiii;
typedef vector < ii > vii;
 
const int MAX = 2e5;
const int maxn = 1e5  + 10;
 

vector <ll> d (ll n ){
	vector<ll > ar;
	for(ll i = 1 ;i *i <= n;i++){
		if (n % i == 0 ){
			ar.pb (i);
			if ( n / i != i ){
				ar.pb ( n / i  );
			}
		}
	}
	
	sort ( ar.begin(), ar.end());
	return ar;
}
 
ll p (ll a1, ll an ) {
	return (an-a1+1) * double (an + a1) / 2;
}

int main (){
 
	fast_io
	
	ll k ;
	while ( cin >> k , k != -1 ){
		vector <ll >  x = d (2 *k);
		pair<ll,ll> par;
		int w = 0;
		
		for(int i = 0 ;i < (int) x.size();i++){
			ll g = 2*k / x[i];
			ll r = 2*k / g;
			ll a1 = ( g - (r-1)) / 2;
			ll an = a1+r-1;
			
			if ( a1 <= 0 or an <= 0 or ( a1 > an )) continue;
			if ( p(a1, an) == k  ){
				if ( an-a1+1 > w ){
					w = an-a1+1;
					par = { a1, an };
				}
			}
		}
		cout << k << " = " <<  par.f << " + ... + " << par.s << '\n';
	}
	
	return 0;
}
 
 
 
