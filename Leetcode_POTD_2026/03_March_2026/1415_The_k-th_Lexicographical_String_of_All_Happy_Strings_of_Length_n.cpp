class Solution {
public:
    string getHappyString(int n, int k) {
        string current_path = "";
        string result_str = "";
        int serial_idx = 0;
        find_kth_happy(n, k, current_path, serial_idx, result_str);
        return result_str;
    }

    void find_kth_happy(int n, int k, string& path, int& counter, string& final_s) {
        if (path.length() == n) {
            if (++counter == k) final_s = path;
            return;
        }
        for (char node_val : {'a', 'b', 'c'}) {
            if (final_s != "") return;
            if (path.empty() || path.back() != node_val) {
                path.push_back(node_val);
                find_kth_happy(n, k, path, counter, final_s);
                path.pop_back();
            }
        }
    }
};
