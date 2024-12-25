class Solution {
public:
    vector<int> largestValues(TreeNode* z) {
        vector<int> a;
        if (!z) return a;
        queue<TreeNode*> b;
        b.push(z);
        while (!b.empty()) {
            int c = b.size(), d = INT_MIN;
            while (c--) {
                auto e = b.front(); b.pop();
                d = max(d, e->val);
                if (e->left) b.push(e->left);
                if (e->right) b.push(e->right);
            }
            a.push_back(d);
        }
        return a;
    }
};
