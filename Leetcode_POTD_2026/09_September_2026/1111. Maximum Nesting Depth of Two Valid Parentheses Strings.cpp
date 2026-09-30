class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> group_id(seq.size());
        int cur_depth = 0;

        for (int idx = 0; idx < (int)seq.size(); idx++) {
            if (seq[idx] == '(') {
                cur_depth++;
                group_id[idx] = cur_depth % 2;
            } else {
                group_id[idx] = cur_depth % 2;
                cur_depth--;
            }
        }

        return group_id;
    }
};
