#include <iostream>

using namespace std;

struct Nod {
    int info;
    Nod *link;
};

Nod *HEAD = nullptr;

int countNumberOfElements(Nod *n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + countNumberOfElements(n->link);
}


void insertAtBeginning(int a) {
    Nod *p = new Nod;
    if (p == nullptr) {
        cout << "OVERFLOW\n";
        return;
    }
    p->info = a;
    p->link = HEAD;

    HEAD = p;
}

void insertAtEnd(int a) {
    Nod *p = new Nod;
    if (p == nullptr) {
        cout << "OVERFLOW\n";
        return;
    }
    p->info = a;
    p->link = nullptr;

    Nod *iter = HEAD;
    while (iter && iter->link) {
        iter = iter->link;
    }
    if (iter) {
        iter->link = p;
    } else {
        HEAD = p;
    }
}

void insertAfter(int a, Nod *q) {

    if (q == nullptr) {
        return;
    }
    Nod *p = new Nod;
    if (p == nullptr) {
        cout << "OVERFLOW";
        return;
    }
    p->info = a;
    p->link = q->link;
    q->link = p;

}

Nod *accessByValue(int a) {
    if (HEAD == NULL) {
        cout << "ATENTIE! Accesare neefectuata; lista goala\n";
        return NULL;
    }

    Nod *iter = HEAD;
    while (iter && iter->info != a) {
        iter = iter->link;
    }
    if (iter == NULL) {
        cout << "Elementul " << a << " nu exista!\n";
    }
    return iter;
}

Nod *accessByIndex(int a) {
    Nod *iter = HEAD;
    int i = 0;
    if (HEAD == NULL) {
        cout << "ATENTIE! Accesare neefectuata; lista goala\n";
        return NULL;
    }

    int elementsNr = countNumberOfElements(HEAD);
    if (a < 0 || a > elementsNr) {
        cout << "INVALID INDEX " << a << endl;
        return NULL;
    }

    while (iter && i != a) {
        cout << i << " ";
        i++;
        iter = iter->link;
    }
    return iter;
}

void deleteFromBeginning() {
    if (HEAD == nullptr) {
        cout << "ATENTIE! Stergere neefectuata; \n";
        return;
    }

    Nod *n = HEAD;
    HEAD = HEAD->link;
    delete n;

}

void deleteFromEnd() {
    if (HEAD == nullptr) {
        cout << "ATENTIE! Stergere neefectuata; \n";
        return;
    }

    if (HEAD->link == nullptr) {
        Nod *p = HEAD;
        HEAD = nullptr;
        delete p;
        return;
    }

    Nod *iter = HEAD;
    while ((iter->link)->link != nullptr) {
        iter = iter->link;
    }
    Nod *p = iter->link;
    iter->link = nullptr;
    delete p;
}

void deleteElement(Nod *p) {
    if (HEAD == nullptr) {
        cout << "ATENTIE! Stergere neefectuata; \n";
        return;
    }
    if (p == nullptr) {
        cout << "Pointer invalid\n";
        return;
    }

    if (HEAD == p) {
        Nod *temp = HEAD;
        HEAD = HEAD->link;
        delete temp;
        return;
    }

    Nod *iter = HEAD;
    while (iter && iter->link != p) {
        iter = iter->link;
    }
    Nod *de_sters = iter->link;
    iter->link = de_sters->link;
    delete de_sters;
}

void printList() {
    Nod *iter = HEAD;
    while (iter) {
        cout << iter->info << "->";
        iter = iter->link;
    }
    cout << "NULL\n";
}

int main() {

    printList();
    insertAtBeginning(9);
    printList();
    insertAtBeginning(2);
    printList();

    while (true) {
        int input;
        cout
                << "\n-----------------------------------------------------------------------------------------------------\n";
        cout << "| Selectati operatia:                                                                               |"
             << endl;
        cout << "| 1.     Inserarea unui element la inceputul listei                                                 |"
             << endl;
        cout << "| 2.     Inserarea unui element la sfarsitul listei                                                 |"
             << endl;
        cout << "| 3.     Inserarea unui element dupa un element dat                                                 |"
             << endl;
        cout << "| 4.     Accesarea unui element prin cautarea unei valori date in lista                             |"
             << endl;
        cout << "| 5.     Accesarea unui element prin numarul de ordine al elementului                               |"
             << endl;
        cout << "| 6.     Stergerea primului element din lista                                                       |"
             << endl;
        cout << "| 7.     Stergerea ultimului element din lista                                                      |"
             << endl;
        cout << "| 8.     Stergerea unui element dat. Se cunoaste adresa elementului care trebuie sters              |"
             << endl;
        cout << "| 9.     Afisare lista                                                                              |"
             << endl;
        cout
                << "-----------------------------------------------------------------------------------------------------\n";
        cin >> input;

        switch (input) {
            case 1:
                int a;
                cout << "Introduceti valoare: ";
                cin >> a;
                insertAtBeginning(a);
                break;
            case 2:
                cout << "Introduceti valoare: ";
                cin >> a;
                insertAtEnd(a);
                break;
            case 3:
                cout << "Introduceti valoare pentru insertie: ";
                cin >> a;
                cout << "Introduceti valoare pentru nodul dupa care inseram: ";
                int b;
                cin >> b;
                insertAfter(a, accessByValue((b)));
                break;
            case 4:
                cout << "Introduceti valoare: ";
                cin >> a;
                cout << accessByValue(a) << endl;
                break;
            case 5:
                cout << "Introduceti numar de ordine: ";
                cin >> a;
                cout << accessByIndex(a) << endl;
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                cout << "Introduceti valoare: ";
                cin >> a;
                deleteElement(accessByValue(a));
                break;
            case 9:
                printList();
                break;
            default:
                exit(0);
        }
    }
}
