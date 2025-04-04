class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* r) {
        function<int(TreeNode*)> d = [&](TreeNode* n) { return n ? 1 + max(d(n->left), d(n->right)) : 0; };
        function<TreeNode*(TreeNode*)> f = [&](TreeNode* n) {
            int l = d(n->left), r = d(n->right);
            return l == r ? n : f(l > r ? n->left : n->right);
        };
        return f(r);
    }
};
