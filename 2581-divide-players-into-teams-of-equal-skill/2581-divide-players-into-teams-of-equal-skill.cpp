class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans = 0 ;
        int prev = 0 ;
        for(int i = 0 ; i < skill.size()/2 ; i++){
            if(i!=0){
                int curr = skill[i]+skill[skill.size()-1-i];
                if(curr!=prev){
                    return -1;
                }
            }
            else{
                prev = skill[i]+skill[skill.size()-1-i];
            }
            ans += (skill[i])*(skill[skill.size()-1-i]);
        }
        return ans;
    }
};