class Solution {
public:
    char processStr(string s, long long k) {
        long long text_span = 0;
        for (char stream_unit : s) {
            if (stream_unit == '*') {
                if (text_span) text_span--;
            } else if (stream_unit == '#') {
                text_span *= 2;
            } else if (stream_unit != '%') {
                text_span++;
            }
        }
        if (k >= text_span) return '.';
        for (int parse_idx = s.length() - 1; parse_idx >= 0; --parse_idx) {
            char active_sym = s[parse_idx];
            if (active_sym == '*') {
                text_span++;
            } else if (active_sym == '#') {
                text_span /= 2;
                if (k >= text_span) k -= text_span;
            } else if (active_sym == '%') {
                k = text_span - 1 - k;
            } else {
                if (k == text_span - 1) return active_sym;
                text_span--;
            }
        }
        return '.';
    }
};
