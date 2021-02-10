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

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;


typedef long long ll;
const int MAX = 50;
const int maxn = 1e6 +100;


int n, fat[maxn], ans[maxn];

unordered_map<int, int> lcm;

void sive(int n){
	for(int i = 0 ;i < maxn;i++)
		fat[i] = i;

	for(ll i = 2;i <= n;i++){
		if( fat[i] == i){
			for(ll j = 2*i ;j <= n; j+=i){
				fat[j] = i;
			}
		}
	}

}
 
inline int pwr (int n, int e ){
	int r = 1;
	while(e ){
		if (e&1 )r = ( r * n ) % 10;
		n = (n * n ) % 10;
		e>>=1;
	}
	return r;
}
 

void solve (){
	ll dig = 1;
	for(int i = 1;i < 1e6 + 2;i++){// i < n
		unordered_map < int, int > cur;
		int n = i;
		
		while ( fat[n] > 1 ){
			cur[fat[n]]++;
			n /=fat[n];
		}
		
		for( auto item : cur ){
			int val = item.f, exp = item.s;
			int tem = lcm[val];
			if ( val != 5 and val != 2){
					if ( exp > tem )
						dig = ( dig * pwr ( val, exp-tem ) ) % 10;
			}
			
			if ( exp > tem )
				lcm[val] = exp;
		}
		int cinco  = lcm[5], dois = lcm[2];
		ll novo;
		
		if ( dois > cinco )
			novo  =  (dig * pwr ( 2, dois-cinco) )%10;
		else 
			novo = ( dig * pwr ( 5, cinco-dois ) )%10;
		
		ans[i] = novo;
	}
	
}

int main (){
	
	//~ in 

	sive( 1e6 + 10 );
	solve();
	
 
	
	while ( scanf("%d",&n ) , n){
		printf("%d\n", ans[n]);
	}
	
	return 0;
}
