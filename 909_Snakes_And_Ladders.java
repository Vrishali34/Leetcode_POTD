import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int d = board.length; // Dimension of the board (n)
        int s = d * d; // Total number of squares (n*n)

        Queue<int[]> q = new LinkedList<>(); // Queue for BFS: stores {current_square, moves_taken}
        q.offer(new int[]{1, 0}); // Start at square 1 with 0 moves

        // Array to store minimum moves to reach each square, initialized to -1 (unvisited)
        int[] v = new int[s + 1];
        for (int i = 0; i <= s; i++) {
            v[i] = -1;
        }
        v[1] = 0; // Mark starting square as visited with 0 moves

        // Lambda function to get the actual value from the board given a 1-indexed square number
        // It handles the Boustrophedon (alternating) numbering style of the board
        java.util.function.Function<Integer, Integer> getBoardValue = (sq) -> {
            int r = (sq - 1) / d; // Calculate 0-indexed row from 1-indexed square number
            int c = (sq - 1) % d; // Calculate 0-indexed column from 1-indexed square number

            // If the row is odd (0-indexed), the direction is right-to-left, so adjust column
            if (r % 2 == 1) {
                c = d - 1 - c;
            }
            // The board is given with row n-1 at the bottom, so invert the row index
            return board[d - 1 - r][c];
        };

        while (!q.isEmpty()) {
            int[] curr = q.poll(); // Dequeue the current square and its moves
            int currSq = curr[0]; // Current square number
            int currMvs = curr[1]; // Moves taken to reach current square

            // If we reached the target square (n*n), return the moves
            if (currSq == s) {
                return currMvs;
            }

            // Explore possible moves from current square (1 to 6 steps)
            for (int nxtStp = 1; nxtStp <= 6; ++nxtStp) {
                int ptnlSq = currSq + nxtStp; // Potential next square

                // If potential square is beyond the board, skip
                if (ptnlSq > s) {
                    continue;
                }

                // Get the value at the potential square on the board
                // This handles snakes (-1) and ladders (destination square)
                int dest = getBoardValue.apply(ptnlSq);
                // If it's a snake or ladder, the final destination is 'dest', otherwise it's 'ptnlSq'
                int finalSq = (dest != -1) ? dest : ptnlSq;

                // If this final square has not been visited yet
                if (v[finalSq] == -1) {
                    v[finalSq] = currMvs + 1; // Mark as visited with one more move
                    q.offer(new int[]{finalSq, currMvs + 1}); // Enqueue for further exploration
                }
            }
        }
        // If the queue becomes empty and n*n is not reached, it's impossible
        return -1;
    }
}
