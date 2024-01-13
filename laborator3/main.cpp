#include <iostream>

using namespace std;

int n, v[100];

void displayVector() {
    cout << "Vectorul sortat: [" << v[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << "]\n";
}

void readVector() {
    cout << "Introduceti nr elemente: ";
    cin >> n;

    cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void selectionSort() {

    for (int j = 0; j < n - 1; j++) {
        int min = v[j];
        int index_min = j;
        for (int i = j + 1; i < n; ++i) {
            if (v[i] < min) {
                min = v[i];
                index_min = i;
            }
        }
        if (index_min != j) {
            swap(v[j], v[index_min]);
        }
    }

    displayVector();
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && v[j + 1] < v[j]) {
            swap(v[j + 1], v[j]);
            j--;
        }
    }

    displayVector();

    // Best case: sorted ASC vector => n - 1 comparisons -> O(n) complexity
    // Worst case: sorted DESC vector => n(n - 1) / 2 comparisons -> O(n^2) complexity
}

void bubbleSort() {
    bool hasChanged;
    int lastElem = n;
    do {
        hasChanged = false;
        for (int i = 0; i < lastElem - 1; ++i) {
            if (v[i] > v[i + 1]) {
                hasChanged = true;
                swap(v[i], v[i + 1]);
            }
        }
        lastElem--;
    } while (hasChanged);

    displayVector();

    // Best case: sorted ASC vector => n - 1 comparisons -> O(n) complexity
    // Worst case: sorted DESC vector => n(n - 1) / 2 comparisons -> O(n^2) complexity
}

void quickSort() {

    displayVector();
}

int main() {


    readVector();

    int x;
    cout << "\n-----------------------------------\n";
    cout << "Alegeti metoda de sortare:\n";
    cout << "|  1. Selection sort   - O(n^2)\n";
    cout << "|  2. Insertion sort   - O(n^2)\n";
    cout << "|  3. Bubble sort      - O(n^2)\n";
    cout << "|  4. Quick sort       - O(n^2)\n";
    cout << "-----------------------------------\n";
    cin >> x;
    cout << endl;

    switch (x) {
        case 1:
            selectionSort();
            break;
        case 2:
            insertionSort();
            break;
        case 3:
            bubbleSort();
            break;
        case 4:
            quickSort();
            break;
        default:
            return 0;
    }

    return 0;
}
