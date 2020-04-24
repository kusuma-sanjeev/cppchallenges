using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
	public:
		static int findKthSmallestNumber(const vector<int> &nums, int k) {
			priority_queue<int> maxHeap;

			// put first k numbers in the max heap
			for (int i = 0; i < k; i++) {
				maxHeap.push(nums[i]);
			}

			// go through the remaining numbers of the array, if the number from the array is smaller than
			// the top (biggest) number of the heap, remove the top number from heap and add the number from
			// array
			for (int i = k; i < nums.size(); i++) {
				if (nums[i] < maxHeap.top()) {
					maxHeap.pop();
					maxHeap.push(nums[i]);
				}
			}

			// the root of the heap has the Kth smallest number
			return maxHeap.top();
		}
};

int main(int argc, char *argv[]) {
	int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
	cout << "Kth smallest number is: " << result << endl;

	// since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
	result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
	cout << "Kth smallest number is: " << result << endl;

	result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
	cout << "Kth smallest number is: " << result << endl;
}

