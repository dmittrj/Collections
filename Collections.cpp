#include <iostream>

using namespace std;

template <typename T>
class list_item {
public:
    list_item* next;
    list_item* prev;
    T _value;

    template <typename T>
    list_item(T elem, list_item* tail) {
        _value = elem;
        prev = tail;
        next = nullptr;
    }
};

template <typename T>
class list {
public:
    list_item<T>* head;
    list() {
        head = new list_item<T>(0, nullptr);
    }
    ~list()
    {
        list_item<T>* _itt = head;
        list_item<T>* _tail;
        while (true)
        {
            if (_itt->next == nullptr) {
                _tail = _itt;
                break;
            }
            else {
                _itt = _itt->next;
            }
        }
        while (true)
        {
            if (_tail->prev == nullptr) {
                delete _tail;
                break;
            }
            else {
                _tail = _tail->prev;
                delete _tail->next;
            }
        }
    }

    template <typename T>
    void add(T element) {
        list_item<T>* _itt = head;
        while (true)
        {
            if (_itt->next == nullptr) {
                list_item<T>* new_item = new list_item<T>(element, _itt);
                _itt->next = new_item;
                break;
            }
            else {
                _itt = _itt->next;
            }
        }
    }

    void remove(int index) {
        list_item<T>* _itt = head;
        for (int i = 0; i < index + 1; i++)
        {
            if (_itt->next == nullptr) {
                return;
            }
            else {
                _itt = _itt->next;
            }
        }
        _itt->prev->next = _itt->next;
        if (_itt->next != nullptr) {
            _itt->next->prev = _itt->prev;
        }
        delete _itt;
    }

    template <typename T>
    T operator[](int index) {
        list_item<T>* _itt = head;
        for (int i = 0; i < index + 1; i++)
        {
            if (_itt->next == nullptr) {
                return 0;
            }
            else {
                _itt = _itt->next;
            }
        }
        return _itt->_value;
    }

    void print() {
        list_item<T>* _itt = head;
        while (true)
        {
            if (_itt->next == nullptr) {
                break;
            }
            else {
                cout << "Element >> " << _itt->next->_value << endl;
                _itt = _itt->next;
            }
        }
    }
};

int main()
{
    list<int>* l = new list<int>();

    l->add(5);
    l->add(6);
    l->add(7);
    l->add(8);
    l->print();

    l->remove(1);
    l->print();

    //cout << (*l)[2];

    delete l;
}

