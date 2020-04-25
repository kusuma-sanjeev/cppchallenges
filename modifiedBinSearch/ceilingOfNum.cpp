using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
    public:
        static int searchCeilingOfANumber(const vector<int>& arr, int key) {
            if (key > arr[arr.size() - 1]) {  // if the 'key' is bigger than the biggest element
                return -1;
            }

            int start = 0, end = arr.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (key < arr[mid]) {
                    end = mid - 1;
                } else if (key > arr[mid]) {
                    start = mid + 1;
                } else {  // found the key
                    return mid;
                }
            }
            // since the loop is running until 'start <= end', so at the end of the while loop, 'start ==
            // end+1' we are not able to find the element in the given array, so the next big number will be
            // arr[start]
            return start;
        }
};

int main(int argc, char* argv[]) {
    cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
    cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
    cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
    cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}

