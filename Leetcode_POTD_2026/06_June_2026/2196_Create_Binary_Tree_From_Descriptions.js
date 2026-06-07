/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(descriptions) {
    const node_registry = new Map();
    const child_lineage = new Set();
    
    for (const [head_val, sub_val, is_left] of descriptions) {
        if (!node_registry.has(head_val)) node_registry.set(head_val, new TreeNode(head_val));
        if (!node_registry.has(sub_val)) node_registry.set(sub_val, new TreeNode(sub_val));
        
        const head_node = node_registry.get(head_val);
        const sub_node = node_registry.get(sub_val);
        
        if (is_left === 1) {
            head_node.left = sub_node;
        } else {
            head_node.right = sub_node;
        }
        
        child_lineage.add(sub_val);
    }
    
    for (const [head_val] of descriptions) {
        if (!child_lineage.has(head_val)) {
            return node_registry.get(head_val);
        }
    }
};
