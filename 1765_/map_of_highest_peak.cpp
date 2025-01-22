class Solution {  
public:  
    vector<vector<int>> highestPeak(vector<vector<int>>& code2_a) {  
        int code2_b = code2_a.size(), code2_c = code2_a[0].size();  
        queue<pair<int, int>> code2_d;  
        vector<vector<int>> code2_e(code2_b, vector<int>(code2_c, -1));  
        for (int code2_f = 0; code2_f < code2_b; ++code2_f) {  
            for (int code2_g = 0; code2_g < code2_c; ++code2_g) {  
                if (code2_a[code2_f][code2_g] == 1) {  
                    code2_e[code2_f][code2_g] = 0;  
                    code2_d.push({code2_f, code2_g});  
                }  
            }  
        }  
        vector<pair<int, int>> code2_h = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
        while (!code2_d.empty()) {  
            auto [code2_i, code2_j] = code2_d.front(); code2_d.pop();  
            for (auto& code2_k : code2_h) {  
                int code2_l = code2_i + code2_k.first;  
                int code2_m = code2_j + code2_k.second;  
                if (code2_l >= 0 && code2_l < code2_b && code2_m >= 0 && code2_m < code2_c && code2_e[code2_l][code2_m] == -1) {  
                    code2_e[code2_l][code2_m] = code2_e[code2_i][code2_j] + 1;  
                    code2_d.push({code2_l, code2_m});  
                }  
            }  
        }  
        return code2_e;  
    }  
};  
