class Solution {
    int find_solo(string s) {
        int high = 0, flow = 0;
        for(int k = 0; k < s.size(); ++k) {
            flow = (k > 0 && s[k] == s[k-1]) ? flow + 1 : 1;
            high = max(high, flow);
        }
        return high;
    }
    int find_pair(string s, char x, char y, char out) {
        int max_w = 0, gap = 0;
        unordered_map<int, int> rec = {{0, -1}};
        for(int j = 0; j < s.size(); ++j) {
            if(s[j] == out) { rec = {{0, j}}; gap = 0; continue; }
            if(s[j] == x) gap++; else if(s[j] == y) gap--;
            if(rec.count(gap)) max_w = max(max_w, j - rec[gap]);
            else rec[gap] = j;
        }
        return max_w;
    }
    int find_triple(string s) {
        int result = 0, a = 0, b = 0, c = 0;
        unordered_map<long long, int> hist = {{0, -1}};
        for(int i = 0; i < s.size(); ++i) {
            s[i] == 'a' ? a++ : (s[i] == 'b' ? b++ : c++);
            long long key = ((long long)(a - b) << 32) | (unsigned int)(b - c);
            if(hist.count(key)) result = max(result, i - hist[key]);
            else hist[key] = i;
        }
        return result;
    }
public:
    int longestBalanced(string s) {
        return max({find_solo(s), find_pair(s, 'a', 'b', 'c'), find_pair(s, 'a', 'c', 'b'), find_pair(s, 'b', 'c', 'a'), find_triple(s)});
    }
};
