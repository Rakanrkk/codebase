//
// Created by Rakan on 2022/5/11.
//
#include <iostream>

using namespace std;

class Node {
public:
    explicit Node(int d = 0) : data(d) {};

    ~Node() = default;

    int data;
    Node *next = nullptr;

    friend Node operator+(const Node &first, const int other) {
        Node temp;
        temp.data = first.data + other;
        temp.next = first.next;
        return temp;
    }

    friend void operator+=(int &first, const Node &other) {
        first += other.data;
    }

};

class Linklist {

public:
    explicit Linklist() {
        cout << "LinkList()0" << endl;
    };

    explicit Linklist(int n) {
        cout << "LinkList()" << n << endl;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            push_back(tmp);
        }
    }

    Linklist(Linklist &other) {
        length = other.length;
        Node *iter = other.start;
        start = new Node(iter->data);
        last = start;
        while (iter->next != nullptr) {
            iter = iter->next;
            last->next = new Node(iter->data);
            last = last->next;
        }
    }

    ~Linklist() {
        Node *iter = start;
        while (iter != nullptr) {
            Node *tmp = iter;
            iter = iter->next;
            delete tmp;
        }
        cout << "~LinkList()"<< length << endl;
    }

    int Count() const {
        return length;
    }

    void push_back(int x) {
        if (start == nullptr) {
            start = new Node(x);
            last = start;
            length++;
        } else {
            last->next = new Node(x);
            last = last->next;
            length++;
        }
    }

    void append(Node *other) {
        if (start == nullptr) {
            start = other;
            last = start;
            length++;
            while (last->next != nullptr) {
                last = last->next;
                length++;
            }
        } else {
            last->next = other;
            while (last->next != nullptr) {
                last = last->next;
                length++;
            }
        }
    }

    void print() {
        Node *iter = start;
        while (iter != nullptr) {
            cout << iter->data << ' ';
            iter = iter->next;
        }
        cout << endl;
    }

    Node &operator[](int idx) {
        Node *iter = start;
        for (int i = 0; i < idx; i++) {
            iter = iter->next;
        }
        return *iter;
    }

private:
    int length = 0;
    Node *start = nullptr;//首元节点
    Node *last = nullptr;//指向最后一个节点的指针，非空
};


int main() {
    int n;
    cin >> n;
    Linklist La(n);
    cin >> n;
    Linklist Lb(n);
    Linklist Lc;
    for (int i = 0; i < La.Count(); i++) {
        for (int j = 0; j < Lb.Count(); j++)
            if (La[i].data == Lb[j].data) {
                Lc.push_back(La[i].data);
            }
    }
    Lc.print();
    return 0;
}
