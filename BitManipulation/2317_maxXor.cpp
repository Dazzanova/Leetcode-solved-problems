class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int x = 0;
        for(int num : nums){
            x = num | x;
        }
        return x;
    }
};
