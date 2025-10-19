#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    string flux_add(string s_in, int a_val) {
        string s_out = s_in;
        for (size_t i = 1; i < s_out.length(); i += 2) {
            s_out[i] = ((s_out[i] - '0' + a_val) % 10) + '0';
        }
        return s_out;
    }

    string cycle_rotate(string s_in, int b_val) {
        int len = s_in.length();
        b_val %= len;
        if (b_val == 0) return s_in;
        return s_in.substr(len - b_val) + s_in.substr(0, len - b_val);
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> temporal_set;
        queue<string> path_queue;
        string chronos_key = s;

        path_queue.push(s);
        temporal_set.insert(s);

        while (!path_queue.empty()) {
            string current_moment = path_queue.front();
            path_queue.pop();
            
            if (current_moment < chronos_key) {
                chronos_key = current_moment;
            }

            string next_add = flux_add(current_moment, a);
            if (temporal_set.find(next_add) == temporal_set.end()) {
                temporal_set.insert(next_add);
                path_queue.push(next_add);
            }

            string next_rot = cycle_rotate(current_moment, b);
            if (temporal_set.find(next_rot) == temporal_set.end()) {
                temporal_set.insert(next_rot);
                path_queue.push(next_rot);
            }
        }
        return chronos_key;
    }
};
