#include <iostream>
#include <stdio.h>
#include <math.h>
#include <unordered_set>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <string.h>
#include <limits.h>
#include <stack>
#include <functional>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <sstream>
 
 
#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
 
#define ii pair<int,int>
#define f first
#define s second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define iii pair<int, ii >
#define ii pair<int,int>
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt", "w", stdout);
#define eps 1e-9
#define pi 3.14159265359
#define nl (no<<1)
#define nr ( (no<<1)|1)
#define mid l + ( (r-l)>>1)

using namespace std;

typedef vector<int> vi;
const int maxn = 1e4 + 10;
typedef long long ll;

const int MAX = 1e2 + 10;
const int mod = 1e6 +7;
ll dp[MAX][MAX];
int n, test, t = 1;

char mat[MAX][MAX];


inline bool bound(int i,int j){
	return i >=0 && j>=0 && i < n && j < n;
}

ll w (ll n){
	return (n+mod)%mod;
}

ll f(int i , int j ){
	ll &r = dp[i][j];
	if ( r != -1)
		return r;
	
	ll v1 = 0 , v2 = 0;
	
	if( bound(i-1, j+1)){
		if ( mat[i-1][j+1] != '.'){
			if ( bound(i-2, j+2) ){
				v1 = f ( i - 2, j + 2);
			}
		}else{
			v1 = f( i - 1, j + 1);
		}
	}
	
	if ( bound ( i-1,j-1) ){
		if ( mat[i-1][j-1] != '.'){
			if( bound(i-2,j-2) ){
				v2 = f(i-2, j-2);
			}
		}else {
			v2 = f(i-1,j-1);
		}
	}
	
	return r = w (w(v1) + w(v2) );
}

int main (){
	
	cin >>test;
	while(test--){
		cin >> n;
		memset ( dp, -1, sizeof dp);
		for(int i = 0 ;i < MAX;i++)
			dp[0][i] = 1;
			
		ii start;
		for(int i = 0 ;i < n;i++)
			for(int j = 0;j < n;j++){
				cin >> mat[i][j];
				if ( mat[i][j] == 'W') start = { i , j};
				else if (mat[i][j] == 'B'){
					dp[i][j] = 0;
				}
			}
			cout << "Case "<<t++<<": ";
			cout << f ( start.f ,start.s) <<'\n';
	}
	return 0;
}


