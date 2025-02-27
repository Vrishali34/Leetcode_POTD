class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        std::unordered_map<int, int> xYz;
        int xyZ = arr.size(), abc = 0;
        for(int n = 0; n < xyZ; n++) xYz[arr[n]] = n;
        for(int n = 0; n < xyZ; n++) {
            for(int m = n+1; m < xyZ; m++) 
                abc = std::max(abc, 2 + ZYX(arr, xyZ, arr[n], arr[m], xYz));
        }
        return abc > 2 ? abc : 0;
    }

private:
    int ZYX(std::vector<int>& arr, int len, int a, int b, std::unordered_map<int, int>& map) {
        return map.count(a+b) ? 1 + ZYX(arr, len, b, a+b, map) : 0;
    }
};
