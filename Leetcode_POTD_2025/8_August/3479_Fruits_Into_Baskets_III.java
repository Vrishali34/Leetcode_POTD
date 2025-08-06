import java.util.Arrays;

class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int numBaskets = baskets.length;
        int treeSize = 1;
        while (treeSize < numBaskets) {
            treeSize *= 2;
        }

        int[] segmentTree = new int[2 * treeSize];
        Arrays.fill(segmentTree, -1);
        for (int i = 0; i < numBaskets; ++i) {
            segmentTree[treeSize + i] = baskets[i];
        }

        for (int i = treeSize - 1; i > 0; --i) {
            segmentTree[i] = Math.max(segmentTree[2 * i], segmentTree[2 * i + 1]);
        }

        int unplacedCount = 0;
        for (int fruitQty : fruits) {
            if (segmentTree[1] < fruitQty) {
                unplacedCount++;
                continue;
            }

            int currentNodeIndex = 1;
            while (currentNodeIndex < treeSize) {
                if (segmentTree[2 * currentNodeIndex] >= fruitQty) {
                    currentNodeIndex = 2 * currentNodeIndex;
                } else {
                    currentNodeIndex = 2 * currentNodeIndex + 1;
                }
            }

            segmentTree[currentNodeIndex] = -1;

            currentNodeIndex /= 2;
            while (currentNodeIndex > 0) {
                segmentTree[currentNodeIndex] = Math.max(segmentTree[2 * currentNodeIndex], segmentTree[2 * currentNodeIndex + 1]);
                currentNodeIndex /= 2;
            }
        }
        return unplacedCount;
    }
}
