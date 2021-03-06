#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
int main(){
    int n;
    cin >> n;
    vii v;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        v.pb(mp(x, i));
    }
    sort(all(v));
    reverse(all(v));
    int mini = v[0].second;
    int maxi = v[0].second;
    ll ans = 0;
    for(int i = 1; i < n; i++) {

        int x = v[i].second;
        if(x < mini || x > maxi) ans += 1;
        else ans += 2;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    cout << ans << "\n";

    return 0;
}