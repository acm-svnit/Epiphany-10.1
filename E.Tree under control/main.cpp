#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll D = 20;
ll n,a[200005];
vector<ll> g[200005];
ll par[200005][22];
ll w[200005];
ll dep[200005];
ll sum[200005];
void dfs(ll s ,ll pr, ll d)
{
        par[s][0] = pr;
        dep[s] = d;
        sum[s] = 1;
        for(auto i : g[s])
        {
                dfs(i , s , d + w[i]);
        }
}
void SetTable()
{
        for(ll i=1;i<=20;i++)
        {
                for(ll j=1;j<=n;j++)
                {
                        par[j][i] = par[par[j][i-1]][i-1];
                }
        }
}
void upd(ll s,ll val)
{
        for(ll d = D;d >= 0;d--)
        {
                if(dep[par[s][d]] >= val)
                {
                        s = par[s][d];
                }
        }
        if(s == 1) return;
        s = par[s][0];
        sum[s]--;
}
void go(ll s)
{
        if(s != 1)
        {
                upd(s , dep[s] - a[s]);
        }
        for(auto i : g[s])
        {
                go(i);
                sum[s] += sum[i];
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n;
        for(ll i=1;i<=n;i++) cin >> a[i];

        for(ll i=2;i<=n;i++)
        {
                ll x,y;
                cin >> x >> y;
                g[x].push_back(i);
                w[i] = y;
        }
        dfs(1 , 1, 0);
        SetTable();
        go(1);
        for(ll i=1;i<=n;i++) cout << sum[i] - 1 << " ";
        return 0;
}
