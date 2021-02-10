
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
#define pb push_back
 
using namespace std;
typedef vector<int> vi;

const int maxn = 4e4 + 10;

typedef vector<int> vi;

typedef long long ll;

const int MAX = 80;
const int mod = 20437;
 
int n, a[maxn], dist[maxn], s, m, hasneg[maxn], vis[maxn];

vector < ii > e;
vi g[maxn];

void add(int a, int b ){
	g[a].pb(b);
}

int w ( int u ,int v ){
	int x = a[v]-a[u];
	return x*x*x;
}

int t = 1;

void f ( int u ){
	vis[u] = 1;
	hasneg[u] = 1;
	for(int j = 0 ;j < (int)g[u].size();j++){
		int v = g[u][j];
		if ( !vis[v] ){
			f (v);
		}
	}
}


void fill(){
	for(int i = 0 ;i<= n;i++) {
		dist[i] = inf;
		hasneg[i] = 0;
		vis[i] = 0;
	}
}

int main (){
 
	
	while ( cin >> n  ){
		for(int i = 0 ;i < n;i++){
			cin >> a[i + 1];
		}
		
		cin >> m;
		for(int i = 0 ;i < m;i++){
			int a, b; cin >> a >> b;
			e.pb( { a, b } );
		}
		
		fill();
		dist[1] = 0;
		
		for(int i = 0;i < n;i++){
			for(auto item: e ){
				int u = item.f , v = item.s;
				if ( dist[u] < inf )
					if ( dist[v] > dist[u] + w(u,v) ){
						dist[v] = dist[u] + w(u,v);
						if ( i == n-1){// enézima vez
							f(v);
						}
					}
			}
		}
 
		cout << "Set #"<<t++<<'\n';
		int q;
		cin >> q;
		while ( q--){
			int x; cin >> x;
			if ( dist[x] == inf or hasneg[x] or dist[x] < 3)
				cout << "?\n";
			else
				cout << dist[x] << '\n';
		}
		
		for(int i = 0 ;i <= n;i++)
			g[i].clear();
			
		e.clear();
	}
	
	return 0;
}
