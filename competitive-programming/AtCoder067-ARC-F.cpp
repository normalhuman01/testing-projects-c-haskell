#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;

const long double PI = acos(-1);
const long long MOD = 1000000000 +7;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}

ll add(ll a, ll b, ll m = MOD){ return (a%m + b%m+2*m)%m;}

ll mul(ll a, ll b, ll m = MOD){ return ((a%m+m)*(b%m+m))%m;}

ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}

ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}

int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}

/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

const int N = 5000+5;
const int M = 200+5;
const int LOG = 18;

int n,m;
ll a[N];
int b[N][M];
int ST[M][N][LOG];

void startSparseTable(){
	for(int k=0; k<m; k++){
		for(int i=0; i<n; i++){
			ST[k][i][0] = b[i][k];
		}
		for(int d=1; 1<<d <= n; d++){
			int dis = 1<<(d-1);
			for(int i=0; i+2*dis <= n; i++){
				ST[k][i][d] = max(ST[k][i][d-1],ST[k][i+dis][d-1]);
			}
		}
	}
}

int getMax(int k, int x, int y){
	if(x == y) return b[x][k];
	int d = y-x+1;
	int bit = 31 - __builtin_clz(d);
	int dis = 1<<bit;
	return max(ST[k][x][bit],ST[k][y-dis+1][bit]);
}

ll solve(int i, int j){
	ll act = 0LL;
	for(int k=0; k<m; k++){
		act += getMax(k,i,j);
	}
	if(i){
		act -= a[j-1]-a[i-1];
	}
	else{
		if(j){
			act -= a[j-1];
		}
	}
	return act;
}

int main(){
	ri2(n,m);
	for(int i=0; i<n-1; i++) rll(a[i]);
	for(int i=1; i<n-1; i++) a[i] += a[i-1];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ri(b[i][j]);
		}
	}
	startSparseTable();
	ll ans = 0LL;
	for(int i=0; i<n; i++){
		/*
		int lo = i, hi = n-1;
		while(lo < hi){
			int mi = lo + (hi-lo+1)/2;
			if(solve(i,mi) <= solve(i,mi+1)) lo = mi;
			else hi = mi-1;
		}
		if(lo+1 < n) lo++;
		ans = max(ans,solve(i,lo));
		*/
		for(int j=i; j<n; j++){
			ans = max(ans,solve(i,j));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
