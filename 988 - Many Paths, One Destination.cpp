
#include<iostream>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
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
const int MAX = 5e3 + 10;


int vis[maxn], ways[maxn],n;
vi g[maxn];


void f(int u ){
	vis[u] = 1;
	for(int j = 0;j < (int)g[u].size();j++){
		int v = g[u][j];
		if ( !vis[v] ){
			f(v);
		}
		ways[u]+=ways[v];
	}
	
}

int main (){
	
	bool entre = 0;
	while ( cin >> n ) {
		memset ( vis, 0, sizeof vis);
		memset ( ways, 0, sizeof ways);
		for(int i = 0 ;i < n;i++){
			int num;cin >> num;
			if ( num == 0 ){
				ways[i] = 1, vis[i] = 1;
			}
			for(int j = 0 ; j < num;j++){
				int x; cin >> x;
				g[i].pb(x);
			}
		}
		f(0);
		
		if ( entre ) cout << '\n';
		cout << ways[0] << '\n';
		
		entre = 1;
		
		for(int i = 0 ;i < maxn;i++)
			g[i].clear();
	}
	
	return 0;
}
