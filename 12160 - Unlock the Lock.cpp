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


int cur, un, but, t = 1, b_size;
string c1, un1;
vector< string>  buttons;

unordered_map <string, int> vis;

inline int toint ( string str ){
	int ans = 0;
	for(int i = 0 ;str[i];i++){
		ans *=10;
		ans += str[i] - 48;
	}
	return ans;
}

inline string tostr (int  x){
	string str;
	int quatro = 4;
	while ( x  && quatro--) {
		int y = x%10;
		str += y+48;
		x/=10;
	}
	reverse(str.begin(),str.end());
	return str;
}


int bfs (string start, string end){
	queue<pair< int, string > > q;
	vis[start] = 0 ;
	q.push( {0 , start} );
	
	while (!q.empty()){
		int d = q.front().f;
		string to = q.front().s; q.pop();
		if ( vis[end]  && vis[end] < d )continue;
		for(int j = 0 ;j < b_size ;j++){
			string x = buttons[j];
			string vo = tostr ( toint(to) + toint(x) );
			if ( vis[vo] and vis[vo] <= d+1)continue;
			if (!vis[vo] or vis[vo] < d + 1){
				vis[vo] = d + 1;
				q.push (  { d+ 1, vo } );
			}
		}
	}
	if ( !vis[end] )
		return -1;
		
	return vis[end];
}

 
int main(){
 fast_io
	//~ in out
	while ( cin >> c1 >> un1  >> b_size, b_size ){
		buttons.resize(b_size);
		for(int i = 0 ;i < b_size;i++){
			cin >> buttons[i];
		}
		cout<< "Case "<<t++<<": ";
		int ans = bfs(c1, un1);
		if ( ans == -1 )
			cout<<"Permanently Locked\n";
		else
			cout<< ans << '\n';
		vis.clear();
	}
	return 0;
}
