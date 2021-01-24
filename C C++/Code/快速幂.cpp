typedef long long ll;
ll fastPow(ll a, ll b, ll m) {
    ll r = 1;
    while (b) {
        if (b & 1) {
            r = (r * a) % m;
        }
        b >>= 1;
        a = (a * a) % m;
    }
    return r;
}