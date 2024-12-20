class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* a) {
        queue<TreeNode*> b;
        b.push(a);
        bool c = false;
        while (!b.empty()) {
            int d = b.size();
            vector<TreeNode*> e;
            for (int f = 0; f < d; f++) {
                TreeNode* g = b.front();
                b.pop();
                if (!g) continue;
                e.push_back(g);
                b.push(g->left);
                b.push(g->right);
            }
            if (c) {
                int h = 0, i = e.size() - 1;
                while (h < i) swap(e[h++]->val, e[i--]->val);
            }
            c = !c;
        }
        return a;
    }
};
