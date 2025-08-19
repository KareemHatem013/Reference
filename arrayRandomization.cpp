mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }

    shuffle(ans.begin(), ans.end(), rng);
    //answer is shuffled
}
