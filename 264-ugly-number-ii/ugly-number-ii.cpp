class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> results(1, 1);

        int i = 0, j = 0, k = 0;

        while (results.size() < n) {
            int next = min({
                results[i] * 2,
                results[j] * 3,
                results[k] * 5
            });

            results.push_back(next);

            if (next == results[i] * 2) i++;
            if (next == results[j] * 3) j++;
            if (next == results[k] * 5) k++;
        }

        return results.back();
    }
};