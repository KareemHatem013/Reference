class Hashing{
private:
    const ll mod = (1ll << 61) - 1;
    static ll base;
    int sz;
    vector<ll>hPre,pow;
    //pow[i] = base^i
public:
    Hashing(const string&s,char st = 'a'){ // 1-based
        sz = sz(s);
        hPre  = pow = vector<ll>(sz + 1);
        pow[0] = 1;
        for(int i = 1; i <= sz;i++){
            pow[i] = (__int128_t)pow[i-1]*base % mod;
            hPre[i] = ((__int128_t)(s[i-1] - st + 1)*pow[i-1]  + hPre[i-1] )%mod;
        }
    }
    ll get(int l,int r){ // l,r is 0-based
        return ((__int128_t)(hPre[r+1] - hPre[l])*pow[sz - r - 1]%mod + mod)%mod;
    }
};
ll rng(ll l = (1ll << 40), ll r = (1ll << 60)) {
    static std::mt19937 gen(
            std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution<long long>(l, r)(gen);
}

ll Hashing::base = rng();
