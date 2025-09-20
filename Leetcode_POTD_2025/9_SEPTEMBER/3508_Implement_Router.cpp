#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Router {
private:
    int limit_cap;
    deque<vector<int>> flow;
    unordered_set<string> footprints;
    unordered_map<int, vector<int>> records;
    unordered_map<int, int> offsets;

    string hash(int s, int d, int t) {
        return to_string(s) + "_" + to_string(d) + "_" + to_string(t);
    }

public:
    Router(int memoryLimit) : limit_cap(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string sig = hash(source, destination, timestamp);
        if (footprints.count(sig)) return false;

        if (flow.size() == limit_cap) {
            forwardPacket();
        }

        flow.push_back({source, destination, timestamp});
        footprints.insert(sig);
        records[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (flow.empty()) return {};
        
        vector<int> packet = flow.front();
        flow.pop_front();
        footprints.erase(hash(packet[0], packet[1], packet[2]));

        offsets[packet[1]]++;

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (records.find(destination) == records.end()) return 0;

        const auto& data = records.at(destination);
        int start_idx = offsets[destination];

        auto first = lower_bound(data.begin() + start_idx, data.end(), startTime);
        auto last = upper_bound(data.begin() + start_idx, data.end(), endTime);
        
        return distance(first, last);
    }
};
