class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int star_map = bits.size() - 2;
        int nebula_density = 0;
        while (star_map >= 0 && bits[star_map] == 1) {
            nebula_density++;
            star_map--;
        }
        return nebula_density % 2 == 0;
    }
};
