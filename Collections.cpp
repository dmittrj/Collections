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
    int amount;
    list() {
        head = new list_item<T>(0, nullptr);
        amount = 0;
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
        amount++;
    }

    void insert(int index, T element) {
        if (amount < index) return;
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
        list_item<T>* new_item = new list_item<T>(element, _itt->prev);
        new_item->next = _itt;
        _itt->prev->next = new_item;
        _itt->prev = new_item;
        amount++;
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
        amount--;
    }

    T* toarray() {
        if (head == nullptr) return nullptr;
        T* arr = new T[amount]; 
        list_item<T>* _itt = head->next;
        for (int i = 0; i < amount; i++)
        {
            arr[i] = _itt->_value;
            _itt = _itt->next;
        }
        return arr;
    }

    T operator[](int index) {
        list_item<T>* _itt = head;
        for (int i = 0; i < index + 1; i++)
        {
            if (_itt->next == nullptr) {
                return _itt->_value;
            }
            else {
                _itt = _itt->next;
            }
        }
        return _itt->_value;
    }

    void print() {
        list_item<T>* _itt = head;
        int i = 0;
        while (true)
        {
            if (_itt->next == nullptr) {
                break;
            }
            else {
                cout << "Element [" << i++ << "] > " << _itt->next->_value << endl;
                _itt = _itt->next;
            }
        }
    }

private:
    list_item<T>* head;
};

template <typename T>
class stack_item {
public:
    stack_item* prev;
    T _value;

    template <typename T>
    stack_item(T elem, stack_item* tail) {
        _value = elem;
        prev = tail;
    }
};

template <typename T>
class stack {
public:
    int amount;
    stack() {
        head = nullptr;
        amount = 0;
    }
    ~stack()
    {
        
    }

    template <typename T>
    void push(T element) {
        stack_item<T>* new_item = new stack_item<T>(element, head);
        head = new_item;
        amount++;
    }

    T peak() {
        return head->_value;
    }

    T pop() {
        stack_item<T>* _itt = head;
        head = head->prev;
        T ret = _itt->_value;
        delete _itt;
        amount--;
        return ret;
    }

private:
    stack_item<T>* head;
};

int main()
{
    stack<int>* s = new stack<int>();
    s->push(20);
    s->push(40);
    s->push(60);
    s->push(80);
    cout << s->peak() << endl;
    cout << s->peak() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
}

