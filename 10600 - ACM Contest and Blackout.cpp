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

 
typedef long long ll;
typedef vector< int> vi;

const int MAX = 1e2 + 10;
const int maxn = 320;



int p[MAX][10], wg[MAX][MAX], a[MAX][10], an[MAX], anc[MAX], lv[MAX], vis[MAX], n, m;


vector <ii> g[MAX];
void fill(){
	for(int i = 0 ;i < MAX;i++){
		an[i] =lv[i] = vis[i] = 0, g[i].clear();
		anc[i] = i;
	}
}

void add(int a ,int b , int c){
	g[a].pb({b, c});
	g[b].pb({a, c});
 
}

int findc(int x ){
	while ( x != anc[x] ){
		x = anc[x] = anc[anc[x]];
	}
	return x;
}

void une ( int a, int b ){
	anc[findc(a)] = findc(b);
}

void f ( int u ){
	vis[u] = 1;
	
	for(int j = 0 ;j < (int)g[u].size();j++){
		int v = g[u][j].f , peso = g[u][j].s;
		if( !vis[v] ){
			an[v] = u;
			lv[v] = lv[u]+1;
			wg[u][v] = peso;
			wg[v][u] = peso;
			f ( v);
		}
	}
}

void calc(){
 
	for(int i = 1;i <= n;i++){
		p[i][0] = an[i];
		a[i][0] = wg[an[i]][i];
	}
	
	for(int j = 1; j < 10;j++){
		for(int i = 1;i <= n;i++){
			p[i][j] = p[p[i][j-1]][j-1];
			a[i][j] = max ( a[i][j-1], a[p[i][j-1]][j-1]);
		}
	}
}

int hlca( int x, int y ){
	if( lv[x] > lv[y] ){
		swap ( x, y);
	}
	
	int dif = lv[y] - lv[x], resp = 0;
	for(int i = 0 ;dif;i++){
		if ( dif &(1<<i) ) {
			resp = max ( resp, a[y][i]);
			dif-=(1<<i);
			y = p[y][i];
		}
	}
	
	if ( x == y ) return resp;
	
	for(int j = 9 ;j >=0 ;--j){
		if ( p[x][j] != p[y][j] ){
			resp = max ( resp , max ( a[x][j], a[y][j] ) );
			x = p[x][j], y = p[y][j];
		}
	}
	resp = max ( resp, max ( a[x][0], a[y][0] ) );
	
	return resp;
}

int t;
int main (){
	 
	//~ in 
	cin >> t;
	while ( t--){
		cin >> n >> m;
		fill();
		vector< pair < int, ii > >e, us;
		for(int i = 0 ;i < m ;i++) {
			int a, b, c; cin >> a >> b >> c;
			e.pb ( { c, {a, b} });
		}
		
		sort(e.begin(), e.end() );
		
		int ans1 = 0, ans2 = 0;
		int ex = -1;
		for(int i = 0 ;i < (int)e.size();i++) {
			int a = e[i].s.f, b = e[i].s.s, w = e[i].f;
			if ( findc(a) != findc(b) ) {
				une ( a, b);
				add ( a, b, w);
				ex = a;
				ans1 += w;
			}else {
				us.pb ( e[i]);
			}
		}
		
		
		f(ex);
		calc();
 
		ans2 = inf;
		for(int i = 0 ;i < (int)us.size();i++){
			int a = us[i].s.f, b = us[i].s.s, w = us[i].f;
			int val = hlca ( a, b);
			ans2 = min ( ans2, ans1 - val + w);
		}

		cout << ans1 <<  ' '<< max ( ans1, ans2) << '\n';
	}
	return 0;
}



