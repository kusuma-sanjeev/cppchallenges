using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
    public:
        struct valueCompare {
            bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
                return y.second > x.second;
            }
        };

        static string sortCharacterByFrequency(const string &str) {
            // find the frequency of each character
            unordered_map<char, int> characterFrequencyMap;
            for (char chr : str) {
                characterFrequencyMap[chr]++;
            }

            priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

            // add all characters to the max heap
            for (auto entry : characterFrequencyMap) {
                maxHeap.push(entry);
            }

            // build a string, appending the most occurring characters first
            string sortedString = "";
            while (!maxHeap.empty()) {
                auto entry = maxHeap.top();
                maxHeap.pop();
                for (int i = 0; i < entry.second; i++) {
                    sortedString += entry.first;
                }
            }

            return sortedString;
        }
};

int main(int argc, char *argv[]) {
    string result = FrequencySort::sortCharacterByFrequency("Programming");
    cout << "Here is the given string after sorting characters by frequency: " << result << endl;

    result = FrequencySort::sortCharacterByFrequency("abcbab");
    cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}

