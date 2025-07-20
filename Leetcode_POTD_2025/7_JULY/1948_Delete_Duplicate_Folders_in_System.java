import java.util.*;

class Solution {
    class TerraNode {
        Map<String, TerraNode> k_children_k = new TreeMap<>(); // Using TreeMap for consistent hash generation
        String v_hash_v = "";
        boolean b_marked_b = false;
    }

    TerraNode construct_arbor_trie(List<List<String>> p_paths_p) {
        TerraNode l_arbor_root_l = new TerraNode();
        for (List<String> l_path_l : p_paths_p) {
            TerraNode l_current_l = l_arbor_root_l;
            for (String l_comp_l : l_path_l) {
                l_current_l.k_children_k.putIfAbsent(l_comp_l, new TerraNode());
                l_current_l = l_current_l.k_children_k.get(l_comp_l);
            }
        }
        return l_arbor_root_l;
    }

    String calculate_cryptic_hash(TerraNode p_node_p, Map<String, Integer> p_hash_counts_p) {
        if (!p_node_p.k_children_k.isEmpty()) {
            StringBuilder l_cur_sig_l = new StringBuilder("(");
            for (Map.Entry<String, TerraNode> entry : p_node_p.k_children_k.entrySet()) {
                l_cur_sig_l.append(entry.getKey()).append(calculate_cryptic_hash(entry.getValue(), p_hash_counts_p));
            }
            l_cur_sig_l.append(")");
            p_node_p.v_hash_v = l_cur_sig_l.toString();
            p_hash_counts_p.put(p_node_p.v_hash_v, p_hash_counts_p.getOrDefault(p_node_p.v_hash_v, 0) + 1);
        }
        return p_node_p.v_hash_v;
    }

    void mark_celestial_duplicates(TerraNode p_node_p, Map<String, Integer> p_hash_counts_p) {
        if (!p_node_p.v_hash_v.isEmpty() && p_hash_counts_p.get(p_node_p.v_hash_v) > 1) {
            p_node_p.b_marked_b = true;
        }
        for (TerraNode l_child_l : p_node_p.k_children_k.values()) {
            mark_celestial_duplicates(l_child_l, p_hash_counts_p);
        }
    }

    void gather_survivors(TerraNode p_node_p, List<String> p_current_path_p, List<List<String>> p_results_p) {
        if (p_node_p.b_marked_b) {
            return;
        }
        if (!p_current_path_p.isEmpty()) {
            p_results_p.add(new ArrayList<>(p_current_path_p));
        }
        for (Map.Entry<String, TerraNode> entry : p_node_p.k_children_k.entrySet()) {
            p_current_path_p.add(entry.getKey());
            gather_survivors(entry.getValue(), p_current_path_p, p_results_p);
            p_current_path_p.remove(p_current_path_p.size() - 1);
        }
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> p_paths_p) {
        TerraNode l_root_node_l = construct_arbor_trie(p_paths_p);
        Map<String, Integer> l_hash_tally_l = new HashMap<>();
        calculate_cryptic_hash(l_root_node_l, l_hash_tally_l);
        mark_celestial_duplicates(l_root_node_l, l_hash_tally_l);
        List<List<String>> l_final_remains_l = new ArrayList<>();
        List<String> l_current_trail_l = new ArrayList<>();
        gather_survivors(l_root_node_l, l_current_trail_l, l_final_remains_l);
        return l_final_remains_l;
    }
}
