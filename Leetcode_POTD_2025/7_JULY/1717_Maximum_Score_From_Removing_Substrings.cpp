class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ultimate_earning = 0;
        string interim_stack_a, interim_stack_b;
        char key_char_1, key_char_2;
        int gain_val_1, gain_val_2;

        if (x >= y) {
            key_char_1 = 'a';
            key_char_2 = 'b';
            gain_val_1 = x;
            gain_val_2 = y;
        } else {
            key_char_1 = 'b';
            key_char_2 = 'a';
            gain_val_1 = y;
            gain_val_2 = x;
        }

        for (char iter_char : s) {
            if (!interim_stack_a.empty() && interim_stack_a.back() == key_char_1 && iter_char == key_char_2) {
                ultimate_earning += gain_val_1;
                interim_stack_a.pop_back();
            } else {
                interim_stack_a.push_back(iter_char);
            }
        }

        for (char iter_char : interim_stack_a) {
            if (!interim_stack_b.empty() && interim_stack_b.back() == key_char_2 && iter_char == key_char_1) {
                ultimate_earning += gain_val_2;
                interim_stack_b.pop_back();
            } else {
                interim_stack_b.push_back(iter_char);
            }
        }
        return ultimate_earning;
    }
};
