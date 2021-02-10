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
const int MAX = 1e2 + 10;
 


int n, m, mat[MAX][MAX], indg[MAX],  num, test = 1;

char str[MAX][MAX];
map <string, int> mapa;
map < int, string> rev;

vi g[MAX];

inline void ad(int a, int b ){
 
	g[a].pb(b);
	indg[b]++;
}

void solve(){
	vi ans;
	priority_queue<int, vi, greater<int>> q;
	
	for(int i = 1;i < num;i++){
		if ( indg[i] == 0) {
			q.push(i);
		}
	}
	
	while ( !q.empty() ){
		int u = q.top(); q.pop();
		
			ans.pb(u);
			for(int j = 0;j < (int)g[u].size();j++){
				int v = g[u][j];
				indg[v]--;
			if(indg[v] == 0){
					q.push (v);
			}
		}
	}
	
	cout << "Case #"<<test++<<": " <<"Dilbert should drink beverages in this order: ";
	bool prim = 1;
	for(int i = 0 ;i <(int) ans.size();i++) {
		if (!prim)cout<< ' ';
		cout<<rev[ans[i]];
		prim = 0;
	}
	cout<<".\n";
}

	

int main (){
	//~ in out
	
		
	while( cin >> n ){ 
		cin.ignore();	
		num = 1;

		for(int i = 0 ;i < n;i++){
			string str; getline ( cin, str);
			mapa[str]=num++;
			rev[mapa[str]] = str;
		}
		
		cin >> m;
		cin.ignore();	
		for(int i= 0 ;i < m;i++){
				string str, aux,a,b; getline ( cin, str);
				stringstream ss(str);
				bool prim = 0;
				while ( ss >> aux ){
						if (!prim) a = aux;
						else	b = aux;
						prim = 1;
						aux.clear();
				}
				ad( mapa[a], mapa[b]);
		}
		
		for(int i = 0 ;i < MAX;i++)
			sort( g[i].begin(), g[i].end());
		

		solve();
		cout<< '\n';
		for(int i = 0 ;i< MAX;i++){
			g[i].clear();
		}
			
		memset ( mat, 0 , sizeof mat);
		memset ( indg, 0, sizeof indg);
		rev.clear();
		mapa.clear();
	}
	
	
	return 0;
}


 








