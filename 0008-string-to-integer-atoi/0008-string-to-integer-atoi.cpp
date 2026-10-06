class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
    int n = s.size();
    
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    if (i == n) {
        return 0;
    }
    
    int sign = 1;
    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }
    
    long long result = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        result = result * 10 + digit;
        
        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;
        
        i++;
    }
    
    return sign * result;
        
    }
};