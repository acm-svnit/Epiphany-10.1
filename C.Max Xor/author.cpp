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
    ll i,j,n,m,q,x;
    t()
    {
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());

        cin>>q;
        while(q--){
            cin>>x>>m;
            ll mxXor=-1;
            ll ans=-1;
            ll L=0;
            ll R=upper_bound(a.begin(),a.end(),m)-a.begin();
            if(R==0){
                cout<<ans<<"\n";
                continue;
            }
            R--;
            ans = R;
            for(j=30;j>=0 && L<=R;j--){
                ll M = (L+R)/2;
                ll bit = x & (1LL<<j);
                if(bit){//looking 0
                    ll temp=-1,l=L,r=R;
                    //search for last unset bit
                    while(l<=r){
                        ll mid = (l+r)/2;
                        if(a[mid] & (1LL<<j)){
                            r = mid-1;
                        }
                        else{
                            temp = mid;
                            l = mid+1;
                        }
                    }
                    if(temp!=-1){
                        R=temp;
                        ans = R;
                    }
                }
                else{//looking 1
                    ll temp=-1,l=L,r=R;
                    //search for first set bit
                    while(l<=r){
                        ll mid = (l+r)/2;
                        if(a[mid] & (1LL<<j)){
                            temp = mid;
                            r = mid-1;
                        }
                        else{
                            l = mid+1;
                        }
                    }
                    if(temp!=-1){
                        L = temp;
                    }
                }
            }
            cout<<a[ans]<<"\n";
        }

    }
}