class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& stone_matrix) {
        int h = stone_matrix.size(), w = stone_matrix[0].size();
        for (int i = 0; i < h; ++i) {
            int spot = w - 1;
            for (int j = w - 1; j >= 0; --j) {
                if (stone_matrix[i][j] == '*') spot = j - 1;
                else if (stone_matrix[i][j] == '#') {
                    stone_matrix[i][j] = '.';
                    stone_matrix[i][spot--] = '#';
                }
            }
        }
        vector<vector<char>> final_box(w, vector<char>(h));
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                final_box[j][h - 1 - i] = stone_matrix[i][j];
        return final_box;
    }
};
