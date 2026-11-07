class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int serverCnt = servers.size(), taskCnt = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeHeap;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> busyHeap;
        for (int i = 0; i < serverCnt; i++) freeHeap.push({servers[i], i});

        vector<int> ans(taskCnt);
        long long curSec = 0;
        for (int taskIdx = 0; taskIdx < taskCnt; taskIdx++) {
            curSec = max(curSec, (long long)taskIdx);
            if (freeHeap.empty()) curSec = max(curSec, get<0>(busyHeap.top()));
            while (!busyHeap.empty() && get<0>(busyHeap.top()) <= curSec) {
                auto [endSec, serverWt, serverIdx] = busyHeap.top();
                busyHeap.pop();
                freeHeap.push({serverWt, serverIdx});
            }
            auto [serverWt, serverIdx] = freeHeap.top();
            freeHeap.pop();
            ans[taskIdx] = serverIdx;
            busyHeap.push({curSec + tasks[taskIdx], serverWt, serverIdx});
        }
        return ans;
    }
};
