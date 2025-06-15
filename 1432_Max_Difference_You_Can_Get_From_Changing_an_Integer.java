class Solution {
    public int maxDiff(int num) {
        String stNum = String.valueOf(num);

        // Maximize
        char[] maxValList = stNum.toCharArray();
        char replForMax = ' ';
        for (char charM : maxValList) {
            if (charM != '9') {
                replForMax = charM;
                break;
            }
        }
        
        int maxRes;
        if (replForMax == ' ') {
            maxRes = num;
        } else {
            StringBuilder sbMax = new StringBuilder();
            for (char chM : maxValList) {
                if (chM == replForMax) {
                    sbMax.append('9');
                } else {
                    sbMax.append(chM);
                }
            }
            maxRes = Integer.parseInt(sbMax.toString());
        }

        // Minimize
        char[] minValList = stNum.toCharArray();
        char replForMin = ' ';
        
        int minRes;
        if (minValList[0] != '1') {
            replForMin = minValList[0];
            StringBuilder sbMin = new StringBuilder();
            for (char chMin : minValList) {
                if (chMin == replForMin) {
                    sbMin.append('1');
                } else {
                    sbMin.append(chMin);
                }
            }
            minRes = Integer.parseInt(sbMin.toString());
        } else {
            for (int iMin = 1; iMin < minValList.length; iMin++) {
                if (minValList[iMin] != '0' && minValList[iMin] != '1') {
                    replForMin = minValList[iMin];
                    break;
                }
            }
            if (replForMin == ' ') {
                minRes = num;
            } else {
                StringBuilder sbMin = new StringBuilder();
                for (char chMin : minValList) {
                    if (chMin == replForMin) {
                        sbMin.append('0');
                    } else {
                        sbMin.append(chMin);
                    }
                }
                minRes = Integer.parseInt(sbMin.toString());
            }
        }
        
        return maxRes - minRes;
    }
}
