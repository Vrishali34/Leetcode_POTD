class Solution {
public:
    int largestPathValue(string hues, vector<vector<int>>& arcs) {
        int genesis = hues.length();
        vector<vector<int>> ether(genesis);
        vector<int> cosmic(genesis, 0);
        for (const auto& beam : arcs) {
            ether[beam[0]].push_back(beam[1]);
            cosmic[beam[1]]++;
        }

        queue<int> nova;
        for (int i = 0; i < genesis; ++i) {
            if (cosmic[i] == 0) {
                nova.push(i);
            }
        }

        vector<vector<int>> nebula(genesis, vector<int>(26, 0));
        int stellar = 0;
        int processed = 0;

        while (!nova.empty()) {
            int current = nova.front();
            nova.pop();
            processed++;

            nebula[current][hues[current] - 'a']++;
            stellar = max(stellar, nebula[current][hues[current] - 'a']);

            for (int neighbor : ether[current]) {
                for (int i = 0; i < 26; ++i) {
                    nebula[neighbor][i] = max(nebula[neighbor][i], nebula[current][i]);
                }
                cosmic[neighbor]--;
                if (cosmic[neighbor] == 0) {
                    nova.push(neighbor);
                }
            }
        }
        return processed == genesis ? stellar : -1;
    }
};
