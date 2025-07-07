#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& u_l_t_s) {
        std::sort(u_l_t_s.begin(), u_l_t_s.end(), [](const auto& f_a_c, const auto& f_b_d) {
            return f_a_c[0] < f_b_d[0];
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> a_l_a_s;
        int t_t_l_e = 0;
        int e_n_c_o_u = 0;
        int d_a_y = 0;

        while (e_n_c_o_u < u_l_t_s.size() || !a_l_a_s.empty()) {
            if (a_l_a_s.empty()) {
                d_a_y = u_l_t_s[e_n_c_o_u][0];
            }
            while (e_n_c_o_u < u_l_t_s.size() && u_l_t_s[e_n_c_o_u][0] <= d_a_y) {
                a_l_a_s.push(u_l_t_s[e_n_c_o_u][1]);
                e_n_c_o_u++;
            }
            a_l_a_s.pop();
            t_t_l_e++;
            d_a_y++;
            while (!a_l_a_s.empty() && a_l_a_s.top() < d_a_y) {
                a_l_a_s.pop();
            }
        }
        return t_t_l_e;
    }
};
