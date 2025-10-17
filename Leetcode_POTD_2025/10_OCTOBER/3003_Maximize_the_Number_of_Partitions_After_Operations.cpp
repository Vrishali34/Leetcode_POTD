#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
private:
    map<tuple<int, int, bool>, int> dp_memo;

    int pop_count(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    int stellar_dp(int i, int m, bool u, const string& s_map, int k_bound) {
        if (i == s_map.length()) {
            return 1;
        }

        if (dp_memo.count({i, m, u})) {
            return dp_memo[{i, m, u}];
        }

        int max_res = 0;

        
        int orig_bit = (1 << (s_map[i] - 'a'));
        int next_mask = m | orig_bit;
        
        if (pop_count(next_mask) <= k_bound) {
            max_res = max(max_res, stellar_dp(i + 1, next_mask, u, s_map, k_bound));
        } else {
            max_res = max(max_res, 1 + stellar_dp(i + 1, orig_bit, u, s_map, k_bound));
        }

        
        if (!u) {
            for (int j = 0; j < 26; ++j) {
                int new_mask = m | (1 << j);
                
                if (pop_count(new_mask) <= k_bound) {
                    max_res = max(max_res, stellar_dp(i + 1, new_mask, true, s_map, k_bound));
                } else {
                    max_res = max(max_res, 1 + stellar_dp(i + 1, (1 << j), true, s_map, k_bound));
                }
            }
        }
        
        return dp_memo[{i, m, u}] = max_res;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        dp_memo.clear();
        return stellar_dp(0, 0, false, s, k);
    }
};
