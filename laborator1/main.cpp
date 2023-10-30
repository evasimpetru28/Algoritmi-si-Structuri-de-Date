#include <iostream>

using namespace std;
#define N 100

int myList[N], n;

void introducere_elem(int deIntrodus, int pos) {
    if (n == N) {
        cout << "OVERFLOW\n";
        return;
    }
    if (pos == 0 && n == 0) {
        myList[0] = deIntrodus;
        n++;
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position. Position should be in interval: [0," << n << ")\n";
        return;
    }

    for (int i = n; i > pos; i--) {
        myList[i] = myList[i - 1];
    }
    myList[pos] = deIntrodus;
    n++;
}

void stergere_elem(int pos) {
    if (n == 0) {
        cout << "UNDERFLOW\n";
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position. Position should be in interval: [0," << n << ")\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        myList[i] = myList[i + 1];
    }
    n--;
}

int accesare_elem(int pos) {
    if (n == 0) {
        cout << "UNDERFLOW\n";
        return NULL;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position. Position should be in interval: [0," << n << ")\n";
        return NULL;
    }
    return myList[pos];
}

void modificare_elem(int pos, int nouaValoare) {
    if (n == 0) {
        cout << "EMPTY LIST\n";
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position. Position should be in interval: [0," << n << ")\n";
        return;
    }
    myList[pos] = nouaValoare;
}

void afisare_lista() {
    cout << "[";
    if (n >= 1) {
        cout << myList[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << ", " << myList[i];
    }
    cout << "]\n";
}


void new_list() {
    int a, nr;
    cout << "Introduceti numarul de elemente dorite: ";
    cin >> nr;
    if (nr <= 0 || nr >= N) {
        cout << "Invalid number; should be in interval: [0," << N << ")\n";
        return;
    }

    n = nr;
    for (int i = 0; i < n; ++i) {
        cout << "Introduceti elem " << i << ": ";
        cin >> a;
        myList[i] = a;
    }

    cout << "[";
    if (n >= 1) {
        cout << myList[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << ", " << myList[i];
    }
    cout << "]\n";
}

void creare_lista() {
    if (n != 0) {
        cout << "\nExista deja o lista. Introduceti optiunea dorita: \n";
        cout << "   | 1. Discard lista veche\n";
        cout << "   | 2. Pastrez lista veche\n";
        int a;
        cin >> a;

        switch (a) {
            case 1:
                new_list();
                break;
            case 2:
                break;
            default:
                exit(0);
        }

    } else {
        new_list();
    }

}

int main() {
    while (true) {
        int input;
        cout << "Selectati operatia: " << endl;
        cout << "1.     Introducere elem" << endl;
        cout << "2.     Stergere elem" << endl;
        cout << "3.     Accesare elem" << endl;
        cout << "4.     Modificare elem" << endl;
        cout << "5.     Creare lista" << endl;
        cout << "6.     Afisare lista" << endl;

        cin >> input;

        switch (input) {
            case 1:
                int a, pos;
                cout << "Introduceti valoare: ";
                cin >> a;
                cout << "Introduceti pozitia de inserare: ";
                cin >> pos;
                introducere_elem(a, pos);
                break;
            case 2:
                cout << "Introduceti pozitia de stergere: ";
                cin >> pos;
                stergere_elem(pos);
                break;
            case 3:
                cout << "Introduceti pozitia: ";
                cin >> pos;
                cout << accesare_elem(pos) << endl;
                break;
            case 4:
                cout << "Introduceti pozitia: ";
                cin >> pos;
                cout << "Introduceti noua valoare: ";
                cin >> a;
                modificare_elem(pos, a);
                break;
            case 5:
                creare_lista();
                break;
            case 6:
                afisare_lista();
                break;
            default:
                exit(0);
        }
    }
}
