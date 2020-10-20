#include <iostream>

using namespace std;

class Lnode_list {
private:
    typedef struct Lnode {
        int data;
        Lnode *next;
    };
    Lnode *head;

public:
    Lnode_list() {
        head = new Lnode;
        head->next = nullptr;
        head->data = 0;
    }

    void insert_list(int e) {
        Lnode *s = new Lnode;
        s->data = e;
        s->next = nullptr;
        Lnode *p = head;
        for (;;) {
            if (p->next == nullptr) {
                p->next = s;
                break;
            }
            p = p->next;
        }
    }

    void print() {
        Lnode *p;
        p = head;
        if (p->next == nullptr) {
            return;
        }
        p = p->next;
        while (p != nullptr) {
            cout << p->data;
            if (p->next != nullptr) {
                cout << ",";
            }
            p = p->next;
        }
        cout << endl;
    }

    int even_number() {
        Lnode *p = head;
        int number = 0;
        if (p->next == nullptr) {
            return 0;
        }

        p = p->next;
        while (p) {
            if (p->data % 2 == 0) {
                number++;
            }
            p = p->next;
        }
        return number;
    }

    void delete_same() {
        Lnode *p = head;
        Lnode *pr, *prr;
        if (p->next == nullptr) {
            return;
        }

        while ((p = p->next) != nullptr) {
            pr = p;
            while (pr->next) {
                prr = pr;
                pr = pr->next;
                if (pr->data == p->data) {
                    prr->next = pr->next;
                    delete pr;
                    pr = prr;
                }
            }
        }
    }

    int del_x(int x) {
        Lnode *p = head;
        Lnode *pr;
        int flag = 0;
        while (p->next) {
            pr = p;
            p = p->next;
            if (p->data == x) {
                pr->next = p->next;
                delete p;
                p = pr;
                flag = 1;
            }
        }
        return flag;
    }
};

int main() {
    Lnode_list Lnode1;
    Lnode1.insert_list(1);
    Lnode1.insert_list(2);
    Lnode1.insert_list(1);
    Lnode1.insert_list(4);
    Lnode1.insert_list(4);
    Lnode1.insert_list(4);
    cout << "����Ԫ��:" << endl;
    Lnode1.print();
    cout << "�� " << Lnode1.even_number() << " ��ż��" << endl;
    Lnode1.delete_same();
    cout << "����Ԫ��:" << endl;
    Lnode1.print();
    cout << "ɾ��������ֵΪ2����������Ϊ��" << endl;
    cout << Lnode1.del_x(2) << endl;
    cout << "����Ԫ��:" << endl;
    Lnode1.print();
    getchar();
    return 0;
}
