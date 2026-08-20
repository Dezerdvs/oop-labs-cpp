#include <iostream>
#include <cstring>

using namespace std;

template<typename T1>
struct compare_struct { // Структура порівняння
    static bool compare(const T1 &a, const T1 &b) {
        return a > b;
    }
};

template<>
struct compare_struct<const char *> { // Структура порівняння(тільки для char*)
    static bool compare(const char *const &a, const char *const &b) {
        return strcmp(a, b) > 0;
    }
};

template<typename T1>
class sorter {
private:
    T1 *array;
    int size;

    void heapify(int n, int i) { // споміжна функція для пірамідального сорутування
        int maxID = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && compare_struct<T1>::compare(array[left], array[maxID]))
            maxID = left;

        if (right < n && compare_struct<T1>::compare(array[right], array[maxID]))
            maxID = right;

        if (maxID != i) {
            swap(array[i], array[maxID]);
            heapify(n, maxID);
        }
    }

public:
    sorter(T1 *array, int size) : size(size), array(new T1[size]) { // конструктор ініціалізації
        for (int i = 0; i < size; i++)
            this->array[i] = array[i];
    }

    ~sorter() {
        delete[] array;
        array = nullptr;
    }

    void heapSort() { // саме сортування (пірамідальне )
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);

        for (int i = size - 1; i > 0; i--) {
            swap(array[0], array[i]);
            heapify(i, 0);
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

struct testing_type { // Спосіб організаціїї і зберігання данних
    int value;

    testing_type(int value = 0) : value(value) {} // Конструктор ініціалізації

    bool operator>(const testing_type& other) const {
        return value < other.value;
    }

    testing_type& operator=(const testing_type& other) {
        value = other.value;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const testing_type& output) {
        os << output.value;
        return os;
    }
};

int main() {
    system("chcp 65001");

    cout << "Номер варіанту: 15" << endl;
    cout << "Виконавець: Скрипніков Віктор Сергійович " << endl;
    cout << "Рівень складності: Рівень Б (максимальна оцінка «0,8»)" << endl;

    int array_int[] = {5, 10, 9, 101};
    sorter<int> objINT(array_int, 4);
    objINT.heapSort();
    objINT.print();

    const char *array_char[] = {"5", "10", "9", "101"};
    sorter<const char *> objCHAR(array_char, 4);
    objCHAR.heapSort();
    objCHAR.print();

    testing_type array_testType[] = {testing_type(5), testing_type(10), testing_type(9), testing_type(101) };
    sorter<testing_type> objTYPE(array_testType, 4);
    objTYPE.heapSort();
    objTYPE.print();
    return 0;
}
