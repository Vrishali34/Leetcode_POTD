class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& srcGrid, int shiftAmt) {
        int rowCount = srcGrid.size();
        int colCount = srcGrid[0].size();
        int totalCells = rowCount * colCount;
        shiftAmt = shiftAmt % totalCells;
        
        vector<vector<int>> shiftedGrid(rowCount, vector<int>(colCount));
        
        for (int cellIdx = 0; cellIdx < totalCells; ++cellIdx) {
            int targetIdx = (cellIdx + shiftAmt) % totalCells;
            shiftedGrid[targetIdx / colCount][targetIdx % colCount] = srcGrid[cellIdx / colCount][cellIdx % colCount];
        }
        
        return shiftedGrid;
    }
};
