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
 
const int maxn = 2e7 + 100;
const int MAX = 5e3 + 10;
typedef long long ll;
typedef vector< int> vi;		


int lp[maxn], fac[maxn], dois[maxn], cinco[maxn];

vi primes;

void sive(int n ){
	for(ll i = 2;i <= n;i++){
		if ( lp[i] == 0 ){
			primes.pb(i);
			lp[i] = i;
		}
		for(int j = 0 ; j < (int)primes.size() && primes[j] <= lp[i] && i*(ll)primes[j] <= n;j++){
			lp[i*primes[j]] = primes[j];
		}
	}
}

int pwr ( int n, int e ) {
	int r = 1;
	while ( e ){
		if ( e&1){
			 r = r * n  % 10 ;
		}
		n = n * n % 10;
		e>>=1;
	}
	return r;
}

int cnt[6];

inline int f(int n){
	int i = n;
	int cur = 1;
	while ( n > 1 ){
		if ( lp[n] == 2 or lp[n] == 5) {
			cnt[lp[n]]++;
		}else{
			cur = ( cur % 10 ) * ( lp[n] % 10 );
			cur%=10;
		}
		n/=lp[n];
	}
 
	dois[i] = cnt[2];
	cinco[i] = cnt[5];
	return cur;
}

int n, m;

 

int solve (int d, int c ){
	if ( d > c ){
		return pwr( 2, d-c);
	}else if ( c > d ){
		return pwr ( 5, c-d);
	}
	return 1;
}


int inv (int x ){
	for(int i = 0 ; i < 10;i++){
		if ( i * x  % 10 == 1 ) return i;
	}
}

int p(int n , int m , int f2,int f5 ,int p2, int p5){
	int ae = fac[n] * inv(fac[n-m]) % 10;
	int n2 = dois[n] - dois[n-m];
	int n5 = cinco[n]-cinco[n-m];
	return  ae * solve ( n2, n5) % 10;
}

 
    
//~ int gcd ( int a, int b ){
	//~ while ( b ){
		//~ int aux = b;
		//~ b = a % b;
		//~ a = aux;
	//~ }
	//~ return a;
//~ }
 

int main (){
	//~ in
	
	fac[0] = fac[1] = 1;
	sive ( maxn );
 
	for(int i = 2;i < maxn-10;i++){
		fac[i] = fac[i-1] * f(i) % 10;
		fac[i] %=10;
	}
	
	while ( scanf( "%d %d" ,&n ,&m )!= EOF ){
		int ans = p ( n, m,  dois[n], cinco[n],dois[n-m], cinco[n-m]);
 
		printf("%d\n", ans );
	}
	
	return 0;
}


