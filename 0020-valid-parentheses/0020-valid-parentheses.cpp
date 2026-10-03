class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.size()==0){
                    return 0;
                }
                else{
                    char x = st.top();
                    st.pop();
                     if((x=='(' && s[i]==')') || 
                       (x=='[' && s[i]==']') || 
                       (x=='{' && s[i]=='}')) {
                        continue;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
        if(st.empty()) return 1;
        return 0;

    }
};