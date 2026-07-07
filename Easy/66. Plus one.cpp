class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {

            // If digit is less than 9, simply increase it
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If digit is 9, it becomes 0 and carry continues
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};