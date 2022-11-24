//
// Created by fsindustry on 2022/8/26.
//
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // (num, count)
        unordered_map<int, int> countMap;
        for (int num: nums) {
            if (countMap.find(num) == countMap.end()) {
                countMap[num] = 1;
            } else {
                countMap[num] = countMap[num] + 1;
            }
        }

        // (count, num)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        for (const pair<int, int> &entry : countMap) {
            if (queue.size() < k) {
                queue.push(make_pair(entry.second, entry.first));
            } else {
                if (entry.second > queue.top().first) {
                    queue.pop();
                    queue.push(make_pair(entry.second, entry.first));
                }
            }
        }

        vector<int> res;
        while (!queue.empty()) {
            res.push_back(queue.top().second);
            queue.pop();
        }

        return res;
    }
};


class Solution1 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // (num, count)
        unordered_map<int, int> countMap;
        for (int num: nums) {
            if (countMap.find(num) == countMap.end()) {
                countMap[num] = 1;
            } else {
                countMap[num] = countMap[num] + 1;
            }
        }


        vector<int> res;
        if(countMap.size() - k == 0){
            for (const pair<int, int> &entry : countMap) {
                res.push_back(entry.first);
            }
            return res;
        }

        // (count, num)
        priority_queue<pair<int, int>, vector<pair<int, int>>> queue;
        for (const pair<int, int> &entry : countMap) {
            if (queue.size() < countMap.size() - k) {
                queue.push(make_pair(entry.second, entry.first));
            } else {
                if (entry.second < queue.top().first) {
                    res.push_back(queue.top().second);
                    queue.pop();
                    queue.push(make_pair(entry.second, entry.first));
                } else {
                    res.push_back(entry.first);
                }
            }
        }

        return res;
    }
};
