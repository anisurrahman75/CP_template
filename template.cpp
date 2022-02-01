#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
using  namespace std;

// pbds=polisy base data structure.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
//Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
//*(s.find_by_order(2)) : 3rd element in the set i.e. 6
//order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
//end pbds

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define PI acos(-1)
#define endl      "\n"
#define clr(arr,x)      memset(arr, x, sizeof arr)
#define vout(v,sz)      for(int w=0;w<sz;w++){if(w) cout<<" ";else cout<<endl; cout<<v[w];}
#define all(v)          v.begin(), v.end()
#define rall(v)         v.rbegin(), v.rend()
#define F first
#define S second
#define tu tuple <int, int, int>
// tie(t11, t12, t13) = t1;// for unpact touple
// tie(t21, t22, t23) = t2;
// struct comp {
//     bool operator() (const tu &t1, const tu &t2) const {
//     	int t11, t12, t13;
//     	int t21, t22, t23;
//     	tie(t11, t12, t13) = t1;
//     	tie(t21, t22, t23) = t2;
//     	return t11 > t21;
//     }
// };

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void file();

int cs = 1;
int dx[] = { +0, +0, +1, -1};
int dy[] = { +1, -1, +0, +0};

int X[] = { +0, +0, +1, -1, -1, +1, -1, +1}; // Kings Move
int Y[] = { -1, +1, +0, +0, +1, +1, -1, -1}; // Kings Move

int kx[] = { -2, -2, -1, -1, 1, 1, 2, 2}; // Knights Move
int ky[] = { -1, 1, -2, 2, -2, 2, -1, 1}; // Knights Move
bool valid(int r, int c, int n, int m)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}

//-------------------------------------------------------------------

//  priority_queue<int,vector<int>,greater<int>>pq;//smaller
/// some useful functions
vector <ll> findPrimeFactors(ll n);
vector<long long> allDivisiors(long long n);
bool isPrime(ll n);
ll power(ll n, ll p);
bool isPalindrome(string s);
int ask( int a , int b, int c);
ll onbit(ll N, ll pos);
ll offbit(ll N, ll pos);
ll flipbit(ll N, ll pos);
bool checkbit(ll N, ll pos);


ll bigMod(ll p, ll e, ll M) {ll ret = 1; for (; e > 0; e >>= 1) { if (e & 1) ret = (ret * p) % M; p = (p * p) % M;} return (ll)ret;}
ll modInverse(ll a, ll M) {return bigMod(a, M - 2, M);}
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {a = abs(a); b = abs(b); return (a / gcd(a, b)) * b;}

//-------------------------------------------------------------------
const ll inf = 2000000000;
const ll infll = 9000000000000000000;

const ll lim = 200000000;
const ll mod = power(2,32);
const int maxn = 100000005;;
//-------------------------------------------------------------------
void solve()
{

}
int main( )
{
	clock_t tStart = clock();
	FastIO;
	file();
	int t;
	cin >> t;
	while (t--)
	solve();

	


#ifdef ONLINEJUDGE
	fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

	return 0;
}
void file()
{
#ifdef ONLINEJUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
///Bit-valing.. pos is 0 based index and starts from left to right: [31 30 ... ... ... 3 2 1 0]
ll onbit(ll N, ll pos) {
	return N = N | (1 << pos);
}
ll offbit(ll N, ll pos) {
	return N = N & ~(1 << pos);
	//or return N = N & !(1<<pos);
}
ll flipbit(ll N, ll pos) {
	return N = N ^ (1 << pos);
}
bool checkbit(ll N, ll pos) {
	return (bool)(N & (1 << pos));
}


vector <ll> findPrimeFactors(ll n)
{
	vector<ll> primeFactors;
	while (n % 2 == 0)primeFactors.push_back(2), n = n / 2;

	for (ll i = 3; i * i <= n; i = i + 2)
	{
		while (n % i == 0)
		{
			primeFactors.push_back(i);
			n = n / i;
		}
	}
	if (n > 2) primeFactors.push_back(n);
	return primeFactors;
}
vector<long long> allDivisiors(long long n)
{
	vector<long long>divisors;
	ll limit = sqrt(n + 1);
	for (ll i = 1; i <= limit; i++)
	{
		if (n % i == 0)
		{
			if (n / i == i) divisors.push_back(i);
			else divisors.push_back(i), divisors.push_back(n / i);
		}
	}
	return divisors;
}
bool isPrime(ll n)
{
	if (n == 2 or n == 3) return true;
	if (n % 2 == 0 || n == 1) return false;
	for (ll i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
	return true;
}
ll power(ll n, ll p)
{
	if (p == 0) return 1;
	if (p == 1) return n;
	ll rem = 1;
	while (p)
	{
		if (p & 1) rem = rem * n;
		n = n * n;
		p = p / 2;
	}
	return rem;
}
bool isPalindrome(string s)
{
	int N = s.size();
	for ( int i = 0; i < N / 2; i++)
	{
		if (s[i] != s[N - 1 - i]) return 0;
	}
	return 1;
}
int ask( int a , int b, int c)
{
	cout << "? " << a << " " << b << " " << c << endl; cout.flush();
	int ch; cin >> ch;
	return ch;
}
//---------------Bitwise sieve--------
// bitset <mx> mark;
// uint primes[mxprm]; 
// uint mul[mxprm];  

// void sieve() { 
//     mark[0] = mark[1] = 1;
//     primes[psz++] = 2;
//     int lim = sqrt(mx * 1.0) + 2;
//     for (int i = 4; i < mx; i += 2) mark[i] = 1;
//     for (int i = 3; i < mx; i += 2) {
//         if (!mark[i]) {
//             primes[psz++] = i;
//             if (i <= lim)
//                 for (int j = i * i; j < mx; j += i)
//                     mark[j] = 1;
//         }
//     }
//     mul[0]=2;

//       for (int i = 1; i < psz; i++)
//         mul[i] = (primes[i] * mul[i - 1]);
// }
