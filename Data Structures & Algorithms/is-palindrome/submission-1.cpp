class Solution {
public:
    bool isPalindrome(string s) {
        string og = "";

        for(auto & x: s){
            if(isalpha(x) || isdigit(x)){
                og+=tolower(x);
            }
        }

        int size = og.size()-1;
        string r = "";
        for(int i = size ; i>=0; i--){
            r+=og[i];
        }


        if(r == og)
        return true;

        return false;
    }
};
