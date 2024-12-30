class Solution {
public:
    int P = 1e9+7;
    vector<int> cache;
    int foom(int l, int h, int z, int o, int cur) {
        if (cur > h) return 0;
        if (cache[cur] != -1) return cache[cur];
        int grab = 0;
        if(cur >= l && cur <= h) grab = 1;
        return cache[cur] = (grab + foom(l, h, z, o, cur + z) + foom(l, h, z, o, cur + o)) % P;
    }
    int countGoodStrings(int l, int h, int z, int o) {
        cache.assign(100001, -1);
        return foom(l, h, z, o, 0);
    }
};
