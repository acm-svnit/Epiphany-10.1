#include <bits/stdc++.h>

#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<ll> get_final_coordinates(ll n,vector<ll> initial_coordinates,ll k){
    k = k%4;
    if(k==0) return initial_coordinates;

    vector<ll> new_coordinates(2,0);
    ll x = initial_coordinates[0];
    ll y = initial_coordinates[1];

    if(x==y){
        new_coordinates[0] = n - y;
        new_coordinates[1] = n - x;
        new_coordinates[0] = n - new_coordinates[0];
    }else if(x+y==n){
        new_coordinates[0] = y;
        new_coordinates[1] = x;
        new_coordinates[1] = n - new_coordinates[1];
    }else if((y>x && x+y<n) || (x>y && x+y>n)){
        new_coordinates[0] = n - y;
        new_coordinates[1] = n - x;
        new_coordinates[0] = n - new_coordinates[0];
    }else if((x>y && x+y<n) || (x<y && x+y>n)){
        new_coordinates[0] = y;
        new_coordinates[1] = x;
        new_coordinates[1] = n - new_coordinates[1];
    }

    return get_final_coordinates(n,new_coordinates,k-1);
}

void solve(){
    ll n,x,y,k;
    cin >> n >> x >> y >> k;
    vector<ll> initial_coordinates = {x,y};
    n--;
    vector<ll> final_coordinates = get_final_coordinates(n,initial_coordinates,k);
    cout<<final_coordinates[0]<<" "<<final_coordinates[1]<<endl;
}

int main(){
    fastio
    ll t;
    cin >> t;
    while(t--) solve();
}