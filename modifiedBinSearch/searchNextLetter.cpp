using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
    public:
        static char searchNextLetter(const vector<char>& letters, char key) {
            int n = letters.size();
            if (key < letters[0] || key > letters[n - 1]) {
                return letters[0];
            }

            int start = 0, end = n - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (key < letters[mid]) {
                    end = mid - 1;
                } else {  // if (key >= letters[mid]) {
                    start = mid + 1;
                }
                }
                // since the loop is running until 'start <= end', so at the end of the
                // while loop, 'start == end+1'
                return letters[start % n];
            }
    };

int main(int argc, char* argv[]) {
    cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
    cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
    cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
    cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}

