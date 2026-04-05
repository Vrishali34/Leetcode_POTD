class Solution {
public:
    bool judgeCircle(string moves) {
        int x_shift = 0, y_shift = 0;
        for (char step_dir : moves) {
            switch (step_dir) {
                case 'U': y_shift++; break;
                case 'D': y_shift--; break;
                case 'L': x_shift--; break;
                case 'R': x_shift++; break;
            }
        }
        return !x_shift && !y_shift;
    }
};
