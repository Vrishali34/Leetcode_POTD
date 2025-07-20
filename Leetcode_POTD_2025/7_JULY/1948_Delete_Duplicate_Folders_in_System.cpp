class Solution {
public:
    struct TerraNode {
        map<string, TerraNode*> k_children_k;
        string v_hash_v;
        bool b_marked_b = false;
    };

    TerraNode* construct_arbor_trie(const vector<vector<string>>& p_paths_p) {
        TerraNode* l_arbor_root_l = new TerraNode();
        for (const auto& l_path_l : p_paths_p) {
            TerraNode* l_current_l = l_arbor_root_l;
            for (const string& l_comp_l : l_path_l) {
                if (l_current_l->k_children_k.find(l_comp_l) == l_current_l->k_children_k.end()) {
                    l_current_l->k_children_k[l_comp_l] = new TerraNode();
                }
                l_current_l = l_current_l->k_children_k[l_comp_l];
            }
        }
        return l_arbor_root_l;
    }

    string calculate_cryptic_hash(TerraNode* p_node_p, unordered_map<string, int>& p_hash_counts_p) {
        if (!p_node_p->k_children_k.empty()) {
            string l_cur_sig_l = "(";
            for (auto const& [l_name_l, l_child_l] : p_node_p->k_children_k) {
                l_cur_sig_l += l_name_l + calculate_cryptic_hash(l_child_l, p_hash_counts_p);
            }
            l_cur_sig_l += ")";
            p_node_p->v_hash_v = l_cur_sig_l;
            p_hash_counts_p[l_cur_sig_l]++;
        }
        return p_node_p->v_hash_v;
    }

    void mark_celestial_duplicates(TerraNode* p_node_p, const unordered_map<string, int>& p_hash_counts_p) {
        if (!p_node_p->v_hash_v.empty() && p_hash_counts_p.at(p_node_p->v_hash_v) > 1) {
            p_node_p->b_marked_b = true;
        }
        for (auto const& [l_name_l, l_child_l] : p_node_p->k_children_k) {
            mark_celestial_duplicates(l_child_l, p_hash_counts_p);
        }
    }

    void gather_survivors(TerraNode* p_node_p, vector<string>& p_current_path_p, vector<vector<string>>& p_results_p) {
        if (p_node_p->b_marked_b) {
            return;
        }
        if (!p_current_path_p.empty()) {
            p_results_p.push_back(p_current_path_p);
        }
        for (auto const& [l_name_l, l_child_l] : p_node_p->k_children_k) {
            p_current_path_p.push_back(l_name_l);
            gather_survivors(l_child_l, p_current_path_p, p_results_p);
            p_current_path_p.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& p_paths_p) {
        TerraNode* l_root_node_l = construct_arbor_trie(p_paths_p);
        unordered_map<string, int> l_hash_tally_l;
        calculate_cryptic_hash(l_root_node_l, l_hash_tally_l);
        mark_celestial_duplicates(l_root_node_l, l_hash_tally_l);
        vector<vector<string>> l_final_remains_l;
        vector<string> l_current_trail_l;
        gather_survivors(l_root_node_l, l_current_trail_l, l_final_remains_l);
        return l_final_remains_l;
    }
};
