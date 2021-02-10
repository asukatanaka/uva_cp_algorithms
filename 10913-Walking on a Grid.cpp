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
#include<unordered_map>
#include<cstdlib>
 
#include<unordered_map>
#include<algorithm>
#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
 
#define ii pair<long long,long long>
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

const int MAX = 80;
const int maxn = 2e4 + 100;




int mat[MAX][MAX], dp[6][MAX][MAX],n, lim, test = 1;

void calc (int i, int j ){
	int soma = 0 , ag = 0;
	for(int k = j ;k <= n;k++){
		soma += mat[i][k];
		ag += (mat[i][k] < 0);
		for(int e = lim - ag; e>=0 ;e--){
			if ( dp[e][i+1][k] != -inf) {
				if ( dp[ag+e][i][j] < soma + dp[e][i+1][k] ){
					dp[ag+e][i][j] = soma + dp[e][i+1][k];
				}
			}
		}
	}
	
	soma = 0 , ag = 0;
	for(int k = j ;k;--k){
		soma+=mat[i][k];
		ag += (mat[i][k]<0);
		for(int e = 0 ;ag+e<=lim;e++){
			if ( dp[e][i+1][k] != -inf) {
				if ( dp[ag+e][i][j] < soma + dp[e][i+1][k] ){
					dp[ag+e][i][j] = soma + dp[e][i+1][k];
				}
			}
		}
	}
}
 

int main (){
	fast_io
	while ( cin >> n >> lim ,  n) {
		
		for(int k =0 ;k < 6 ;k++)
			for(int i = 0 ;i < MAX;i++)	
				for(int j =0 ;j < MAX;j++)
					dp[k][i][j] = -inf;
					
		for(int i = 1 ;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin >> mat[i][j];
			}
		}

		int item = (mat[n][n] < 0);
		dp[item][n][n] = mat[n][n];
		for(int i = n-1; i ;--i){
			if( mat[n][i] < 0 )
					if ( item+1 >lim)break;
					
			if ( mat[n][i] < 0 ){
				item++;
				dp[item][n][i] = dp[item-1][n][i+1] + mat[n][i];
			}else {
				dp[item][n][i] = dp[item][n][i+1] + mat[n][i];
			}
		}
		
		for(int i = n-1; i ;--i){
			for(int j = n; j ;j--){
				calc (i, j );
			}
		}
		
		int ans = -inf;
		
		for(int i = 0 ;i <= lim;i++) {
			ans = max ( ans, dp[i][1][1]);
		}
		
		cout << "Case " << test ++ << ": ";
		if ( ans == -inf)
			cout << "impossible\n";
		else
			cout << ans << '\n';	
	}
	
	return 0;
}

