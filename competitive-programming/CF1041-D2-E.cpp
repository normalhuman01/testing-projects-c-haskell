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

ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}

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

/*
	Author: Racso Galvan

	Idea:

	- Greedy problem

	- Notice that b[i] must be n for all i, so if this doesn't hold the answer is NO

	- Now, consider the array a sorted in non decreasing order. We should have

	  that the number of a[i] <= k for each k must not exceed k. Like the former observation,

	  if that doesn't hold then the answer is NO.

	  The intuition is that we can't have more than k subtrees with values <= k.

	- 


*/

const int N = 1000+5;

int n;
int m;
int a[N], b[N];

int main(){
	ri(n);
	m = n-1;
	for(int i=0; i<m; i++){
		ri2(a[i], b[i]);
	}
	sort(a, a + m);
	for(int i=0; i<m; i++){
		if(b[i] < n){
			puts("NO");
			return 0;
		}
	}
	int leq = 0;
	for(int i = 1; i <= n; i++){
		while(leq < m and a[leq] <= i) leq++;
		if(leq > i){
			puts("NO");
			return 0;
		}
	}
	set<int> toUse;
	for(int i = 1; i < n; i++){
		toUse.emplace(i);
	}
	puts("YES");
	int last = a[0];
	for(int i = 1; i < m; i++){
		if(a[i-1] < a[i]){
			printf("%d %d\n",last, a[i]);
			toUse.erase(a[i]);
			toUse.erase(last);
			last = a[i];
		}
		else{
			if(*toUse.begin() < a[i]){
				printf("%d %d\n",last, *toUse.begin());
				last = *toUse.begin();
				toUse.erase(toUse.begin());
			}
			else{
				cout << "Not enough" << endl;
			}
		}
	}
	printf("%d %d\n",last, n);
	return 0;
}
