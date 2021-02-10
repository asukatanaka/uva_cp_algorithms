
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
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt", "w", stdout);
#define eps 1e-9
 
#define pi 3.14159265359
#define nl (no<<1)
#define nr ( (no<<1)|1)
#define mid l + ( (r-l)>>1)
 
 
 
using namespace std;
 
typedef long long int ll;


const int MAX = 220;
typedef vector<int> vi;

 
char a[7] = {'W', 'A', 'K', 'J', 'S', 'D'};

int d[MAX], pot[MAX], h, w, mat[MAX][MAX], outra[MAX][MAX];

bool vis[MAX][MAX];

void pre(){
	for(int i = 0 ;i < 10 ;i++){
		d[i + 48] = i;
	}
	for(int i = 0 ;i < 10 ;i++){
		d[i + 97] = 10 + i;
	}
}

string tobin( char x){
	int decimal  = d[(int)x];
	string binario;
	while( decimal ){
		if ( (decimal%2) )
			binario.pb('1');
		else
			binario.pb('0');
		
		decimal/=2;
	}
	int _size = (int) binario.size();
	if ( _size < 4 ){
		for(int i = 0 ;i < 4-_size;i++){
			binario.pb('0');
		}
	}
	reverse( binario.begin(),binario.end() );
	return binario;
}

int oy[] = {-1, 0, 1, 0};
int ox[] = {0, 1, 0, -1};


inline bool wow (int l ,int c ){ 
	return ( l < 0 or c > 4*w+1 or c < 0 or l > h+1 or vis[l][c] or mat[l][c] != 0  );
}
inline bool wowoutra(int l ,int c ){
	return ( l < 0 or c > 4*w+1 or c < 0 or l > h+1 or outra[l][c] != 0  );
}

int reccall = 1;

inline void f(int i, int j){
	if (wow ( i , j) ) return;
	vis[i][j] = true;
	mat[i][j] = 2;
	for( int k = 0 ; k < 4;k++){
		int ni = i + oy[k], nj = j + ox[k];
		f( ni, nj);
	}
}

inline void foutra(int i ,int j ){
	if ( wowoutra(i,j ) )return;
	outra[i][j] = 2;
	
	for( int k = 0 ; k < 4;k++){
		int ni = i + oy[k], nj = j + ox[k];
		foutra( ni, nj);
	}
}

inline bool inva (int l ,int c ){ 
	return ( l < 0 or c > 4*w+1 or c < 0 or l > h+1 or mat[l][c] != 1  );
}
void f2 (int l ,int c ){
	if ( inva ( l, c) ) return;
	vis[l][c]= true;
	mat[l][c] = 3;
	outra[l][c] = 3;
	for(int k = 0 ; k < 4;k++){
		int el = l + oy[k], ec = c + ox[k];
		f2 ( el, ec );
	}
}

inline bool fora (int l ,int c ){
	return ( l < 0 or c > 4*w+1 or c < 0 or l > h+1 or vis[l][c] or outra[l][c] != 0  );
}

inline void f3 (int l, int c ){
	if ( fora ( l, c) )return;
	outra[l][c] = 8;
	mat[l][c] = 8;
	for(int k = 0 ;k < 4 ;k++){
		int el = l + oy[k], ec = c + ox[k];
		f3( el, ec );
	}
}

int calc(){
	int cnt = 0;
	for(int i = 0 ; i <= h+1;i++){
		for(int j = 0 ;j <= 4*w;j++){
			if ( outra[i][j] == 0 ){
				++cnt;
				f3(i, j);
			}
		}
	}
	
	return cnt;
}

void mostra(){
	cout<<'\n';
	for(int i = 0 ;i <= h + 1;i++,cout<<'\n'){
		for(int j = 0;j <= 4*w + 1;j++){
			cout << mat[i][j];
		}
	}
 
	cout<<'\n';
}

void mostraoutra(){
	cout << "OUTRA\n ";
	cout<<'\n';
	for(int i = 0 ;i <= h + 1;i++,cout<<'\n'){
		for(int j = 0;j <= 4*w + 1;j++){
			cout << outra[i][j];
		}
	}
 
	cout<<'\n';
	
}

int main (){
	 
 pre();
 int test = 1;
 
	while ( cin >> h >> w, ( h||w ) ){
		memset (mat,0, sizeof mat);
		memset (vis, 0 , sizeof vis);

		for(int i = 0 ;i < h;i++){
			for(int j = 0 ;j < w;j++){
				char letra; cin >> letra;
				string aux = tobin (letra);
				for(int k = 0;k < 4;k++){
						mat[1 + i][1 + 4*j + k] = aux[k]-48;
				}
			}
		}
		//~ mostra();
		
		f(0,0);
		//~ cout << "TERMINEI\n";
		//~ mostra();
		cout << "Case "<<test++<<": ";
		
		//~ bool uma = 0;
		vector<char> arr;
		

		for(int i = 0 ;i <= h + 1;i++){
				for(int j = 0 ;j <= 4*w + 1;j++){
					if ( mat[i][j] == 1 and !vis[i][j] ){
							//~ mostra();
							memset(outra, 0, sizeof outra);
							
							f2( i, j);
							foutra(0,0);
							//~ cout<<"depois do f2\n";
							//~ mostraoutra();
							//~ mostra();
							int valor = calc();

							//~ cout << "depois do f3\n";
							//~ mostra();
							//~ mostraoutra();
							//~ cout << "buracos = "<< valor << '\n';
							arr.pb(a[valor]);

					}
				}
		}
		sort (arr.begin(),arr.end());
		for(auto y: arr){
			cout<<y;
		}
		cout<<'\n';
	}
	
	return 0;
}
