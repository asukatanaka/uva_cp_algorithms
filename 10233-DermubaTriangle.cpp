#include<iostream>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include<stack>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<set>
#include<vector>
#include<bitset>
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
 
#define pi 3.14159265359
#define nl (no<<1)
#define nr ( (no<<1)|1)
#define mid l + ( (r-l)>>1)
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
 
const int maxn = 2e5 + 10;
const int MAX = 4e2;

int n, a, b;

ll f(double n  ){
	double a1 = 3;
	double an = a1 + (n-1) * 2;
	return n * ( an + a1) / 2;
}

ll get(ll x){
	ll l = 0 , r = 1e9 + 400;
	while ( l < r  ) {
		if(f (mid ) < x )
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

int par(int x ){
	return !(x&1);
}

pair < double, double > w ( ll num, ll x , ll last ) {
	if ( num  == 0 ) return { 0 ,0 };
	
	ll meio = last - x;
	double h = sqrt(3) / 2.0;
	double R = 0.57735026919;
	double apotema = 0.28867513459;
	
	double y;
	if( par(x) != par(num) ) 
		y = 2*apotema +  (x - 1 ) * h;
	else 
		y = R + apotema  +(x-1) *h;
		
	return {  (num - meio ) * 0.5, -y };
}

double dist ( pair< double  ,double > pa, pair < double , double > pb ) {
	return sqrt ( (pb.f - pa.f) *(pb.f - pa.f) +  
	(pb.s - pa.s ) *(pb.s - pa.s ) );
}

double solve(int a, int b ){
	ll line_a = get(a);
	ll line_b = get(b);
	return dist  ( w (a ,line_a, f(line_a )), w ( b, line_b, f(line_b) ) );
}

int main (){
	fast_io
	
	int a, b;
	while ( cin >> a >> b ){
		cout << fixed << setprecision(3) << solve ( a, b) << '\n';
	}
	
	return 0;
}
