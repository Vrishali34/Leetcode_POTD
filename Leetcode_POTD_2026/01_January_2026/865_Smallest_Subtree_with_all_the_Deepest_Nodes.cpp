class Solution {
public:
    pair<TreeNode*, int> seek_deep_node(TreeNode* curr_node) {
        if (!curr_node) return {nullptr, 0};
        auto left_side = seek_deep_node(curr_node->left);
        auto right_side = seek_deep_node(curr_node->right);
        if (left_side.second > right_side.second) return {left_side.first, left_side.second + 1};
        if (right_side.second > left_side.second) return {right_side.first, right_side.second + 1};
        return {curr_node, left_side.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return seek_deep_node(root).first;
    }
};
