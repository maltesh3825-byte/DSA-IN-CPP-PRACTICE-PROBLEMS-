//count distinct
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countDistinct(vector<int> arr) {
    unordered_set<int> s;

    // Insert all elements into the unordered_set
    for (int i = 0; i < arr.size(); i++) {
        s.insert(arr[i]);
    }

    // The size of the set represents the count of distinct elements
    return s.size();
}

int main() {
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << "Count of distinct elements: " << countDistinct(arr) << endl;

    return 0;
}