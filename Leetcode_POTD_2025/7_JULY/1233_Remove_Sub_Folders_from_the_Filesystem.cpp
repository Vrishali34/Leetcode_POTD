class Solution {
public:
    vector<string> removeSubfolders(vector<string>& file_paths) {
        sort(file_paths.begin(), file_paths.end());
        vector<string> cosmic_roots;
        for (const string& path_str : file_paths) {
            if (cosmic_roots.empty() || !(path_str.rfind(cosmic_roots.back() + "/", 0) == 0)) {
                cosmic_roots.push_back(path_str);
            }
        }
        return cosmic_roots;
    }
};
