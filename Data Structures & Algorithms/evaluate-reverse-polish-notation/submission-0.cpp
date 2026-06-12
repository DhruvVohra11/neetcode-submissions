class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int out;
        for(auto & ch: tokens){
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/"){
                st.push(stoi(ch));
            }
            else{
                if(ch == "+"){
                    auto a = st.top();
                    st.pop();
                    auto b = st.top();
                    st.pop();
                    st.push(a+b);
                }
                if(ch == "*"){
                    auto a = st.top();
                    st.pop();
                    auto b = st.top();
                    st.pop();
                    st.push(a*b);
                }
                if(ch == "-"){
                    auto a = st.top();
                    st.pop();
                    auto b = st.top();
                    st.pop();
                    st.push(b-a);
                }
                if(ch == "/"){
                    auto a = st.top();
                    st.pop();
                    auto b = st.top();
                    st.pop();
                    st.push(b/a);
                }

            }
        }
        return st.top();
    }
};
