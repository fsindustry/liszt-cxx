//
// Created by fsindustry on 7/4/22.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> result;
        for(int v : nums2){
            if(set1.find(v) != set1.end()){
                result.insert(v);
            }
        }

        return vector<int>{result.begin(), result.end()};
    }
};