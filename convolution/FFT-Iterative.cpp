const double PI = acos(-1);
typedef complex<double> cd;
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    // bit reversal permutation
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j)swap(a[i], a[j]);
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)j ^= bit;
        j ^= bit;
    }
    for (int ln = 2; ln <= n; ln <<= 1) {
        double angle = 2 * PI / ln;
        cd wln(cos(angle), sin(angle) * (invert ? -1 : 1));
        for (int j = 0; j < n; j += ln) {
            cd w(1);
            for (int i = 0; i < ln / 2; i++) {
                cd temp = a[i + j];
                a[i + j] = a[i + j] + w * a[i + j + ln / 2];
                a[i + j + ln / 2] = temp - w * a[i + j + ln / 2];
                w *= wln;
                if (invert) {
                    a[i + j] /= 2;
                    a[i + j + ln / 2] /= 2;
                }
            }
        }
    }
}
//don't send the same vector twice 
vector<ll> conv(const vector<ll> &a,const vector<ll> &b) {
    int n = 1;
    while (n < sz(a) + sz(b))n <<= 1;
    vector<cd> fa(all(a)), fb(all(b));
    fa.resize(n);
    fb.resize(n);
    fft(fa, 0);
    fft(fb, 0);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, 1);
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = round(fa[i].real());
    }
    return res;
}
vector<ll>polyPow(vector<ll>a,ll k){
    vector<ll>ans = {1};
    while(k){
        if(k&1){
            ans = conv(ans,a);
        }
        k>>=1;
        a = conv(a,a);
    }
    return ans;
}
