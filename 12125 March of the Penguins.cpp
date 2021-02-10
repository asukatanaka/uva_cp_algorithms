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
const int MAX = 4e2;

int f[MAX][MAX],mem[MAX][MAX],  ss = 349, st = 350, vis[MAX], anc[MAX], n;

double d;
vi g[MAX];

struct ice{
	int x, y, num , cap;
	ice(int a, int b, int c, int d) : x(a), y(b), num(c), cap(d){}
	ice(){}
};

vector < ice > arr;

inline double dist(int x1, int y1, int x2, int y2 ){
	return sqrt (  (y2 - y1) * (y2 - y1) +
	( x2 - x1) * ( x2 - x1) );
}

bool bfs (int s, int t ){ 
	queue<int>q;
	q.push (s);
	memset ( vis, 0, sizeof vis);
	vis[s] = 1;
	while ( !q.empty()){
		int u = q.front(); q.pop();
		for(int j = 0 ; j < (int)g[u].size();j++){
			int v = g[u][j];
			if ( f[u][v] <= 0 or vis[v] )continue;
			anc[v] = u;
			vis[v] = 1;
			q.push (v);
		}
	}
	return vis[t];
}

int mf (int source, int t){
	int max_flow = 0;
	
	while ( bfs ( source, t ) ){
		int x = t, garg = inf;
		while ( x != source){
			garg = min(garg, f[anc[x]][x] );
			x = anc[x];
		}
		x = t;
		while( x != source ){
			f[anc[x]][x]-=garg;
			f[x][anc[x]]+=garg;	
			x = anc[x];
		}
		max_flow+=garg;
	}
	return max_flow;
}

void add(int a, int b , int c){
	g[a].pb(b);
	g[b].pb(a);
	f[a][b] = c;
	mem[a][b] = c;
}

void reseta(){
	for(int i = 0 ;i < MAX;i++){
		for(int j = 0;j < MAX ;j++){
			f[i][j] = mem[i][j];
		}
	}
}
void fill(){
	for(int i = 0;i < MAX;i++)
		for(int j = 0;j < MAX;j++)
			f[i][j] = mem[i][j] = 0;
}


int main (){
	
	int test;
	cin >> test;
	
	while ( test--){
		cin >> n >> d;
		fill();
		arr.resize(n+1);
		int total = 0;
		for(int i = 1;i <= n; i++){
			cin >> arr[i].x >> arr[i].y >> arr[i].num >> arr[i].cap;
			add ( 2*i, 2*i+1, arr[i].cap);
			add( ss, 2*i, arr[i].num);
			total += arr[i].num;
		}
		
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if ( dist ( arr[i].x , arr[i].y , arr[j].x, arr[j].y ) <= d ){
					add( 2*i+1, 2*j, inf);
					add( 2*j+1, 2*i, inf);
				}
			}
		}
		
		vector <int > ans;
		for(int i = 1;i <= n;i++){
			if ( mf ( ss, 2*i) == total ){
				ans.pb ( i );
			}
			reseta();
		}
		
		bool prim = 1;
		for(auto item : ans ) {
			if (!prim)cout<< ' ';
			cout << item-1;
			prim = 0;
		}
		
		if ( ans.size() == 0 ){
			cout << "-1";
		}
		
		cout << '\n';
		for(int i = 0 ; i < MAX;i++){
			g[i].clear();
		}
	}
	
	return 0;
}

