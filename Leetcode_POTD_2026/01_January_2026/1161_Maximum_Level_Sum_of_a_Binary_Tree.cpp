class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int peak_lvl = 1, curr_lvl = 1;
        long long peak_sum = LLONG_MIN;
        queue<TreeNode*> node_hub;
        node_hub.push(root);
        while (!node_hub.empty()) {
            long long span_sum = 0;
            int span_sz = node_hub.size();
            for (int i = 0; i < span_sz; ++i) {
                TreeNode* curr_node = node_hub.front();
                node_hub.pop();
                span_sum += curr_node->val;
                if (curr_node->left) node_hub.push(curr_node->left);
                if (curr_node->right) node_hub.push(curr_node->right);
            }
            if (span_sum > peak_sum) {
                peak_sum = span_sum;
                peak_lvl = curr_lvl;
            }
            curr_lvl++;
        }
        return peak_lvl;
    }
};
