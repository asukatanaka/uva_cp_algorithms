
#include<iostream>
#include<queue>
#include<stack>
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
 
#define ii pair<long long , long long  >
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
 
const int maxn = 80;


int n, m, low[maxn], num[maxn], instac[maxn],aresta[maxn][maxn], dfs_num = 1, test = 1;

vi g[maxn];

map <string, int > mapa;
map <int , string > idx;
vi st;
inline void add(int a, int b ){
	g[a].pb(b);
}

void f(int u ){
	low[u] = num[u] = dfs_num++;
	st.pb( u);
	instac[u] = 1;
		
	for(int j = 0;j < (int)g[u].size();j++){
		int v = g[u][j];
		if(num[v] == 0 )  // nao visitado
			f(v);
		if( instac[v] )
			low[u] = min ( low[u], low[v] );
	}
	
	if( low[u] == num[u] ){
		vi este;
		while ( 1 ){
			int v = st.back(); st.pop_back();
			instac[v] = 0;
			este.pb(v);
			if ( u == v) break;
		}
		if ( (int)este.size() ){
			bool prim = 1;
			for(auto y : este) {
				if ( !prim) 	cout<< ", ";
				cout << idx[y] ;
				prim = 0;
			}
			cout << '\n';
		}
	}
}

 
void reseta(){
	for(int i = 1;i <= n;i++){
		g[i].clear();
	}
	for(int i = 1;i<= n;i++){
		instac[i] = num[i] = low[i] = 0;
	}			
		dfs_num = 1;
		mapa.clear();
		idx.clear();
		st.clear();
		
		for(int i = 0 ;i < maxn;i++)
			for(int j = 0 ;j < maxn;j++)
				aresta[i][j] = 0;
}

int main(){
		
		bool os = 1;
		while ( cin >> n >> m, ( n || m ) ){
		int k = 1;
		if(!os)cout<<'\n';
		for(int i = 0 ;i < m;i++){
			string str1, str2;
			cin >> str1 >> str2;
			
			if(!mapa[str1] ){
				mapa[str1] = k;
				idx[k] = str1;
				k++;
			}
			if(!mapa[str2] ){
				mapa[str2] = k;
				idx[k] = str2;
				k++;
			}
			
			if ( aresta[mapa[str1]][mapa[str2]] )continue;
			aresta[mapa[str1]][mapa[str2]] = 1;
			add( mapa[str1], mapa[str2] );
		}
		cout << "Calling circles for data set "<< test << ":\n";
		for(int i = 1;i <= n;i++){
			if( num[i] == 0 ){
				f( i);
			}
		}
		
		
		os = 0;
		reseta();
		test+=1;
	}
	return 0;
}
