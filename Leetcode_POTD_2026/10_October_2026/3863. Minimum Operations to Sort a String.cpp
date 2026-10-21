class Solution {
public:
    int minOperations(string s) {
        size_t len = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (len == 2) return -1;
        char minCh = *min_element(s.begin(), s.end());
        char maxCh = *max_element(s.begin(), s.end());
        if (s[0] == minCh || s[len - 1] == maxCh) return 1;
        bool minInPrefix = s.find(minCh) < len - 1;
        bool maxInSuffix = s.rfind(maxCh) > 0;
        return (minInPrefix || maxInSuffix) ? 2 : 3;
    }
};

/* 

my logic - Logic:
Already sorted gives 0. A length-2 string that isn’t sorted can’t be fixed, since the only allowed substrings have length 1, so it gives -1.
If the smallest char is at index 0, sorting everything after it finishes the job. The same holds if the largest char is at the last index, so the answer is 1.
Otherwise the answer is 2 if the smallest char appears in a proper prefix (before the last index) or the largest char appears in a proper suffix (after index 0). If neither does, the answer is 3.

*/
