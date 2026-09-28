class Solution {
public:
    int maxDepth(string s) {
        int openCnt = 0, maxOpen = 0;
        for (char ch : s) {
            if (ch == '(') maxOpen = max(maxOpen, ++openCnt);
            else if (ch == ')') openCnt--;
        }
        return maxOpen;
    }
};
