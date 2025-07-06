class FindSumPairs {
    unordered_map<int,int> cache;
    vector<int> cpu, gpu;
public:
    FindSumPairs(vector<int>& a, vector<int>& b): cpu(a), gpu(b) {
        for(int i : b) cache[i]++;
    }
    void add(int idx, int val) {
        cache[gpu[idx]]--;
        gpu[idx] += val;
        cache[gpu[idx]]++;
    }
    int count(int tgt) {
        int cnt = 0;
        for(int x : cpu) cnt += cache[tgt - x];
        return cnt;
    }
};
