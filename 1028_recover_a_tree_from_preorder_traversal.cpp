class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*> stk;
        for (int i = 0; i < s.size();) {
            int d = 0, v = 0;
            while (s[i] == '-') d++, i++;
            while (i < s.size() && isdigit(s[i])) v = v * 10 + (s[i++] - '0');
            TreeNode* n = new TreeNode(v);
            if (d == stk.size()) {
                if (!stk.empty()) stk.back()->left = n;
            } else {
                stk[d - 1]->right = n;
                stk.resize(d);
            }
            stk.push_back(n);
        }
        return stk[0];
    }
};
