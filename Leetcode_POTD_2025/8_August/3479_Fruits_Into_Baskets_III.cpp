#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int n = baskets.size();
        int N = 1;
        while (N < n) {
            N *= 2;
        }

        std::vector<int> seg(2 * N, -1);
        for (int i = 0; i < n; ++i) {
            seg[N + i] = baskets[i];
        }

        for (int i = N - 1; i > 0; --i) {
            seg[i] = std::max(seg[2 * i], seg[2 * i + 1]);
        }

        int unplaced_count = 0;
        for (int fruit_qty : fruits) {
            if (seg[1] < fruit_qty) {
                unplaced_count++;
                continue;
            }

            int idx = 1;
            while (idx < N) {
                if (seg[2 * idx] >= fruit_qty) {
                    idx = 2 * idx;
                } else {
                    idx = 2 * idx + 1;
                }
            }

            seg[idx] = -1;

            idx /= 2;
            while (idx > 0) {
                seg[idx] = std::max(seg[2 * idx], seg[2 * idx + 1]);
                idx /= 2;
            }
        }
        return unplaced_count;
    }
};
