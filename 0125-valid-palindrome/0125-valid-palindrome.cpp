class Solution {
public:
    bool isPalindrome(string s) {
        string n = "";
        for(auto i: s){
            if(isalnum(i)){
                n+=tolower(i);
            }
        }
        int left = 0;
        int right = n.size()-1;

        while(left<right){
            if(n[left] != n[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};