#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PI;
typedef pair<LD,LD> PD;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())
// }}}

int n,m,v;

int main() {
    scanf("%d%d%d",&n,&m,&v);
    if (m<n-1) {
        printf("-1\n");
        return 0;
    }
    LL rr=(((LL)(n-1))*((LL)(n-2)))/2LL+1LL;
    if ((LL)m>rr) {
        printf("-1\n");
        return 0;
    }

    int a;
    VI r;
    if (v==1) r.PB(2),a=2;
    else r.PB(1),a=1;
    r.PB(v);
    FOR(i,1,n) if (i!=v && i!=a) r.PB(i);

    REP(i,SIZE(r)-1) printf("%d %d\n",r[i],r[i+1]);
    m-=n-1;

    FOR(i,1,SIZE(r)-1)
        FOR(j,i+2,SIZE(r)-1) {
            if (!m) goto et;
            m--;
            printf("%d %d\n",r[i],r[j]);
        }

et: 
    return 0;
}
