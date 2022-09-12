#include <bits/stdc++.h>

#define pii pair<int, int>
#define veci vector<int>
#define vecb vector<bool>
#define vecll vector<long long>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;


map<ll, vector<vecll>> pow_cache;


vector<vecll > mMult(vector<vecll > &a, vector<vecll > &b, int k) {
    vector<vecll > temp_result = vector<vecll >(k, vecll(k, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                temp_result[i][j] += (a[i][l] * b[l][j]);
                temp_result[i][j];
            }
        }
    }
    return temp_result;

}

vector<vecll > &mPow(vector<vecll > &m, ll pow, int k) {
    if (pow == 1) {
        pow_cache[1] = m;
        return m;
    } else {
        if (pow_cache.find(pow) == pow_cache.end()) {
            pow_cache[pow] = mMult(mPow(m, pow / 2, k), mPow(m, pow / 2 + pow % 2, k), k);
        }
        return pow_cache[pow];
    }
}

ld summ_g(vector<vecll > &g, int k) {
    ld summ = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            summ += (ld) g[i][j];
        }
    }
    return summ;
}


void solve() {
    int k;
    cin >> k;
    vector<vecll > g(k, vecll(k, 0));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> g[i][j];
        }
    }

    if (k == 1 && g[0][0] == 0) {
        cout << 0;
        return;
    }


    ll pow = 2;
    ld prev_val = summ_g(g, k);
    ld curr_val = summ_g(mPow(g, pow, k), k);
    ld prev_lim = curr_val / prev_val;

    ld e = 1e-2;


    while (pow < 100) {
        pow++;
        prev_val = curr_val;
        curr_val = summ_g(mPow(g, pow, k), k);
        ld lim = curr_val / prev_val;

        if (abs(lim - prev_lim) < e) {
            cout << fixed << setprecision(2) << lim;
            break;
        }
        prev_lim = lim;
    }
}

int main() {
    solve();
    return 0;

}

