#include <iostream>
#include <vector>
#include <algorithm>


struct query {
    size_t first;
    size_t second;
    size_t index;
};

int64_t cc[1000002];
query q[200002];
size_t left, right, bucket_size;
int64_t last_res = 0;

void solve(int32_t const v[],
           size_t t,
           int64_t res[]) {

    left = q[0].first;
    right = q[0].second;

    for (size_t i=left; i<=right; ++i){
        last_res += 2*v[i]*cc[v[i]] + v[i];
        cc[v[i]]++;
    }

    res[q[0].index] = last_res;

    for (size_t j=1; j<t; ++j) {
        auto r = q[j];
        for (size_t i=left; i<r.first; ++i) {
            if (cc[v[i]] > 0) {
                cc[v[i]]--;
                last_res -= 2*v[i]*cc[v[i]] + v[i];
            }
        }

        for (size_t i=r.first; i<left; ++i) {
            last_res += 2*v[i]*cc[v[i]] + v[i];
            cc[v[i]]++;
        }

        for (size_t i=std::max(right+1, r.first); i<=r.second; ++i) {
            last_res += 2*v[i]*cc[v[i]] + v[i];
            cc[v[i]]++;
        }

        for (size_t i=r.second+1; i<=right; ++i) {
            if (cc[v[i]] > 0) {
                cc[v[i]]--;
                last_res -= 2*v[i]*cc[v[i]] + v[i];
            }
        }

        res[r.index] = last_res;
        left = r.first;
        right = r.second;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin.tie(nullptr);
    size_t n, t, l, r;
    std::cin >> n >> t;
    int32_t test[n];
    bucket_size = (size_t) sqrt(n);

    for (size_t i=0; i<n; ++i){
        std::cin >> test[i];
    }

    for (size_t i=0; i<t; ++i){
        std::cin >> l >> r;
        l--;
        r--;
        q[i].first = l;
        q[i].second = r;
        q[i].index = i;
    }

    int64_t res[t];

    std::sort(q, q+t,
              [](const query& a, const query& b) -> bool{
                  if (a.first / bucket_size < b.first / bucket_size)
                      return true;
                  if (a.first / bucket_size > b.first / bucket_size)
                      return  false;
                  return (a.second < b.second);
              });

    solve(test, t, res);

    for (auto sol : res)
        std::cout << sol << "\n";

    return 0;
}