class Solution {
public:
    bool helper(int x, int co, long long rev){
        if(x==0){
            return co==rev;
        }
        int digit = x%10;
        rev = rev*10+digit;
        return helper(x/10, co, rev);
    }
    bool isPalindrome(int x) {
        if(x<0) return 0;
        return helper(x, x,0);
    }
};