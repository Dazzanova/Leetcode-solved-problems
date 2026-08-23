class Solution {
public:
    bool sumGame(string num) {
        int qm = 0;
        int n = num.length();
        int mid = n / 2;
        int s1=0,s2=0;
        int q1=0,q2=0;
        for(int i=0;i<n;i++){
            if(num[i] == '?'){
                qm++;
                if(i < mid) q1++;
                else q2++;
            }
            else{
                if(i < mid) s1 += (num[i] - '0');
                else  s2 += (num[i] - '0');
            }
        }

        if(qm == 0) return s1 != s2;
        if(qm % 2 != 0) return true;
        else{
            return 2 * (s1 - s2) != 9 * (q2 - q1);
        }

    return true;
    }
};
