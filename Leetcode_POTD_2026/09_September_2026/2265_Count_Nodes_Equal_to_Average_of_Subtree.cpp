class Solution {
public:
    int match_tally;

    array<int, 2> traverse_sum_cnt(TreeNode* node) {
        if (!node) return {0, 0};
        auto left_pair = traverse_sum_cnt(node->left);
        auto right_pair = traverse_sum_cnt(node->right);
        int node_cnt = left_pair[1] + right_pair[1] + 1;
        int node_sum = left_pair[0] + right_pair[0] + node->val;
        if (node_sum / node_cnt == node->val) match_tally++;
        return {node_sum, node_cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        match_tally = 0;
        traverse_sum_cnt(root);
        return match_tally;
    }
};
