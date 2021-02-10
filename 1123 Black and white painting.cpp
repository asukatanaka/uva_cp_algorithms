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


 
 
int n ,m, cor;


bool impar ( int x ){
	return x&1;
}

int solve(int n, int m , int cor ){
	if( cor ){
		if ( impar (n) and impar (m)){
			return n * m  / 2;
		}
	}else {
		if ( impar (n) and impar(m)) {
			return( n * m  + 1 )/ 2;
		}
	}
	return (n * m ) / 2;	
}
 
int main (){
	fast_io
	//~ in
	while ( cin >> n >> m >> cor, n or m ){
		n-=7; m-=7;
		
		cout << solve ( n, m , !cor ) << '\n';
	}
	return 0;
}
