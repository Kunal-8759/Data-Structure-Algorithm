class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{//close
                if(st.size()==0) return false;
                char lastOpening=st.top();
                st.pop();
                if(lastOpening=='{' && s[i]!='}') return false;
                if(lastOpening=='[' && s[i]!=']') return false;
                if(lastOpening=='(' && s[i]!=')') return false;
            }
        }
        if(st.size()==0) return true;
        return false;
    }
};