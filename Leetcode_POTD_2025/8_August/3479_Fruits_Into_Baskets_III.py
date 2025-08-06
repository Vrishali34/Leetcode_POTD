import math

class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        num_baskets = len(baskets)
        tree_size = 1
        while tree_size < num_baskets:
            tree_size *= 2

        segment_tree = [-1] * (2 * tree_size)
        
        for i in range(num_baskets):
            segment_tree[tree_size + i] = baskets[i]

        for i in range(tree_size - 1, 0, -1):
            segment_tree[i] = max(segment_tree[2 * i], segment_tree[2 * i + 1])

        unplaced_count = 0
        for fruit_qty in fruits:
            if segment_tree[1] < fruit_qty:
                unplaced_count += 1
                continue

            current_node_index = 1
            while current_node_index < tree_size:
                if segment_tree[2 * current_node_index] >= fruit_qty:
                    current_node_index = 2 * current_node_index
                else:
                    current_node_index = 2 * current_node_index + 1
            
            segment_tree[current_node_index] = -1

            current_node_index //= 2
            while current_node_index > 0:
                segment_tree[current_node_index] = max(segment_tree[2 * current_node_index], segment_tree[2 * current_node_index + 1])
                current_node_index //= 2
                
        return unplaced_count
