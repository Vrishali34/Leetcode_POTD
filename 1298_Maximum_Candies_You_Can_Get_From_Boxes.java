import java.util.*;

class Solution {
    public int maxCandies(int[] chamberSeals, int[] gemDeposits, int[][] mysticKeys, int[][] nestedRealms, int[] startingPortals) {
        long totalGems = 0;
        Queue<Integer> explorationQueue = new LinkedList<>();
        boolean[] encounteredSealed = new boolean[chamberSeals.length];
        int[] currentSealState = Arrays.copyOf(chamberSeals, chamberSeals.length);

        for (int portal : startingPortals) {
            if (currentSealState[portal] == 1) {
                explorationQueue.offer(portal);
            } else {
                encounteredSealed[portal] = true;
            }
        }

        while (!explorationQueue.isEmpty()) {
            int currentRealm = explorationQueue.poll();

            totalGems += gemDeposits[currentRealm];

            for (int keyTarget : mysticKeys[currentRealm]) {
                if (currentSealState[keyTarget] == 0) {
                    currentSealState[keyTarget] = 1;
                    if (encounteredSealed[keyTarget]) {
                        explorationQueue.offer(keyTarget);
                    }
                }
            }

            for (int nestedRealm : nestedRealms[currentRealm]) {
                if (currentSealState[nestedRealm] == 1) {
                    explorationQueue.offer(nestedRealm);
                } else if (!encounteredSealed[nestedRealm]) {
                    encounteredSealed[nestedRealm] = true;
                }
            }
        }
        return (int) totalGems;
    }
}
