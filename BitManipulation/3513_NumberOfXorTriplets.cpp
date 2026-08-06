class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int msb = 31 - __builtin_clz(n);

        int res = (1 << (1+msb));
        return res;
    }
};