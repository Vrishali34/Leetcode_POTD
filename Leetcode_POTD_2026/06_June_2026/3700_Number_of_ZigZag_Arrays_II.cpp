class Solution {
    static constexpr int mod = 1e9 + 7;
    using Matrix = vector<vector<int>>;

    Matrix multiply(const Matrix& a, const Matrix& b) {
        int stateCount = a.size();
        Matrix res(stateCount, vector<int>(stateCount));

        for (int fromState = 0; fromState < stateCount; fromState++)
            for (int midState = 0; midState < stateCount; midState++) {
                if (!a[fromState][midState]) continue;
                long long ways = a[fromState][midState];

                for (int toState = 0; toState < stateCount; toState++)
                    res[fromState][toState] =
                        (res[fromState][toState] +
                         ways * b[midState][toState]) % mod;
            }

        return res;
    }

    Matrix power(Matrix base, long long exp) {
        int stateCount = base.size();
        Matrix res(stateCount, vector<int>(stateCount));

        for (int state = 0; state < stateCount; state++)
            res[state][state] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int valueCount = r - l + 1, stateCount = valueCount * 2;

        Matrix trans(stateCount, vector<int>(stateCount));

        for (int value = 0; value < valueCount; value++) {
            for (int smaller = 0; smaller < value; smaller++)
                trans[valueCount + smaller][value] = 1;

            for (int greater = value + 1; greater < valueCount; greater++)
                trans[greater][valueCount + value] = 1;
        }

        vector<long long> init(stateCount);

        for (int value = 0; value < valueCount; value++) {
            init[value] = value;
            init[valueCount + value] = valueCount - value - 1;
        }

        auto mat = power(trans, n - 2);

        long long totalWays = 0;

        for (int row = 0; row < stateCount; row++)
            for (int col = 0; col < stateCount; col++)
                totalWays =
                    (totalWays +
                     1LL * mat[row][col] * init[col]) % mod;

        return totalWays;
    }
};
