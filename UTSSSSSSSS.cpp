#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

int convertBinaryToDecimal(Node* head) {
    if (head == NULL) {
        return 0;
    }
    Node* current = head;
    int decimal = 0;
    int power = 1;
    while (current != NULL) {
        decimal += current->data * power;
        power *= 2;
        current = current->next;
    }
    return decimal;
}

void konversi(int desimal) {
    stack<char> s;
    while (desimal > 0) {
        int sisa = desimal % 16;
        switch (sisa) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                s.push(sisa + '0');
                break;
            default:
                s.push(sisa - 10 + 'A');
                break;
        }
        desimal = desimal / 16;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    int choice;
    cout << "Pilih operasi:" << endl;
    cout << "1. Konversi biner ke desimal" << endl;
    cout << "2. Konversi desimal ke heksadesimal" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Node* head = NULL;
            string binaryString;
            cout << "Masukkan bilangan biner: ";
            cin >> binaryString;
            for (int i = 0; i < binaryString.length(); i++) {
                if (binaryString[i] == '0' || binaryString[i] == '1') {
                    int bit = binaryString[i] - '0';
                    insert(&head, bit);
                }
            }
            int decimal = convertBinaryToDecimal(head);
            cout << "Bilangan desimal: " << decimal << endl;
            break;
        }
        case 2: {
            int desimal;
            cout << "Masukkan bilangan desimal: ";
            cin >> desimal;
            cout << desimal << " dalam basis heksadesimal adalah: ";
            konversi(desimal);
            cout << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }

    return 0;
}
