using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
    public:
        static int findSingleNumber(const vector<int>& arr) {
            int num = 0;
            for (int i=0; i < arr.size(); i++) {
                num = num ^ arr[i];
            }
            return num;
        }
};

int main(int argc, char* argv[]) {
    cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}
