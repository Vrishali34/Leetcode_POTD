class Solution {
    struct RangeInfo {
        vector<int> rem_ways;
        int whole_mod;
        RangeInfo(int mod_k) : rem_ways(mod_k, 0), whole_mod(1) {}
    };

    struct SegTree {
        int leaf_size;
        int mod_k;
        vector<RangeInfo> tree_arr;

        SegTree(vector<int>& nums, int k) {
            mod_k = k;
            leaf_size = 1;
            while (leaf_size < (int)nums.size()) leaf_size <<= 1;

            tree_arr.reserve(leaf_size * 2);
            for (int i = 0; i < leaf_size * 2; i++) tree_arr.emplace_back(k);

            for (int i = 0; i < (int)nums.size(); i++) {
                int rem_val = nums[i] % k;
                tree_arr[leaf_size + i].rem_ways[rem_val] = 1;
                tree_arr[leaf_size + i].whole_mod = rem_val;
            }
            for (int i = leaf_size - 1; i > 0; i--)
                tree_arr[i] = combine_info(tree_arr[i << 1], tree_arr[i << 1 | 1]);
        }

        RangeInfo combine_info(const RangeInfo& left_info, const RangeInfo& right_info) {
            RangeInfo merged_info(mod_k);
            for (int r = 0; r < mod_k; r++)
                merged_info.rem_ways[r] = left_info.rem_ways[r];

            for (int r = 0; r < mod_k; r++) {
                if (right_info.rem_ways[r] == 0) continue;
                int new_rem = (left_info.whole_mod * r) % mod_k;
                merged_info.rem_ways[new_rem] += right_info.rem_ways[r];
            }
            merged_info.whole_mod = (left_info.whole_mod * right_info.whole_mod) % mod_k;
            return merged_info;
        }

        void update_leaf(int idx_pos, int new_val) {
            int node_pos = leaf_size + idx_pos;
            int rem_val = new_val % mod_k;

            fill(tree_arr[node_pos].rem_ways.begin(), tree_arr[node_pos].rem_ways.end(), 0);
            tree_arr[node_pos].rem_ways[rem_val] = 1;
            tree_arr[node_pos].whole_mod = rem_val;

            node_pos >>= 1;
            while (node_pos > 0) {
                tree_arr[node_pos] = combine_info(tree_arr[node_pos << 1], tree_arr[node_pos << 1 | 1]);
                node_pos >>= 1;
            }
        }

        RangeInfo query_range(int range_lo, int range_hi) {
            RangeInfo left_acc(mod_k), right_acc(mod_k);
            range_lo += leaf_size;
            range_hi += leaf_size;

            while (range_lo < range_hi) {
                if (range_lo & 1) { left_acc = combine_info(left_acc, tree_arr[range_lo]); range_lo++; }
                if (range_hi & 1) { range_hi--; right_acc = combine_info(tree_arr[range_hi], right_acc); }
                range_lo >>= 1;
                range_hi >>= 1;
            }
            return combine_info(left_acc, right_acc);
        }
    };

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegTree seg_tree(nums, k);
        vector<int> query_ans;

        for (auto& single_query : queries) {
            seg_tree.update_leaf(single_query[0], single_query[1]);
            RangeInfo range_res = seg_tree.query_range(single_query[2], nums.size());
            query_ans.push_back(range_res.rem_ways[single_query[3]]);
        }
        return query_ans;
    }
};
