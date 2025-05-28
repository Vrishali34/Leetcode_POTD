import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {

    private int assessReachableUnits(int origin, int reachLimit, int totalUnits, List<List<Integer>> linkages) {
        Queue<AbstractMap.SimpleEntry<Integer, Integer>> journeyQueue = new LinkedList<>();
        int[] traversedDepths = new int[totalUnits];
        Arrays.fill(traversedDepths, -1);
        int talliedReach = 0;

        journeyQueue.offer(new AbstractMap.SimpleEntry<>(origin, 0));
        traversedDepths[origin] = 0;

        while (!journeyQueue.isEmpty()) {
            AbstractMap.SimpleEntry<Integer, Integer> currentPoint = journeyQueue.poll();
            int currentUnit = currentPoint.getKey();
            int currentDepth = currentPoint.getValue();

            if (currentDepth > reachLimit) {
                continue;
            }
            talliedReach++;

            for (int connectedUnit : linkages.get(currentUnit)) {
                if (traversedDepths[connectedUnit] == -1) {
                    traversedDepths[connectedUnit] = currentDepth + 1;
                    journeyQueue.offer(new AbstractMap.SimpleEntry<>(connectedUnit, currentDepth + 1));
                }
            }
        }
        return talliedReach;
    }

    public int[] maxTargetNodes(int[][] structureA_bonds, int[][] structureB_bonds, int proximity_threshold) {
        int countA = structureA_bonds.length + 1;
        int countB = structureB_bonds.length + 1;

        List<List<Integer>> adj_A = new ArrayList<>();
        for (int i = 0; i < countA; i++) {
            adj_A.add(new ArrayList<>());
        }
        for (int[] bond : structureA_bonds) {
            adj_A.get(bond[0]).add(bond[1]);
            adj_A.get(bond[1]).add(bond[0]);
        }

        List<List<Integer>> adj_B = new ArrayList<>();
        for (int i = 0; i < countB; i++) {
            adj_B.add(new ArrayList<>());
        }
        for (int[] bond : structureB_bonds) {
            adj_B.get(bond[0]).add(bond[1]);
            adj_B.get(bond[1]).add(bond[0]);
        }

        int[] measuresA = new int[countA];
        for (int i = 0; i < countA; i++) {
            measuresA[i] = assessReachableUnits(i, proximity_threshold, countA, adj_A);
        }

        int pinnacleB_span = 0;
        for (int j = 0; j < countB; j++) {
            pinnacleB_span = Math.max(pinnacleB_span, assessReachableUnits(j, proximity_threshold - 1, countB, adj_B));
        }

        int[] final_aggregation = new int[countA];
        for (int i = 0; i < countA; i++) {
            final_aggregation[i] = measuresA[i] + pinnacleB_span;
        }

        return final_aggregation;
    }
}
