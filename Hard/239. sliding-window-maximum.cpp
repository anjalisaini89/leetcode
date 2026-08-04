class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < A.size(); ++i) {
            if (q.size() && q.front() == i - k) q.pop_front();
            while (q.size() && A[q.back()] <= A[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(A[q.front()]);
        }
        return ans;
    }
};


// Solution 2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() && i - q.front() >= k) {
                q.pop_front();
            }
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};