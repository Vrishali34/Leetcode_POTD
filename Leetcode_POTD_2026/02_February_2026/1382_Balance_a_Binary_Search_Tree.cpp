class Solution {
    vector<TreeNode*> nodes_flow;
    void gather_flow(TreeNode* curr) {
        if (!curr) return;
        gather_flow(curr->left);
        nodes_flow.push_back(curr);
        gather_flow(curr->right);
    }
    TreeNode* build_axis(int low_idx, int high_idx) {
        if (low_idx > high_idx) return nullptr;
        int mid_pt = low_idx + (high_idx - low_idx) / 2;
        TreeNode* pivot = nodes_flow[mid_pt];
        pivot->left = build_axis(low_idx, mid_pt - 1);
        pivot->right = build_axis(mid_pt + 1, high_idx);
        return pivot;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        gather_flow(root);
        return build_axis(0, nodes_flow.size() - 1);
    }
};
