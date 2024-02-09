/*
 * Nume: Simpetru Eva-Maria
 * An: 2 ID
 * Grupa: 208
 *
 * Github assignment: https://github.com/evasimpetru28/Algoritmi-si-Structuri-de-Date/tree/main/laborator3
 *
 */

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
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void generateRandomNumbers() {
    srand(time(nullptr));
    for (int i = 1; i <= n; ++i) {
        v[i] = rand() % 100;
    }
}

void selectionSort() {
    cout << "Initial vector: ";
    displayVector();

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

    cout << "Sorted vector:  ";
    displayVector();
}

void insertionSort() {
    cout << "Initial vector: ";
    displayVector();

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && v[j + 1] < v[j]) {
            swap(v[j + 1], v[j]);
            j--;
        }
    }

    cout << "Sorted vector:  ";
    displayVector();

    // Best case: sorted ASC vector => n - 1 comparisons -> O(n) complexity
    // Worst case: sorted DESC vector => n(n - 1) / 2 comparisons -> O(n^2) complexity
}

void bubbleSort() {
    cout << "Initial vector: ";
    displayVector();

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

    cout << "Sorted vector:  ";
    displayVector();

    // Best case: sorted ASC vector => n - 1 comparisons -> O(n) complexity
    // Worst case: sorted DESC vector => n(n - 1) / 2 comparisons -> O(n^2) complexity
}

void interclasare(int st, int dr, int c[]) {
    int mijloc = (st + dr) / 2;
    int i = st, j = mijloc + 1, k = st;
    while (i <= mijloc && j <= dr) {
        if (v[i] < v[j]) {
            c[k] = v[i];
            i++;
        } else {
            c[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= mijloc) {
        c[k] = v[i];
        i++;
        k++;
    }
    while (j <= dr) {
        c[k] = v[j];
        j++;
        k++;
    }
}

void mergeSort(int st, int dr) {
    if (st != dr) {
        int mijloc = (st + dr) / 2;
        int c[st + dr];

        mergeSort(st, mijloc);
        mergeSort(mijloc + 1, dr);
        interclasare(st, dr, c);

        for (int i = st; i <= dr; ++i) {
            v[i] = c[i];
        }
    }
}

void mergeSort() {
    cout << "Initial vector: ";
    displayVector();

    mergeSort(0, n - 1);

    cout << "Sorted vector:  ";
    displayVector();
}

int partition(int st, int dr) {
    int pivot = dr; // Pivotul il luam mereu ca fiind ultimul element din lista
    int i = st - 1;

    for (int j = st; j <= dr - 1; j++) {
        if (v[j] <= v[pivot]) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[dr]);

    return (i + 1);
}

void quickSort(int st, int dr) {
    if (st < dr) {
        int newPivot = partition(st, dr);
        quickSort(st, newPivot - 1);
        quickSort(newPivot + 1, dr);
    }
}

void quickSort() {
    cout << "Initial vector: ";
    displayVector();

    quickSort(1, n - 1);

    cout << "Sorted vector:  ";
    displayVector();

    // Best case: equilibrated items => n log(n) comparisons -> O(n log(n)) complexity
    // Worst case: sorted ASC vector + pivot first elem => (n + 1)(n + 2) / 2 comparisons -> O(n^2) complexity
}

int main() {
    int x;

    while (true) {

        cout << "\n---------------------------------------------\n";
        cout << "|Choose method of generating the elements:  |\n";
        cout << "|  1. Manual by keyboard input              |\n";
        cout << "|  2. Random generated numbers <=100        |\n";
        cout << "---------------------------------------------\n";

        cin >> x;

        switch (x) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                readVector();
                break;
            case 2:
                cout << "Enter number of elements: ";
                cin >> n;
                generateRandomNumbers();
                break;
            default:
                exit(1);
        }

        cout << "\n---------------------------------------------\n";
        cout << "|Choose the desired sorting method:         |\n";
        cout << "|  1. Selection sort   - O(n^2)             |\n";
        cout << "|  2. Insertion sort   - O(n^2)             |\n";
        cout << "|  3. Bubble sort      - O(n^2)             |\n";
        cout << "|  4. Merge sort       - O(n log(n))        |\n";
        cout << "|  5. Quick sort       - O(n log(n))        |\n";
        cout << "---------------------------------------------\n";
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
                mergeSort();
                break;
            case 5:
                quickSort();
                break;
            default:
                exit(0);
        }
    }
}
