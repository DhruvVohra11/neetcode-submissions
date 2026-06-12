class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        if(s.size()<=1) return false;
        for(auto & ch: s){
            if(ch == '[' || ch == '(' || ch == '{') open.push(ch);
            else {
                if(open.empty()) return false;
                auto top = open.top();
                open.pop();
                if(ch == ')' && top!='(') return false;
                if(ch == '}' && top!='{') return false;
                if(ch == ']' && top!='[') return false;
            }
        }
        if(open.empty())
        return true;

        return false;
        

    }
};
