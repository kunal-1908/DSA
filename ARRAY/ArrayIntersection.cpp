#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Insert all elements of nums1 into an unordered_set
        unordered_set<int> set1(nums1.begin(), nums1.end());
        
        // Step 2: Create another unordered_set to store common elements
        unordered_set<int> common;
        
        // Step 3: Iterate over nums2 and check for common elements
        for (auto el : nums2) {
            // Use find() instead of contains()
            if (set1.find(el) != set1.end()) {  // Check if el exists in set1
                common.insert(el);  // Insert the common element into the common set
            }
        }
        
        // Step 4: Convert the unordered_set 'common' to a vector
        vector<int> ans(common.begin(), common.end());
        
        // Step 5: Return the result vector
        return ans;
    }
};

int main() {
    // Test case
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    Solution sol;
    vector<int> result = sol.intersection(nums1, nums2);
    
    // Print the result
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
