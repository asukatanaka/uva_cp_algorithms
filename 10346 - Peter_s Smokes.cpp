#include<iostream>
#include<deque>
#include<queue>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<set>
#include<vector>
//~ #include<iomanip>
//~ #include<map>
//~ #include<bitset>
//~ #include<algorithm>
//~ #include<stack>
//~ #include<unordered_map>
//~ #include<cstdlib>
//~ #include<unordered_set>
//~ #include<chrono>
 
#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
//~ #define ii pair	<long long ,long 	long >
#define i64ii pair< long long, pair<int,int> >
#define i64i pair<long long , int >
#define f first
#define s second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
//~ #define ii pair<int, int > 
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

typedef long long ll;	
typedef vector< int> vi;
typedef long double ld;

typedef pair<int,int> ii;		
typedef  pair <ii, ii > iiii;
typedef vector < ii > vii;


const int MAX = 1e2;
const int maxn = 1e5 + 100;
 

int n , k;

int f ( int n , int v , bool a){
	if ( a  ){
		return n + f ( 0 , n + v, 0 );
	}else {
		if ( v < k) return 0;
		return f ( v / k, v % k, 1);
	}
}

int main (){
 
 
	while ( cin >> n >> k ) {
		cout << f ( n, 0, 1) << '\n';
	}
	
	return 0;
}


 

