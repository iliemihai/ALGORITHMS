#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//simple solution
//Runtime: 320 ms, faster than 7.80% of C++ online submissions for Two Sum.
//Memory Usage: 9.3 MB, less than 86.65% of C++ online submissions for Two Sum."
class Solution1 {
private:
    vector<int> res;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n;j++)
                if(target-nums[i]==nums[j]) {
                    res.push_back(i);
                    res.push_back(j);
                }
        return res;
    }
};

//hashtable
//Runtime: 8 ms, faster than 92.82% of C++ online submissions for Two Sum.
//Memory Usage: 10.7 MB, less than 6.54% of C++ online submissions for Two Sum."
class Solution2 {
private:
    vector<int> res;
    map<int, int> h;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            auto it = h.find(target-nums[i]);

            if(it!=h.end()){
                res.push_back(it->second);
                res.push_back(i);
            }
            h[nums[i]] = i;
        }
        return res;
    }
};

//not working when sorting
class Solution3 {
private:
    vector<int> res;
public:
    int binary_search(vector<int>& nums, int l, int r, int k) {
        if (l>r)
            return -1;
        int m = (l+r)/2;
        if(k == nums[m])
            return m;
        if(k<nums[m])
            return binary_search(nums, l, m-1, k);
        else
            return binary_search(nums, m+1, r, k);
    }
    
    int find_index(vector<int>&  nums, int k) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==k)
                return i;
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy_nums = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            int j = binary_search(nums, 0, n, target-nums[i]);
            if(j!=-1) {
                    res.push_back(find_index(copy_nums, nums[i]));
                    res.push_back(find_index(copy_nums, nums[j]));
                    break;
                }
        }
        return res;
    }
};
