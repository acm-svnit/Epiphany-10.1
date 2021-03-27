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



int main()
{
    fastio;
    ll i,j,n,x,y,k;
    t()
    {
        cin>>n>>x>>y>>k;
        k = k%4;
        ll offset = min({x,n-1-x,y,n-1-y});
        x -= offset;
        y -= offset;
        n -= 2*offset;
        for(i=x,j=y;k ;k--){
            ll tempx = j;
            ll tempy = n-1-i;
            i = tempx;
            j = tempy;
        }
        x = i + offset;
        y = j + offset;
        cout<<x<<" "<<y<<"\n";



    }
}
