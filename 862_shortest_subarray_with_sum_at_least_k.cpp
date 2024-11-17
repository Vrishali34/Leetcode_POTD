class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        ll ans = LLONG_MAX, sum = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        for (ll i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k) ans = min(ans, (ll)(i + 1)); // Cast i+1 to ll
            while (!pq.empty() && sum - pq.top().first >= k) {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == LLONG_MAX ? -1 : (int)ans; // Cast ans to int
    }
};
