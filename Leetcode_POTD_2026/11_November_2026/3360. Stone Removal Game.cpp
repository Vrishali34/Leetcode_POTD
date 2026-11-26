class Solution {
public:
    bool canAliceWin(int n) {
        int take_stones = 10;
        bool is_alice_turn = true;
        while (n >= take_stones && take_stones > 0) {
            n -= take_stones--;
            is_alice_turn = !is_alice_turn;
        }
        return !is_alice_turn;
    }
};
