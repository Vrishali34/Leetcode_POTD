#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int N; cin >> N;
        vector<ll> A(N+1);
        for(int i=1;i<=N;i++) cin >> A[i];

        vector<ll> pref(N+2,0), suff(N+2,0);
        for(int i=1;i<=N;i++) pref[i] = std::gcd(pref[i-1], A[i]);
        for(int i=N;i>=1;i--) suff[i] = std::gcd(suff[i+1], A[i]);

        int ans = 0;
        for(int i=1;i<=N;i++){
            ll g_excl = std::gcd(pref[i-1], suff[i+1]);
            if(g_excl > 1) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
165_Compare_Version_Numbers.cpp
