class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int dim = board.size();
        int totalSquares = dim * dim;
        
        // Map 1D square number to 2D board coordinates
        auto getBoardValue = [&](int sqNum) {
            int rowZeroIndexed = (sqNum - 1) / dim;
            int colZeroIndexed = (sqNum - 1) % dim;
            
            // Adjust column for Boustrophedon style
            if (rowZeroIndexed % 2 == 1) { // Odd row (0-indexed) means right-to-left
                colZeroIndexed = dim - 1 - colZeroIndexed;
            }
            
            // Convert to actual board indices (board[row][col])
            // Board is stored from n-1 down to 0, so invert row
            return board[dim - 1 - rowZeroIndexed][colZeroIndexed];
        };

        queue<pair<int, int>> journeyQueue; // {current_square, moves_taken}
        journeyQueue.push({1, 0}); // Start at square 1, 0 moves

        vector<int> minMoves(totalSquares + 1, -1); // Stores minimum moves to reach a square
        minMoves[1] = 0;

        while (!journeyQueue.empty()) {
            pair<int, int> current = journeyQueue.front();
            journeyQueue.pop();

            int currentSq = current.first;
            int currentMvs = current.second;

            if (currentSq == totalSquares) {
                return currentMvs; // Reached the destination
            }

            // Explore possible next moves (1 to 6 steps)
            for (int nextStep = 1; nextStep <= 6; ++nextStep) {
                int potentialSq = currentSq + nextStep;

                if (potentialSq > totalSquares) {
                    continue; // Cannot move beyond the board
                }

                int destinationSq = getBoardValue(potentialSq);
                int finalSq = (destinationSq != -1) ? destinationSq : potentialSq;

                // If this square hasn't been visited or we found a shorter path
                if (minMoves[finalSq] == -1) {
                    minMoves[finalSq] = currentMvs + 1;
                    journeyQueue.push({finalSq, currentMvs + 1});
                }
            }
        }

        return -1; // Destination not reachable
    }
};
