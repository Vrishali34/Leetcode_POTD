class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int path_val = 0) {
        if (!root) return 0;
        path_val = (path_val << 1) | root->val;
        if (!root->left && !root->right) return path_val;
        return sumRootToLeaf(root->left, path_val) + sumRootToLeaf(root->right, path_val);
    }
};
