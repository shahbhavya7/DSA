#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) //- Brute force solution
{
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) { // Fix the first element
        for (int j = i+1; j < n; j++) { // Fix the second element after the first, we don't want overlapping pairs
            for (int k = j+1; k < n; k++) { // Fix the third element after the second
                if (nums[i] + nums[j] + nums[k] == 0) {   // Check if the sum of the triplet is zero
                    vector<int> triplet = {nums[i], nums[j], nums[k]}; // Create a triplet vector
                    sort(triplet.begin(), triplet.end()); // Sort the triplet to ensure uniqueness
                    if (find(res.begin(), res.end(), triplet) == res.end()) { // Check if the triplet is already in the result
                        // If not, add it to the result
                        res.push_back(triplet);
                    }
                }
            }
        }
    }
    // Sort the result to maintain order
    sort(res.begin(), res.end());
    return res;

}

vector<vector<int>> threeSum_II(vector<int> &nums)
{
    set<vector<int>> res; // Using a set to avoid duplicates
    
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int target = -nums[i]; // We need to find two numbers that sum to -nums[i]
        set<int> s; // To store the numbers we have seen so far 
        for(int j = i + 1; j < n; j++) {
            int third = target - nums[j]; // The third number we need to find
            if (s.find(third) != s.end()) { // If the 3rd number is in the set means we found a triplet 
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end()); // Sort to ensure uniqueness
                res.insert(triplet); // Insert into the set
            }
            s.insert(nums[j]); // Add the current number to the set
        }
    }
    // Convert the set to a vector of vectors
    vector<vector<int>> result(res.begin(), res.end());
    return result; // Return the result
}

// for -1, 0, 1, 2, -1, -4 , first loop will fix -1, then target will be -nums[i] i.e 1, then we look for third number which is 1 - nums[j] i.e 1-0 = 1
// then we find 1 in the set but set is empty so we cant find it then we add nums[j] to the set and continue the loop, this time third will be 1-1 = 0, 
//now we find 0 in the set and it's there so then we create a triplet with -1, 0, 1 and insert it into the set and insert nums[j] into the set and continue 
// the loop now same things happens after that, now after checking for 1, the first loop will fix 0, set will be empty again and process will repeat

vector<vector<int>> threeSum_III(vector<int> &nums)
{
    vector<vector<int>> res; // Using a set to avoid duplicates
    sort(nums.begin(), nums.end()); // Sort the array to use two pointers technique
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int j = i + 1; // Start j from the next element
        int k = n - 1; // Start k from the end of the array
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet
            if(sum< 0) {
                j++; // If sum is less than zero, move j to the right to increase the sum
            } else if(sum > 0) {
                k--; // If sum is greater than zero, move k to the left to decrease the sum
            } else {
                // If we found a triplet with sum zero
                res.push_back({nums[i], nums[j], nums[k]}); // Add the triplet to the result
                // Move j and k to the next different elements to avoid duplicates
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++; // Skip duplicates for j
            }
        }
    }
    // Sort the result to maintain order
    sort(res.begin(), res.end());
    return res; // Return the result
}

// for -4, -1, -1, 0, 1, 2 , i will be at -4 initially, j will be at -1 and k will be at 2, we will continue until j is less than k, we will check the sum of 
// (-4, -1, 2) which is -3, since it's less than zero we will move j to the right to increase the sum, now j will be at 0 and k will be at 2, we try to bring
// sum to zero, j directly moved to 0 as after -1 there was another -1 we would give same triplet again using j so to avoid duplicate we skip it do j++
// now we check sum of (-4, 0, 2) which is -2, again less than zero so we move j to the right again, now j will be at 1 and k will be at 2, we check sum of
// (-4, 1, 2) which is -1, again less than zero so we move j to the right again, now j will be at 2 and k will be at 2, now j is not less than k so we 
//exit the inner loop and i will be at -1 now j will be at 0 and k will be at 2, we check sum of (-1, 0, 2) which is 1, since it's greater than zero we move 
// k to the left to decrease the sum now k will be at 1, we check sum of (-1, 0, 1) which is 0, we found a triplet so we add it to the result and move j to the 
// right and k to the left now j will be at 1 and k will be at 0, now j is not less than k so we exit the inner loop and i will be at 0 now, 
//j will be at 1 and k will be at 2, i also skips -1 as it is duplicate and would give same triplet again, i.e -1,0,1 , in both loops we want unique triplets
// we sort the array initially to make sure we can skip duplicates easily by just continue or j++ .

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum_III(nums);
    for (const auto &triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}