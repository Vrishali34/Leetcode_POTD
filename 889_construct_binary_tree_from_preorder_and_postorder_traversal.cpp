class Solution {
public:
    TreeNode* bz(vector<int>& p, vector<int>& q) {
        if (p.empty()) return nullptr;
        TreeNode* n = new TreeNode(p[0]);
        if (p.size() == 1) return n;
        int d = find(q.begin(), q.end(), p[1]) - q.begin() + 1;
        vector<int> a(p.begin() + 1, p.begin() + d + 1), b(q.begin(), q.begin() + d);
        vector<int> c(p.begin() + d + 1, p.end()), e(q.begin() + d, q.end() - 1);
        n->left = bz(a, b);
        n->right = bz(c, e);
        return n;
    }
    TreeNode* constructFromPrePost(vector<int>& p, vector<int>& q) {
        return bz(p, q);
    }
};
