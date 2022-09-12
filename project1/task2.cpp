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


vector<vecll > mMult(vector<vecll>& a, vector<vecll>& b, ll p) {
    vector<vecll > temp_result = vector<vecll >(2, vecll(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l < 2; l++) {
                temp_result[i][j] += (a[i][l] * b[l][j]) % p;
                temp_result[i][j] %= p;
            }
        }
    }
    return temp_result;

}

vector<vecll>& mPow(vector<vecll > &m, ll pow, ll p) {
    if (pow == 1) {
        pow_cache[1] = m;
        return m;
    }

    else{
        if (pow_cache.find(pow) == pow_cache.end()){
            pow_cache[pow] = mMult(mPow(m, pow / 2, p), mPow(m, pow / 2 + pow % 2, p), p);
        }
        return pow_cache[pow];
    }
}


void solve() {
    ll n, p;
    cin >> n >> p;

    vector<vecll > m(2, vecll(2, 0));
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 1;

    auto t = mPow(m, n, p);

    cout << t[0][1] % p << endl;
}

int main() {
    solve();
    return 0;

}

