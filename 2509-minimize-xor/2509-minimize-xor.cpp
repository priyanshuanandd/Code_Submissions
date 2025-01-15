class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 = 0, cnt1 = 0;
        while (num2 > 0) {
            cnt2 += (num2 & 1);
            num2 >>= 1;
        }
        num2 = num1;
        string s1(32,'0');
        int indx = 0 ;
        while (num2 > 0) {
            s1[indx]= '0' + (num2 % 2);
            num2 /= 2;
            indx++;
        }
        
        cout << s1 << endl;
        num2 = num1;
        while (num2 > 0) {
            cnt1 += (num2 & 1);
            num2 >>= 1;
        }
        if (cnt1 == cnt2) {
            return num1;
        }
        cout << cnt1 << " " << cnt2 << endl;
        for(int i = 0 ; i < s1.size() ;i++){
            if(cnt1 > cnt2 and s1[i] == '1'){
                cnt1--;
                s1[i] = '0';
            }
            else if(cnt2 > cnt1 and s1[i] == '0'){
                cout << i << endl;
                s1[i] = '1';
                cnt2--;
            }
        }

        int ans = 0;
        long long power = 1;
        for(int i = 0; i < s1.size();i++){
            ans+=(s1[i]-'0')*(power);
            power*=2;
        }
        
        return ans;
    }
};