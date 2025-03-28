#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
    T* arr;
    int length;
    int capacity;

public:
    DynamicArray(int size = 0) {
        length = 0;
        capacity = (size == 0) ? 1 : size * 2;
        arr = new T[capacity];
    }

     T& operator[](int index) const{
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    bool isEmpty() { return length == 0; }
    int size() { return length;}
    void add(T val) {
        if (length == capacity) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i < length; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[length++] = val;
    }

    void remove(T val) {
        if (length == 0) {
            cout << "The Array is empty\n";
            return;
        }
        int newLength = 0;
        for (int i = 0; i < length; i++) {
            if (arr[i] != val) {
                arr[newLength++] = arr[i];
            }
        }

        if (newLength == length) {
            cout << "The Array does not contain this value\n";
            return;
        }

        length = newLength;

        if (length < capacity / 4) {
            capacity /= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i < length; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
    }

    friend ostream& operator<<(ostream& out, const DynamicArray& d) {
        for (int i = 0; i < d.length; i++) {
            out << d[i] << " ";
        }
        return out;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray<int> d;
    d.add(4);
    d.add(6);
    d.add(4);
    d.add(2);
    cout << "Array: " << d << endl;
    d.remove(4);
    cout << "After Removing 4: " << d << endl;
    cout << d[1];
    return 0;
}
