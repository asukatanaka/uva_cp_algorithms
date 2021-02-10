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
 
const int maxn = 2e5 + 100;
const int MAX = 5e3 + 10;
typedef long long ll;
typedef vector< int> vi;		




int x;


ll f (ll n ){
	return 1 + 6 * n  * double ( n + 1) / 2.0 ;
}

ii par (int i, int start, int dif, int n){
	if ( i == 0 ){
		return {n-1-dif, 1 +dif};
	}else if ( i == 1 ){
		return {-dif, n};
	}else if ( i == 2 ){
		return { -n, n-dif};
	}else if ( i == 3 ){
		return { -n+dif, -dif};
	}else if ( i == 4 ){
		return { dif, -n};
	}else  {
		return {n, -n+ dif};
	}
}

ii solve(int x ){
	if( x == 1 ){
		return { 0 , 0  };
	}
	int l = 0 , r = maxn-1;
	
	while ( l < r ){
		if ( f (mid) < x ){
			l = mid + 1;
		}else{ 
			r = mid;
		}
	}
	
	int ant  = f(l-1);
	
	ii seg1 = { ant+1 ,ant +l}; // 20 -  22
	ii seg2 = {seg1.s, seg1.s+ l};// 22 - 25
	ii seg3 = {seg2.s ,seg2.s+l}; // 25 - 28
	ii seg4 = { seg3.s, seg3.s +l };  // 28 - 31
	ii seg5 = { seg4.s, seg4.s + l};// 31 - 34
	ii seg6 = { seg5.s, seg5.s +l};// 34 - 37
	ii arr[6] = {seg1, seg2, seg3, seg4 , seg5, seg6};
	
	for(int i = 0 ;i < 6;i++) { 
		if ( x >= arr[i].f && x <= arr[i].s ) {
			return par (i, arr[i].f, x-arr[i].f, l);
		}
	}
	return  {-1,-1};
}


int main () {
	
	//~ in
	
	fast_io
	
	int x;
	while ( cin >> x) {
		ii answer = solve (x);
		cout << answer.f << ' '<< answer.s << '\n';
	}
	
	return 0;
}
 
