class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize `q_fabric` to represent the equivalence groups.
        // Each character (0-25 for 'a'-'z') is initially in its own group.
        vector<int> q_fabric(26);
        for (int i = 0; i < 26; ++i) {
            q_fabric[i] = i;
        }

        // `probe_entanglement` is a helper function to find the representative (root)
        // of the equivalence group for a given character using path compression.
        // This ensures efficient lookups for equivalent characters.
        function<int(int)> probe_entanglement = [&](int particle) {
            // If the particle is its own parent, it's the root of its group.
            if (q_fabric[particle] == particle) {
                return particle;
            }
            // Otherwise, recursively find the root and compress the path
            // by setting the particle's parent directly to the root.
            return q_fabric[particle] = probe_entanglement(q_fabric[particle]);
        };

        // Iterate through s1 and s2 to establish equivalence relationships.
        // For each pair of equivalent characters, unite their groups.
        for (int i = 0; i < s1.length(); ++i) {
            // Find the root (representative) of the group for s1[i].
            int photon_x = probe_entanglement(s1[i] - 'a');
            // Find the root (representative) of the group for s2[i].
            int photon_y = probe_entanglement(s2[i] - 'a');

            // To maintain lexicographical smallest equivalent string,
            // the smaller root (character) becomes the parent of the larger root.
            if (photon_x < photon_y) {
                q_fabric[photon_y] = photon_x;
            } else {
                q_fabric[photon_x] = photon_y;
            }
        }

        // Build the `decoded_flux` (result string) by transforming `baseStr`.
        string decoded_flux = "";
        for (char energy_signature : baseStr) {
            // For each character in `baseStr`, find its equivalent smallest character
            // (the root of its equivalence group) and append it to the result.
            decoded_flux += (char)(probe_entanglement(energy_signature - 'a') + 'a');
        }
        // Return the lexicographically smallest equivalent string.
        return decoded_flux;
    }
};
