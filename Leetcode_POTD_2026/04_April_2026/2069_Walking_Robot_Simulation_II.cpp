class Robot {
    int frame_w, frame_h, curr_x = 0, curr_y = 0, vec_dir = 0, circum;
public:
    Robot(int width, int height) : frame_w(width - 1), frame_h(height - 1) {
        circum = 2 * (frame_w + frame_h);
    }
    void step(int num) {
        num %= circum;
        if (num == 0 && curr_x == 0 && curr_y == 0) vec_dir = 3;
        while (num > 0) {
            int gap = 0;
            switch(vec_dir) {
                case 0: gap = min(num, frame_w - curr_x); curr_x += gap; break;
                case 1: gap = min(num, frame_h - curr_y); curr_y += gap; break;
                case 2: gap = min(num, curr_x); curr_x -= gap; break;
                case 3: gap = min(num, curr_y); curr_y -= gap; break;
            }
            num -= gap;
            if (num > 0) vec_dir = (vec_dir + 1) % 4;
        }
    }
    vector<int> getPos() { return {curr_x, curr_y}; }
    string getDir() {
        const char* res[] = {"East", "North", "West", "South"};
        return res[vec_dir];
    }
};
