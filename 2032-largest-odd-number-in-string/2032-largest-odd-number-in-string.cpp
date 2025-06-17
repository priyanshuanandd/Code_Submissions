class Solution {
public:
    string largestOddNumber(string num) {
        int indx = -1;
        for(int i = 0;i < num.size();i++){
            if((num[i]-'0')%2!=0){
                indx = i;
            }
        }
        
        return num.substr(0,indx+1);
    }
};