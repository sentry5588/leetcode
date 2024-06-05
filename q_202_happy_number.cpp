class Solution {

private:
    int digit_square_sum(int n);

public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (!seen.contains(n)) {
            if (n == 1) {
                return true;
            } 
            seen.insert(n);
            n = digit_square_sum(n);
        }
        return false;
    }
};

// Practice method outside of class block
int Solution::digit_square_sum(int n) {
    if (n >= 10) { // Practice recurrion
        return (n%10) * (n%10) + digit_square_sum(n/10);
    } else {
        return (n%10) * (n%10);
    }
}