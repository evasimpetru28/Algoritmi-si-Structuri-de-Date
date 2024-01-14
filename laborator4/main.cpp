#include <iostream>

using namespace std;

int n, v[100];

void displayVector() {
    cout << "[" << v[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << "]\n";
}

void readVector() {
    cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void generateRandomNumbers() {
    srand(time(nullptr));
    for (int i = 1; i <= n; ++i) {
        v[i] = rand() % 101;
    }
}

int recursiveBinarySearch(int x, int st, int dr) {
    if (st > dr) {
        return -1;
    }

    int mijloc = (st + dr) / 2;
    if (v[mijloc] == x) {
        return mijloc;
    } else {
        if (x > v[mijloc]) {
            st = mijloc + 1;
        } else {
            dr = mijloc - 1;
        }
        recursiveBinarySearch(x, st, dr);
    }
}

void binarySearch(int x) {
    bool found = false;
    int st = 0;
    int dr = n - 1;
    while (!found && st <= dr && dr >= 1) {
        int mijloc = (st + dr) / 2;
        if (v[mijloc] == x) {
            found = true;
        } else {
            if (x > v[mijloc]) {
                st = mijloc + 1;
            } else {
                dr = mijloc - 1;
            }
        }
    }

    if (found) {
        cout << "Element " << x << " was found at position " << st << ".\n";
    } else {
        cout << "Element " << x << " was NOT found.\n";
    }

    // BEST case: elem is middle position => O(1)
    // WORST case: elem is not found OR found in a sequence of length 1 => O(log(n))
}

void sequentialSearch(int x) {
    bool found = false;
    int i = 0;
    while (!found && i < n) {
        if (v[i] == x) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        cout << "Element " << x << " was found at position " << i << ".\n";
    } else {
        cout << "Element " << x << " was NOT found.\n";
    }

    // BEST case: elem is on first position => O(1)
    // WORST case: elem is on last position OR not found => O(n)
}

int main() {

    int a;
    cout << "\n-----------------------------------\n";
    cout << "Choose method of generating the elements:\n";
    cout << "|  1. Manual by keyboard input\n";
    cout << "|  2. Random generated numbers <=100\n";
    cout << "-----------------------------------\n";

    cin >> a;

    cout << "Enter number of elements: ";
    cin >> n;

    switch (a) {
        case 1:
            readVector();
            break;
        case 2:
            generateRandomNumbers();
            break;
        default:
            return 1;
    }

    cout << "Vector: ";
    displayVector();

    int x;
    cout << "Enter searched element: ";
    cin >> x;

    cout << "\n----------------------------------------\n";
    cout << "Choose the desired search method:\n";
    cout << "|  1. Sequential search    O(n)\n";
    cout << "|  2. Binary search\n";
    cout << "-----------------------------------------\n";
    cin >> a;
    cout << endl;

    switch (a) {
        case 1:
            sequentialSearch(x);
            break;
        case 2:
            binarySearch(x);
            break;
        default:
            return -1;
    }

    return 0;
}
