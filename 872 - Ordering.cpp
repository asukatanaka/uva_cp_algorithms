
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
#define pb push_back
 
using namespace std;
typedef vector<int> vi;

const int maxn = 4e4 + 10;

typedef vector<int> vi;

typedef long long ll;

const int MAX = 80;
const int mod = 20437;
 


int test, used[27], tem[27], mat[27][27], qt, tem_ord = 0;

void f(int i, string perm){
	if ( (int)perm.size() == qt){
		tem_ord = 1;
		bool prim = 1;
		for(int i = 0 ;i <(int)perm.size();++i){
			if ( !prim )
				cout << ' ';
			cout << perm[i];
			prim = 0;
		}
		cout <<'\n';
		return;
	}
	
	for(int j = 0 ;j < 26;j++){
		bool y = 0;
		if ( tem[j] and !used[j]) {
			y = 1;
			for(int k = 0 ;k < 26 and y ;k++){
				if ( used[k] and mat[j][k]) y = 0;
			}
		}
			
		if(!y)continue;
		
		perm+=(j+65);
		used[j] = 1;
		f ( j , perm);
		used[j] = 0;
		perm.pop_back();
	}
	
}

int main(){
 
	cin >> test;
	string aux;
	getline ( cin , aux);
	
	bool wow = 1;
	while ( test--){
		
		string str;
		cin.ignore();
		getline (cin, str);
		tem_ord = 0;
		memset ( mat, 0 , sizeof mat);
		memset ( used, 0, sizeof used);
		memset ( tem, 0, sizeof tem );
		int n = str.size();
		qt =  ( n + 1 ) / 2;
		for(int i = 0 ;i < n;i+=2){
			tem[str[i]-65] = true;
		}
		
		getline ( cin, str);
		n = str.size();
		

		for(int i = 2 ;i < n; i+=4){
			int b = str[i]-65, a = str[i-2]-65;	
			mat[a][b] = 1;
		}
		if ( !wow)
				cout << '\n';
		
		for(int i = 0 ;i < 26;i++){
			if ( !tem[i])continue;
			string aux;
			used[i] = 1;
			aux+=i+65;
			f( i, aux);
			used[i] = 0;
		}
		
		if ( !tem_ord)
			cout << "NO\n";

		wow = 0;
	}
	return 0;
}


