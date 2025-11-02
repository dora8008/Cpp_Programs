#include <iostream>
using namespace std;

int main() {
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i;
            found = true;
            break;
        }
    }
    if (!found) cout << "Not Found";
    return 0;
}
