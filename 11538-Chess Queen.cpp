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
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<cstdlib>
#include<unordered_set>
#include<algorithm>
#include<chrono>

#define inf 0x3f3f3f3f
#define sup_inf 2e18
#define pb push_back
		
#define ii pair	<int, int>
#define i64ii pair< long long, pair<int,int> >
#define i64i pair<long long , int >
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
 
typedef long long ll;	
typedef vector< int> vi;
typedef long double ld;
typedef  pair <ii, ii > iiii;
typedef vector < ii > vii;
 
const int MAX = 2e5;
const int maxn = 1e6 + 200;

typedef unsigned long long ull;
using namespace std;



ull d[maxn];

ull n, m ;

void calc(){
 for(ull i = 2 ;i < 1e6 + 100;i++) {
  d[i] = d[i-1] + i*i - i;
 }
}

ull p (ull n){
 return n*n-n;
}

int main (){ 
 calc();
 
 while ( cin >> n >> m, n or m ) {
 
  
  if ( n > m ) {
   swap( n, m );
  }
  
  ull t = ( 1+ m-n);
  ull ans = 2 *  t * p(n) + 4 * d[m-(t)]  + n *  m *  (n+m-2);
  cout << ans << '\n';
 }
 
 
 return 0;
}




