#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
const ll INF = 1e16;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x, y,z) cout << #x << " = " << x << "   " << #y << " = " << y << " "<<#z<<" = "<<z<<"\n";
#define debugarray(arr,n) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , \n";}

ll modularexponentiation(ll x,ll n,ll M) //iterative method
{
    ll ans=1;
    while(n>0)
    {
        if(n%2==1)
         ans=(ans*x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return ans;
}
ll modInverse(ll A,ll M)//Fermat's Little Theorem
{
    ll x= modularexponentiation(A,M-2,M);
    return x;
}
int main()
{
    fastio;
    ll i,j,x,y;
    const ll MX = 2000005;
    vector<ll>fact(MX);
    fact[0]=1;
    for(i=1;i<MX;i++)   fact[i] = (i*fact[i-1])%MOD;
    t()
    {
        cin>>x>>y;
        x = abs(x);
        y = abs(y);
        ll ans = fact[x+y];
        ans = (ans * modInverse(fact[x],MOD))%MOD;
        ans = (ans * modInverse(fact[y],MOD))%MOD;
        cout<<ans<<"\n";

    }
}