class Solution {
public:
    int maxCandies(std::vector<int>& chamberSeals, std::vector<int>& gemDeposits, std::vector<std::vector<int>>& mysticKeys, std::vector<std::vector<int>>& nestedRealms, std::vector<int>& startingPortals) {
        long long totalGems = 0;
        std::queue<int> explorationQueue;
        std::vector<bool> encounteredSealed(chamberSeals.size(), false); // Tracks boxes seen but still closed
        std::vector<int> currentSealState = chamberSeals; // Mutable state of chamber seals

        for (int portal : startingPortals) {
            if (currentSealState[portal] == 1) { // Portal is open
                explorationQueue.push(portal);
            } else { // Portal is sealed, but we know it exists
                encounteredSealed[portal] = true;
            }
        }

        while (!explorationQueue.empty()) {
            int currentRealm = explorationQueue.front();
            explorationQueue.pop();

            totalGems += gemDeposits[currentRealm];

            for (int keyTarget : mysticKeys[currentRealm]) {
                if (currentSealState[keyTarget] == 0) { // If target is currently sealed
                    currentSealState[keyTarget] = 1; // Unlock it
                    if (encounteredSealed[keyTarget]) { // If it was previously encountered as sealed
                        explorationQueue.push(keyTarget); // Add to queue as it's now open
                    }
                }
            }

            for (int nestedRealm : nestedRealms[currentRealm]) {
                if (currentSealState[nestedRealm] == 1) { // If nested realm is open
                    explorationQueue.push(nestedRealm);
                } else if (!encounteredSealed[nestedRealm]) { // If sealed and not yet known
                    encounteredSealed[nestedRealm] = true; // Mark as known sealed
                }
            }
        }
        return totalGems;
    }
};
