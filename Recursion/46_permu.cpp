class Solution {
    void solve(vector<int> &nums, int n,int idx, vector<vector<int>> &res){
        if(idx == n){
            res.push_back(nums);
            return;
        }

        for(int j=idx,j<n;j++){
            swap(nums[idx], nums[j]);
            solve(nums,n,idx,res);
            swap(nums[idx], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        int idx = 0;
        solve(nums,n,idx,res);
        return res;
    }
};
