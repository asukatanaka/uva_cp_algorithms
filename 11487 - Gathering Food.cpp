#include<iostream>
#include<queue>
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
#define  i_iii pair<int, iii >
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt", "w", stdout);
#define eps 1e-9
 
#define pi 3.14159265359
#define nl (no<<1)
#define nr ( (no<<1)|1)
#define mid l + ( (r-l)>>1)
#define mod 20437
 
 
 
using namespace std;
 
typedef long long int ll;


const int MAX = 15;
const int maxn = 1e3 + 10;

typedef vector<int> vi;
	
	

//~ 11487 - Gathering Food
//~ 104 - Arbitrage
//~ 10401 - Injured Queen Problem
//~ https://uhunt.onlinejudge.org/id/900367
//~ https://codeforces.com/contest/208/problem/E

int dp[MAX][MAX], dist[MAX][MAX], vis[MAX][MAX], n, alf[30];


char mat[MAX][MAX];

int oy[] = {-1, 0, 1, 0};
int ox[] = {0, 1, 0, -1};

inline bool val (int i ,int j ){
	return i >=0 and j>=0 and i < n and j < n and !vis[i][j] and mat[i][j]!='#';
}


inline int w ( int x){
	return ( x + mod) % mod;
}

void bfs(int si, int sj, int ti, int tj){
	
	memset (dist,0, sizeof dist);
	queue< ii > q;
	vis[si][sj] = 1; 
	dist[si][sj] = 0;
	for(int k = 0 ;k < 4;k++){
		int ni = si + oy[k], nj = sj + ox[k];
		if ( !vis[ni][nj] && val( ni,nj ) ){
			dist[ni][nj] = dist[si][sj]+1;
			vis[ni][nj] = 1;
			dp[ni][nj] = 1;
			q.push ({ ni, nj });
		}
	}
	
	while (!q.empty()){
		ii x = q.front(); q.pop();
		int i = x.f, j = x.s;
		for(int k = 0 ;k < 4;k++){
			int ni = i + oy[k], nj = j + ox[k];
			if ( vis[ni][nj] && dist[ni][nj] == dist[i][j]-1){
				dp[i][j] = w ( w(dp[i][j]) + w(dp[ni][nj]) );
			}
		}
		
		for(int k = 0 ;k < 4;k++){
			int ni = i + oy[k], nj = j + ox[k];
			if ( !vis[ni][nj] && val( ni,nj ) ){
				vis[ni][nj] = 1;
				dist[ni][nj]=dist[i][j]+1;
				q.push ( { ni, nj } );
			}
		}
	}
}

//~ void mostra(){
	//~ for(int i = 0 ;i < n;i++,printf("\n"))
		//~ for(int j= 0 ;j <n;j++)
			//~ printf("%c",mat[i][j]);
			
	//~ printf("\n");
//~ }

//~ void distancia(){
	//~ for(int i = 0 ;i < n;i++,printf("\n"))
		//~ for(int j= 0 ;j <n;j++)
			//~ printf(" %d",dist[i][j]);
			
	//~ printf("\n");
//~ }



//~ void imp_dp(){
	
	//~ cout << "dp = \n";
	//~ for(int i = 0 ;i < n;i++,cout<<'\n')
		//~ for(int j =0 ;j < n;j++)
			//~ cout << dp[i][j] << ' ' ;
	//~ cout<<'\n';
//~ }

void arruma(char a, char b, int k ){
	for(int i = 0 ;i < n; i++){
		for(int j = 0;j < n; j++){
			if ( mat[i][j]>='A' &&  ( mat[i][j]!= a and mat[i][j]!= b) && !alf[mat[i][j]-65] ){
				vis[i][j] = 1;
			}
		}
	}
}



int t = 1;
int main (){
 
	while ( scanf(" %d ",&n )  && n ){
		memset ( alf, 0, sizeof alf);
		vector < pair < char, ii > > a;
		for(int i = 0 ;i < n;i++){
			for(int j = 0 ;j < n;j++){
				scanf(" %c", &mat[i][j]);
				if ( mat[i][j]>='A'){
					a.pb ({mat[i][j], { i, j} } );
				}
			}
		}

		sort(a.begin(), a.end());
		
		int ac = 1 , distancia_total = 0;
		
		bool ruim = 0;
		for(int i = 1;i < (int) a.size() && !ruim;i++){
			memset ( vis,0, sizeof vis);
			memset( dp, 0 , sizeof dp );
			char start = mat[a[i-1].s.f][a[i-1].s.s];
			char term = mat[a[i].s.f][a[i].s.s];
			alf[start-65] = 1;
			alf[term-65] = 1;
			
			arruma(start, term, i);
			bfs ( a[i-1].s.f ,a[i-1].s.s, a[i].s.f , a[i].s.s);
			if ( !vis[a[i].s.f][a[i].s.s] ){
				ruim = 1;
			}

			ac = w(ac) * w( dp[a[i].s.f][a[i].s.s]);
			ac=w(ac);
			distancia_total+=dist[a[i].s.f][a[i].s.s];
			
		}
		printf("Case %d: ", t++);
		if ( ruim )
			printf("Impossible\n");
		else
			printf("%d %d\n", distancia_total , ac );
			
	}
	
	
	return 0;
}

