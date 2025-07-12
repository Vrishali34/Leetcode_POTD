import java.util.*;

class Solution {
    private Map<Integer, int[]> resultStore = new HashMap<>();
    private int totalPlayers;
    private int playerA;
    private int playerB;

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        totalPlayers = n;
        playerA = firstPlayer - 1; 
        playerB = secondPlayer - 1;

        return calculateTournamentOutcome((1 << n) - 1, 1);
    }

    private int[] calculateTournamentOutcome(int currentActiveMask, int currentRound) {
        if (resultStore.containsKey(currentActiveMask)) {
            return resultStore.get(currentActiveMask);
        }

        List<Integer> activeParticipants = new ArrayList<>();
        for (int i = 0; i < totalPlayers; ++i) {
            if (((currentActiveMask >> i) & 1) == 1) {
                activeParticipants.add(i);
            }
        }

        int numActive = activeParticipants.size();
        int posA = -1, posB = -1;
        for (int i = 0; i < numActive; ++i) {
            if (activeParticipants.get(i) == playerA) posA = i;
            if (activeParticipants.get(i) == playerB) posB = i;
        }

        if (posA + posB == numActive - 1) {
            // Base case: players meet in this round
            // No need for computeIfAbsent here as we are directly returning
            int[] result = new int[]{currentRound, currentRound};
            resultStore.put(currentActiveMask, result); // Store the result before returning
            return result;
        }

        int minRound = Integer.MAX_VALUE;
        int maxRound = Integer.MIN_VALUE;
        int matchesInThisRound = (numActive + 1) / 2;

        Stack<Integer> possibleNextRoundMasks = new Stack<>();
        
        generateNextRoundStates(0, 0, activeParticipants, matchesInThisRound, possibleNextRoundMasks);

        for (int nextMask : possibleNextRoundMasks) {
            int[] resForNextState = calculateTournamentOutcome(nextMask, currentRound + 1);
            minRound = Math.min(minRound, resForNextState[0]);
            maxRound = Math.max(maxRound, resForNextState[1]);
        }
        
        // After the loop, minRound and maxRound are finalized for this currentMask.
        // Now they are effectively final for the purpose of being captured by the lambda.
        // However, a simpler put() is generally preferred over computeIfAbsent() when you
        // have already calculated the value.

        int[] finalResult = new int[]{minRound, maxRound};
        resultStore.put(currentActiveMask, finalResult); // Store the calculated result
        return finalResult;
    }

    private void generateNextRoundStates(int currentMatchIndex, int nextPlayersMask, List<Integer> activeParticipants, 
                                          int matchesLimit, Stack<Integer> generatedMasks) {
        if (currentMatchIndex == matchesLimit) {
            generatedMasks.push(nextPlayersMask);
            return;
        }

        int contenderFront = activeParticipants.get(currentMatchIndex);
        int contenderBack = activeParticipants.get(activeParticipants.size() - 1 - currentMatchIndex);

        if (currentMatchIndex == activeParticipants.size() - 1 - currentMatchIndex) { 
            generateNextRoundStates(currentMatchIndex + 1, nextPlayersMask | (1 << contenderFront), activeParticipants, matchesLimit, generatedMasks);
        } else {
            boolean aIsPresent = (contenderFront == playerA || contenderFront == playerB);
            boolean bIsPresent = (contenderBack == playerA || contenderBack == playerB);

            if (aIsPresent && bIsPresent) {
                return; 
            } else if (aIsPresent) {
                generateNextRoundStates(currentMatchIndex + 1, nextPlayersMask | (1 << contenderFront), activeParticipants, matchesLimit, generatedMasks);
            } else if (bIsPresent) {
                generateNextRoundStates(currentMatchIndex + 1, nextPlayersMask | (1 << contenderBack), activeParticipants, matchesLimit, generatedMasks);
            } else {
                generateNextRoundStates(currentMatchIndex + 1, nextPlayersMask | (1 << contenderFront), activeParticipants, matchesLimit, generatedMasks);
                generateNextRoundStates(currentMatchIndex + 1, nextPlayersMask | (1 << contenderBack), activeParticipants, matchesLimit, generatedMasks);
            }
        }
    }
}
