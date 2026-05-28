class Solution {
    struct SuffixState {
        int suffix_links[26];
        int longest_common_suffix_index = -1;
        int smallest_length_bound = 1e9;
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<SuffixState> flat_suffix_trie(1);
        flat_suffix_trie.reserve(500005);
        
        for (int container_index = 0; container_index < wordsContainer.size(); ++container_index) {
            const string& container_word = wordsContainer[container_index];
            int word_length = container_word.length();
            int current_node_id = 0;
            
            if (word_length < flat_suffix_trie[0].smallest_length_bound) {
                flat_suffix_trie[0].smallest_length_bound = word_length;
                flat_suffix_trie[0].longest_common_suffix_index = container_index;
            }
            
            for (int letter_position = word_length - 1; letter_position >= 0; --letter_position) {
                int character_alphabet_index = container_word[letter_position] - 'a';
                if (!flat_suffix_trie[current_node_id].suffix_links[character_alphabet_index]) {
                    flat_suffix_trie[current_node_id].suffix_links[character_alphabet_index] = flat_suffix_trie.size();
                    flat_suffix_trie.emplace_back();
                }
                current_node_id = flat_suffix_trie[current_node_id].suffix_links[character_alphabet_index];
                
                if (word_length < flat_suffix_trie[current_node_id].smallest_length_bound) {
                    flat_suffix_trie[current_node_id].smallest_length_bound = word_length;
                    flat_suffix_trie[current_node_id].longest_common_suffix_index = container_index;
                }
            }
        }
        
        vector<int> query_result_indices;
        query_result_indices.reserve(wordsQuery.size());
        
        for (const string& query_word : wordsQuery) {
            int current_node_id = 0;
            int optimal_suffix_match_index = flat_suffix_trie[0].longest_common_suffix_index;
            
            for (int letter_position = query_word.length() - 1; letter_position >= 0; --letter_position) {
                int character_alphabet_index = query_word[letter_position] - 'a';
                if (!flat_suffix_trie[current_node_id].suffix_links[character_alphabet_index]) break;
                current_node_id = flat_suffix_trie[current_node_id].suffix_links[character_alphabet_index];
                optimal_suffix_match_index = flat_suffix_trie[current_node_id].longest_common_suffix_index;
            }
            query_result_indices.push_back(optimal_suffix_match_index);
        }
        return query_result_indices;
    }
};
