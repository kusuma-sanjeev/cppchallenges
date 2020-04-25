using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
    public:
        struct valueCompare {
            bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
                return x.second > y.second;
            }
        };

        static int findMaximumDistinctElements(const vector<int> &nums, int k) {
            int distinctElementsCount = 0;
            if (nums.size() <= k) {
                return distinctElementsCount;
            }

            // find the frequency of each number
            unordered_map<int, int> numFrequencyMap;
            for (auto i : nums) {
                numFrequencyMap[i]++;
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

            // insert all numbers with frequency greater than '1' into the min-heap
            for (auto entry : numFrequencyMap) {
                if (entry.second == 1) {
                    distinctElementsCount++;
                } else {
                    minHeap.push(entry);
                }
            }

            // following a greedy approach, try removing the least frequent numbers first from the min-heap
            while (k > 0 && !minHeap.empty()) {
                auto entry = minHeap.top();
                minHeap.pop();
                // to make an element distinct, we need to remove all of its occurrences except one
                k -= entry.second - 1;
                if (k >= 0) {
                    distinctElementsCount++;
                }
            }

            // if k > 0, this means we have to remove some distinct numbers
            if (k > 0) {
                distinctElementsCount -= k;
            }

            return distinctElementsCount;
        }
};

int main(int argc, char *argv[]) {
    int result =
        MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = MaximumDistinctElements::findMaximumDistinctElements(
            vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}

