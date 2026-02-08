class Solution {
public:
    int check_depth(TreeNode* curr_nd) {
        if (!curr_nd) return 0;
        int L = check_depth(curr_nd->left), R = check_depth(curr_nd->right);
        if (L == -1 || R == -1 || abs(L - R) > 1) return -1;
        return max(L, R) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return check_depth(root) != -1;
    }
};
