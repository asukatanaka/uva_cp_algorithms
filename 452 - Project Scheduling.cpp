
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




int n, dg[maxn], v[maxn], tem[maxn];
vi g[maxn];

 
void add(int a, int b){
	dg[b]++;
	g[a].pb(b);
}

int calc(){
	
	priority_queue< ii, vector< ii > , greater< ii > > pq;
	int ans = 0;
	for(int i = 0 ;i < 27;i++){
		if ( dg[i] == 0 && tem[i]){
			pq.push( { v[i], i } );
		}
	}
	
	while ( !pq.empty() ){
		ii to = pq.top(); pq.pop();
		int u = to.s;

		vector<ii> ar;
		while (!pq.empty()){
				ar.pb( pq.top());
				pq.pop();
		}
		ans += to.f;
		for(int j = 0 ;j < (int)ar.size();j++){
				ar[j].f-=to.f;
				pq.push ( ar[j] );
		}
		
		for(int j = 0 ;j < (int)g[u].size();j++){
			int next = g[u][j];
			dg[next]-=1;
			if( dg[next] == 0 ){
				pq.push (  { v[next], next });
			}
		}
	}
	
	return ans;
}

int test;
string str;

int toint(string x){
	int ans = 0;
	for(int j = 0 ;j < (int) x.size();j++){
		ans*=10;
		ans+= x[j]-48;
	}
	
	return ans;
}

int valor(string str){
	string aux;
	for(int j = 2; str[j]>='0' and str[j]<='9';j++){
		aux+=str[j];
	}
	return toint(aux);
}

vi lista(string str){
	vi x;
	for(int j = str.size()-1; str[j]>='A'&&str[j]<='Z';j--){
		x.pb(str[j]-65);
	}
	return x;
}

int main(){
 
 bool prim = 1;
	cin >> test;
	cin.ignore();
	string nada;
	getline ( cin, nada);
	
	while (test--){
		memset ( dg, 0 , sizeof dg );
		memset ( tem, 0, sizeof tem );
 
		while ( getline( cin, str ), str.size() > 1){
			tem[str[0]-65] = 1;
			vi e = lista ( str);
			v[str[0]-65] = valor(str);
			for(int j = 0;j < (int)e.size();j++){
				add ( e[j], str[0]-65);
			}
		}
		if ( !prim)cout<<'\n';
		cout << calc() << '\n';
		
		prim = 0;
		for(int i = 0 ;i < 27;i++){
			g[i].clear();
		}
	}
	return 0;
}


