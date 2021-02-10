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
const int maxn = 1e4;
const int MAX = 1e2 + 10;
 
typedef vector< int> vi;

int o[30][30], y[30][30], to, eleta, n = 26, m;

void add_young ( int a, int b , int c, int type){
	y[a][b] = c;
	if ( type == 2 )
		y[b][a] = c;
		
}

void add_old ( int a, int b , int c, int type){
	o[a][b] = c;
	if ( type == 2 )
		o[b][a] = c;
	
}

void yf(){// young
	for(int i = 0; i < n;i++)
		y[i][i] = 0;
		
	for(int k = 0 ;k < n;k++){
		for(int i = 0 ;i < n;i++){
			for(int j = 0 ;j < n;j++){
				y[i][j] = min ( y[i][j], y[i][k] + y[k][j] ) ;
			}
		}
	}
}

void of(){// old
	
	for(int i = 0 ;i < n;i++)
		o[i][i] = 0;
		
	for(int k = 0 ;k < n;k++){
		for(int i = 0 ;i < n;i++){
			for(int j = 0 ;j < n;j++){
				o[i][j] = min ( o[i][j], o[i][k] + o[k][j] );
			}
		}
	}
	
	int ans = inf;
	for(int i = 0 ;i < n;i++)	{
			ans = min ( ans,  y[to][i] + o[eleta][i]);
	}
	
	if ( ans == inf )
		cout << "You will never meet.\n";
	else{
		bool prim = 1;
		cout << ans << ' ';
		for(int i = 0;i < n;i++){
			if( y[to][i] + o[eleta][i] == ans ){
				if ( !prim )cout << ' ' ;
				
				cout << char( i + 65);
				prim = 0;
			}
		}
		cout << '\n';
		
	}
}


inline void fill(){
	for(int i = 0 ;i < n;i++)
		for(int j = 0 ;j < n;j++)
			o[i][j] = y[i][j] = inf;
}



int main (){
	//~ in
	while ( cin >> m , m ){
		fill();
 
		for(int i = 0 ;i < m;i++){
			char x, type;
			cin >> x >> type;
			char a, b;
			int c, tt;
			cin >> a >> b >> c;
 
			if ( type == 'B')
				tt = 2;
			else
				tt = 1;
				
			if ( x == 'Y') {
				add_young( a-65, b-65, c, tt);
			}else {
				add_old ( a-65, b-65, c, tt ); 
			}
		}
			char e, r;
			cin >> e >> r;
			to = e-65, eleta = r-65;
			yf();
			of();
	}
	
	return 0;
}
