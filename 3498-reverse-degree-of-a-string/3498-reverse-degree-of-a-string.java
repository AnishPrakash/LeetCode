class Solution {
    public int reverseDegree(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int reverseAlphabetValue = 26 - (c - 'a');
            int stringIndex = i + 1;
            sum += reverseAlphabetValue * stringIndex;
        }
        return sum;
    }
}