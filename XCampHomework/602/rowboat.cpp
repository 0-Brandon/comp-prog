#include <bits/stdc++.h>

#define MOD 1000000007

typedef long long ll;

// Coordinate compression for handling large ranges
std::vector<int> compressCoordinates(const std::vector<std::pair<int, int>>& ranges) {
    std::vector<int> values;
    for (auto& range : ranges) {
        values.push_back(range.first);
        values.push_back(range.second);
    }
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    return values;
}

// Fenwick Tree for range sum queries
class FenwickTree {
public:
    std::vector<ll> tree;
    int size;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void add(int index, ll value) {
        while (index <= size) {
            tree[index] = (tree[index] + value) % MOD;
            index += index & -index;
        }
    }

    ll sum(int index) {
        ll result = 0;
        while (index > 0) {
            result = (result + tree[index]) % MOD;
            index -= index & -index;
        }
        return result;
    }

    ll rangeSum(int left, int right) {
        return (sum(right) - sum(left - 1) + MOD) % MOD;
    }
};

// Solve the problem
ll countConfigurations(int n, const std::vector<std::pair<int, int>>& ranges) {
    // Coordinate compression
    std::vector<int> compressed = compressCoordinates(ranges);
    std::map<int, int> indexMap;
    for (int i = 0; i < compressed.size(); ++i) {
        indexMap[compressed[i]] = i + 1;
    }

    int maxIndex = compressed.size();
    std::vector<FenwickTree> dpTrees(n + 1, FenwickTree(maxIndex));

    // Initial state: No boats have been sent yet
    dpTrees[0].add(1, 1); // "Zero boats" state (compressed index 1)

    for (int i = 1; i <= n; ++i) {
        int ai = indexMap[ranges[i - 1].first];
        int bi = indexMap[ranges[i - 1].second];

        // Case 1: This school does not send boats
        ll noBoats = dpTrees[i - 1].sum(maxIndex);
        dpTrees[i].add(1, noBoats);

        // Case 2: This school sends boats in the range [ai, bi]
        for (int j = ai; j <= bi; ++j) {
            ll count = dpTrees[i - 1].rangeSum(1, j - 1); // Boats must be strictly increasing
            dpTrees[i].add(j, count);
        }
    }

    // Final result: Sum all valid configurations for the last school
    ll result = dpTrees[n].sum(maxIndex) - 1; // Subtract 1 to exclude the case where no boats are sent at all
    return (result + MOD) % MOD;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ranges[i].first >> ranges[i].second;
    }

    std::cout << countConfigurations(n, ranges) << std::endl;
    return 0;
}
