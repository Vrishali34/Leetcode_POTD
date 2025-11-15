#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        long long cosmic_count = 0;
        int n_len = s.length();
        vector<int> void_locs;
        for (int i = 0; i < n_len; ++i) {
            if (s[i] == '0') void_locs.push_back(i);
        }
        
        int n_voids = void_locs.size();
        int star_limit = sqrt(n_len);
        int void_ptr = 0;
        
        for (int i = 0; i < n_len; ++i) {
            while (void_ptr < n_voids && void_locs[void_ptr] < i) {
                void_ptr++;
            }
            
            int next_void = (void_ptr < n_voids) ? void_locs[void_ptr] : n_len;
            cosmic_count += (next_void - i);
            
            for (int z_count = 1; z_count <= star_limit; ++z_count) {
                int z_end_ptr = void_ptr + z_count - 1;
                if (z_end_ptr >= n_voids) break;
                
                int j_sub_end = void_locs[z_end_ptr];
                int star_count = (j_sub_end - i + 1) - z_count;
                int needed_stars = z_count * z_count;
                
                int next_void_boundary = (z_end_ptr + 1 < n_voids) ? void_locs[z_end_ptr + 1] : n_len;
                int max_stars = star_count + (next_void_boundary - 1 - j_sub_end);
                
                if (max_stars < needed_stars) continue;
                
                int start_j = (star_count >= needed_stars) ? j_sub_end : (j_sub_end + (needed_stars - star_count));
                cosmic_count += (next_void_boundary - start_j);
            }
        }
        return cosmic_count;
    }
};
