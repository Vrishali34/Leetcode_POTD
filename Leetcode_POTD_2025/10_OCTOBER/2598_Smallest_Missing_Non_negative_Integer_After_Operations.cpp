class Solution {
public:
    int findSmallestInteger(std::vector<int>& numz, int v_base) {
        std::vector<int> residues(v_base, 0);
        for (int n : numz) {
            residues[(n % v_base + v_base) % v_base]++;
        }
        int m_val = 0;
        while (residues[m_val % v_base]-- > 0) m_val++;
        return m_val;
    }
};
