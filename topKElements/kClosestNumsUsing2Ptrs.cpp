using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class KClosestElements {
    public:
        static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
            deque<int> result;
            int index = binarySearch(arr, X);
            int leftPointer = index;
            int rightPointer = index + 1;
            for (int i = 0; i < K; i++) {
                if (leftPointer >= 0 && rightPointer < (int)arr.size()) {
                    int diff1 = abs(X - arr[leftPointer]);
                    int diff2 = abs(X - arr[rightPointer]);
                    if (diff1 <= diff2) {
                        result.push_front(arr[leftPointer--]);  // append in the beginning
                    } else {
                        result.push_back(arr[rightPointer++]);  // append at the end
                    }
                } else if (leftPointer >= 0) {
                    result.push_front(arr[leftPointer--]);
                } else if (rightPointer < (int)arr.size()) {
                    result.push_back(arr[rightPointer++]);
                }
            }
            vector<int> resultVec;
            std::move(std::begin(result), std::end(result), std::back_inserter(resultVec));
            return resultVec;
        }

    private:
        static int binarySearch(const vector<int> &arr, int target) {
            int low = 0;
            int high = (int)arr.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) {
                    return mid;
                }
                if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (low > 0) {
                return low - 1;
            }
            return low;
        }
};

int main(int argc, char *argv[]) {
    vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
    cout << "'K' closest numbers to 'X' are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
    cout << "'K' closest numbers to 'X' are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 10);
    cout << "'K' closest numbers to 'X' are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}

