import java.util.HashMap;
import java.util.Map;

class Spreadsheet {
    private final Map<String, Integer> cellValues;

    public Spreadsheet(int rows) {
        this.cellValues = new HashMap<>();
    }
    
    public void setCell(String cell, int value) {
        this.cellValues.put(cell, value);
    }
    
    public void resetCell(String cell) {
        this.cellValues.remove(cell);
    }
    
    public int getValue(String formula) {
        String[] parts = formula.substring(1).split("\\+");
        int value1 = getOperandValue(parts[0]);
        int value2 = getOperandValue(parts[1]);
        return value1 + value2;
    }
    
    private int getOperandValue(String operand) {
        try {
            return Integer.parseInt(operand);
        } catch (NumberFormatException e) {
            return cellValues.getOrDefault(operand, 0);
        }
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */
