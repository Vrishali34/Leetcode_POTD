import collections

class Solution(object):
    def deleteDuplicateFolder(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: List[List[str]]
        """
        class TerraNode:
            def __init__(self):
                self.k_children_k = collections.OrderedDict() # Using OrderedDict for consistent hash generation
                self.v_hash_v = ""
                self.b_marked_b = False

        def construct_arbor_trie(p_paths_p):
            l_arbor_root_l = TerraNode()
            for l_path_l in p_paths_p:
                l_current_l = l_arbor_root_l
                for l_comp_l in l_path_l:
                    if l_comp_l not in l_current_l.k_children_k:
                        l_current_l.k_children_k[l_comp_l] = TerraNode()
                    l_current_l = l_current_l.k_children_k[l_comp_l]
            return l_arbor_root_l

        def calculate_cryptic_hash(p_node_p, p_hash_counts_p):
            if p_node_p.k_children_k:
                l_cur_sig_l = "("
                for l_name_l, l_child_l in p_node_p.k_children_k.items():
                    l_cur_sig_l += l_name_l + calculate_cryptic_hash(l_child_l, p_hash_counts_p)
                l_cur_sig_l += ")"
                p_node_p.v_hash_v = l_cur_sig_l
                p_hash_counts_p[l_cur_sig_l] = p_hash_counts_p.get(l_cur_sig_l, 0) + 1
            return p_node_p.v_hash_v

        def mark_celestial_duplicates(p_node_p, p_hash_counts_p):
            if p_node_p.v_hash_v and p_hash_counts_p[p_node_p.v_hash_v] > 1:
                p_node_p.b_marked_b = True
            for l_child_l in p_node_p.k_children_k.values():
                mark_celestial_duplicates(l_child_l, p_hash_counts_p)

        def gather_survivors(p_node_p, p_current_path_p, p_results_p):
            if p_node_p.b_marked_b:
                return
            if p_current_path_p:
                p_results_p.append(list(p_current_path_p))
            for l_name_l, l_child_l in p_node_p.k_children_k.items():
                p_current_path_p.append(l_name_l)
                gather_survivors(l_child_l, p_current_path_p, p_results_p)
                p_current_path_p.pop()

        l_root_node_l = construct_arbor_trie(paths)
        l_hash_tally_l = {}
        calculate_cryptic_hash(l_root_node_l, l_hash_tally_l)
        mark_celestial_duplicates(l_root_node_l, l_hash_tally_l)
        l_final_remains_l = []
        l_current_trail_l = []
        gather_survivors(l_root_node_l, l_current_trail_l, l_final_remains_l)
        return l_final_remains_l
