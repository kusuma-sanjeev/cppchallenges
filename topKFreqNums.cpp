using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
    struct valueCompare {
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return x.second > y.second;
        }
    };

    public:
    static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
        // find the frequency of each number
        unordered_map<int, int> numFrequencyMap;
        for (int n : nums) {
            numFrequencyMap[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

        // go through all numbers of the numFrequencyMap and push them in the minHeap, which will have
        // top k frequent numbers. If the heap size is more than k, we remove the smallest (top) number
        for (auto entry : numFrequencyMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // create a list of top k numbers
        vector<int> topNumbers;
        while (!minHeap.empty()) {
            topNumbers.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return topNumbers;
    }
};

int main(int argc, char *argv[]) {
    vector<int> result =
        TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
    cout << "Here are the K frequent numbers: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
    cout << "Here are the K frequent numbers: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}

