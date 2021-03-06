#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x,ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
    if(n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll z=sqrt(n);
        rep(i,z-1) if(n%(i+2)==0) return false;
        return true;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N=1000000;
    vi primes;
    set<ll> s;
    vi sieve(N+1,1);
    sieve[0]=0;
    sieve[1]=0;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]==1)
        {
            primes.pb(i);
            s.insert(i);
            for(ll j=i*i;j<=N;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    ll ans=0,p;
    rep(i,sz(primes))
    {
        ll n=0;
        for(ll j=i;j<sz(primes);j++)
        {
            n+=primes[j];
            if(n>N) break;
            else if(s.find(n)!=s.end() && j-i+1>=ans)
            {
                ans=j-i+1;
                p=n;
            }
        }
    }
    cout<<p;
    return 0;
}
