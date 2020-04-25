using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
    public:
        struct numCompare {
            bool operator()(const int &x, const int &y) { return x > y; }
        };

        priority_queue<int, vector<int>, numCompare> minHeap;
        const int k;

        KthLargestNumberInStream(const vector<int> &nums, int k) : k(k) {
            // add the numbers in the min heap
            for (int i = 0; i < nums.size(); i++) {
                add(nums[i]);
            }
        }

        virtual int add(int num) {
            // add the new number in the min heap
            minHeap.push(num);

            // if heap has more than 'k' numbers, remove one number
            if ((int)minHeap.size() > this->k) {
                minHeap.pop();
            }

            // return the 'Kth largest number
            return minHeap.top();
        }
};

int main(int argc, char *argv[]) {
    KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
    cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
    cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
    cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}

