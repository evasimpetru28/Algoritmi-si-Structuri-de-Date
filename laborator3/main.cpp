#include <iostream>

using namespace std;

int n, v[100];

void afisareVector(int v[], int n) {
    cout << "Vectorul sortat: [" << v[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << "]\n";
}

void citireVector() {
    cout << "Introduceti nr elemente: ";
    cin >> n;

    cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void selectionSort(int v[], int n) {

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

    afisareVector(v, n);
}

int main() {


    citireVector();

    int x;
    cout << "\n-----------------------------------\n";
    cout << "Alegeti metoda de sortare:\n";
    cout << "|  1. Selection sort - O(n^2)\n";
    cout << "-----------------------------------\n";
    cin >> x;
    cout << endl;

    switch (x) {
        case 1:
            selectionSort(v, n);
            break;
        default:
            return 0;
    }

    return 0;
}
