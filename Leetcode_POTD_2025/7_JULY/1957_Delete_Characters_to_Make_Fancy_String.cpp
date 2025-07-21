class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string astral_result;
        char last_orb = '\0';
        int orb_count = 0;

        for (char current_orb : s) {
            if (current_orb == last_orb) {
                orb_count++;
            } else {
                last_orb = current_orb;
                orb_count = 1;
            }

            if (orb_count <= 2) {
                astral_result.push_back(current_orb);
            }
        }
        return astral_result;
    }
};
