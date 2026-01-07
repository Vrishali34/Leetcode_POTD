class Solution {
    long long whole_sum = 0, best_yield = 0;
    long long seek_sum(TreeNode* curr) {
        if (!curr) return 0;
        long long leaf_sum = curr->val + seek_sum(curr->left) + seek_sum(curr->right);
        best_yield = max(best_yield, (whole_sum - leaf_sum) * leaf_sum);
        return leaf_sum;
    }
public:
    int maxProduct(TreeNode* root) {
        whole_sum = get_total(root);
        seek_sum(root);
        return best_yield % 1000000007;
    }
    long long get_total(TreeNode* n) {
        return n ? n->val + get_total(n->left) + get_total(n->right) : 0;
    }
};
