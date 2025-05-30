class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        """
        :type edges: List[int]
        :type node1: int
        :type node2: int
        :rtype: int
        """
        node_count = len(edges)

        path_a = [-1] * node_count
        path_b = [-1] * node_count

        current_node = node1
        distance = 0
        while current_node != -1 and path_a[current_node] == -1:
            path_a[current_node] = distance
            distance += 1
            current_node = edges[current_node]

        current_node = node2
        distance = 0
        while current_node != -1 and path_b[current_node] == -1:
            path_b[current_node] = distance
            distance += 1
            current_node = edges[current_node]

        min_overall_max = -1
        best_vertex = -1

        for i in range(node_count):
            if path_a[i] != -1 and path_b[i] != -1:
                current_max = max(path_a[i], path_b[i])
                if best_vertex == -1 or current_max < min_overall_max:
                    min_overall_max = current_max
                    best_vertex = i
                elif current_max == min_overall_max:
                    best_vertex = min(best_vertex, i)
        return best_vertex
