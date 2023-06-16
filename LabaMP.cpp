#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>
#include <chrono>
#include <map>

using namespace std;

/**
 *  @brief Класс Бухгалтерии, хранящий информацию о ФИО, должности, подразделении и зарплаты служащего, а также обладающий методами для взаимодействия объектов класса.
 */


class Accountant {
public:

    /**
 *  @brief Конструктор по умолчанию
 *  @details Заполняет поля класса пустыми строками
 *  @param Параметры отсутствуют
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::Accountant() {
        fname = "";
        lname = "";
        mname = "";
        title = "";
        subdiv = "";
        salary = 0;
    }
 *  @endcode
 */

    string fname;
    string lname;
    string mname;
    string title;
    string subdiv;
    int salary;

    Accountant();

    /**
 *  @brief Конструктор из файлового потока
 *  @details Считывает поля класса из передаваемого файлового потока
 *  @param Ссылка на файловый поток ввода
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::Accountant(ifstream& in) {
        in >> fname >> lname >> mname >> title >> subdiv >> salary;
    }
 *  @endcode
 */

    Accountant(ifstream& in);

    /**
 *  @brief Деструктор класса
 *  @param Параметры отсутствуют
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::~Accountant(){
    }
 *  @endcode
 */

    ~Accountant();

    /**
 *  @brief Оператор присваивания
 *  @details Присваивает объекту данного класса значения полей правого операнда этого же класса
 *  @param Константная ссылка на объект такого же класса
 *  @return Ссылка на этот же объект для возможности дальнейших преобразований компилятором
 *
 *  Реализация:
 *
 *  @code
    Accountant& Accountant::operator= (const Accountant& A) {
        fname = A.fname;
        lname = A.lname;
        mname = A.mname;
        title = A.title;
        subdiv = A.subdiv;
        salary = A.salary;

        return *this;
    }
 *  @endcode
 */



    Accountant& operator= (const Accountant& A);

    /**
 *  @brief Оператор вывода
 *  @details Дружественный оператор вывода полей класса в поток
 *  @param Ссылка на поток вывода и константная ссылка на выводимый объект
 *  @return Ссылка на поток вывода для возможности дальнейших преобразований компилятором
 *
 *  Реализация:
 *
 *  @code
    ostream& operator<< (ostream& out, const Accountant& A) {
        out << A.fname << " ";
        out << A.lname << " ";
        out << A.mname << " ";
        out << A.title << " ";
        out << A.subdiv << " ";
        out << A.salary << " ";
        out << endl;

        return out;
    }
 *  @endcode
 */
    friend ostream& operator<< (ostream& out, const Accountant& A);

    /**
  *  @brief Поля класса
  *  @details Фамилия, Имя, Отчество, Должность, Подразделение, Зарплата
  */
};

Accountant::Accountant() {
    fname = "";
    lname = "";
    mname = "";
    title = "";
    subdiv = "";
    salary = 0;
}

Accountant::Accountant(ifstream& in) {
    in >> fname >> lname >> mname >> title >> subdiv >> salary;
}

Accountant::~Accountant() {

}

Accountant& Accountant::operator= (const Accountant& A) {
    fname = A.fname;
    lname = A.lname;
    mname = A.mname;
    title = A.title;
    subdiv = A.subdiv;
    salary = A.salary;

    return *this;
}

ostream& operator<< (ostream& out, const Accountant& A) {
    out << A.fname << " ";
    out << A.lname << " ";
    out << A.mname << " ";
    out << A.title << " ";
    out << A.subdiv << " ";
    out << A.salary << " ";
    out << endl;

    return out;
}

/**
    @brief Оператор равенства для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если поля объектов равны, False иначе.
*/

bool operator== (const Accountant& A, const Accountant& B) {
    return ((A.fname == B.fname) &&
        (A.lname == B.lname) &&
        (A.mname == B.mname) &&
        (A.title == B.title) &&
        (A.subdiv == B.subdiv) &&
        (A.salary == B.salary));
}
/**
    @brief Оператор неравенства для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return False, если поля объектов равны, True иначе.
*/

bool operator!= (const Accountant& A, const Accountant& B) {
    return !(A == B);
}
/**
    @brief Оператор больше для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически больше, чем соответствующее поле второго объекта, False иначе.
*/
bool operator> (const Accountant& A, const Accountant& B) {
    if (A == B)
        return false;

    if (A.subdiv != B.subdiv)
        return (A.subdiv > B.subdiv);

    if (A.fname != B.fname)
        return (A.fname > B.fname);

    if (A.lname != B.lname)
        return (A.lname > B.lname);

    if (A.mname != B.mname)
        return (A.mname > B.mname);

    if (A.salary != B.salary)
        return (A.salary > B.salary);

    return false;
}
/**
    @brief Оператор меньше для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически меньше, чем соответствующее поле второго объекта, False иначе.
*/

bool operator< (const Accountant& A, const Accountant& B) {
    return (A != B && !(A > B));
}

/**
    @brief Оператор больше либо равно для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически больше, чем соответствующее поле второго объекта, или объекты равны, False иначе.
*/
bool operator >= (const Accountant& A, const Accountant& B) {
    return (A == B || A > B);
}
/**
    @brief Оператор меньше либо равно для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически меньше, чем соответствующее поле второго объекта, или объекты равны, False иначе.
*/
bool operator <= (const Accountant& A, const Accountant& B) {
    return (A == B || A < B);
}


/**
    @brief Шаблонная функция сортировки Insert Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void insertSort(T* A, size_t n) {

    T x;
    long int i = 0, j = 0;
    for (int i = 1; i < n; i++) {
        x = A[i];
        for (j = i - 1; j >= 0 && A[j] > x; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }

}
/**
    @brief Шаблонная функция сортировки Select Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void selectSort(T* A, size_t size)
{
    long i, j, k;
    T x;
    for (i = 0; i < size - 1; i++)
    {   							// i - current step
        k = i;
        x = A[i];
        for (j = i + 1; j < size; j++)	// loop for searching minimal element
        {
            if (A[j] < x)
            {
                k = j; x = A[j];	        // k - minimal element index
            }
        }
        A[k] = A[i]; A[i] = x;   	// swap minimal element and a[i]
    }
}

/**
    @brief Шаблонная функция сортировки Shaker Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void shakerSort(T* A, size_t n) {
    long j, k = n - 1;
    long lb = 1, ub = n - 1;
    T x;
    do {
        for (j = ub; j > 0; j--) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
}
/**
    @brief Шаблонная функция сортировки Merge Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void mergeSort(T* A, size_t n) {
    if (n == 1)
        return;

    mergeSort(A, n / 2);
    mergeSort(&A[n / 2], n - n / 2);

    size_t i = 0, j = n / 2, k = 0;

    T* tmp = new Accountant[n];

    while (k < n) {
        if (i == n / 2) {
            tmp[k] = A[j];
            j++;
        }
        else
            if (j == n) {
                tmp[k] = A[i];
                i++;
            }
            else
                if (A[i] < A[j]) {
                    tmp[k] = A[i];
                    i++;
                }
                else
                {
                    tmp[k] = A[j];
                    j++;
                }
        k++;
    }

    for (size_t i = 0; i < n; i++)
        A[i] = tmp[i];
}

template <typename T>
int linearSearch(T* A, size_t n, string keyName) {
    for (size_t i = 0; i < n; i++)
        if (A[i].fname == keyName)
            return i;
    return -1;
}

template <typename T>
int binarySearch(T* A, size_t n, string keyName) {

    size_t left = 0, right = n, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (A[mid].fname == keyName)
            return mid;
        if (A[mid].fname > keyName)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

/**
    @brief Функция main
    @param Считывание выборок разного объема из файлов, их сортировка выбранным методом, замер времени, вывод отсортированных выборок в файл
    @return Возвращаемое значение отсутствует
    Реализация:
    @code
    int main() {
    setlocale(LC_ALL, "Russian");

    Accountant* data100 = new Accountant[100],
        * data500 = new Accountant[500],
        * data1000 = new Accountant[1000],
        * data5000 = new Accountant[5000],
        * data10000 = new Accountant[10000],
        * data50000 = new Accountant[50000],
        * data100000 = new Accountant[100000];

    ifstream in100("100.txt");

    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Accountant(in100);
    in100.close();


    ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Accountant(in500);
    in500.close();

    ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Accountant(in1000);
    in1000.close();

    ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Accountant(in5000);
    in5000.close();

    ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Accountant(in10000);
    in10000.close();

    ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Accountant(in50000);
    in50000.close();

    ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Accountant(in100000);
    in100000.close();

    int choice;
    cout << "Search:\n1. Linear\n2. Binary with unsorted array\n3. Binary with sorted array\n4. Multimap\n";
    cin >> choice;

    if (choice == 1) {
        int tmp;

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        tmp = linearSearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data1000, 1000, "zmg");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data50000, 50000, "amt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 2) {
        int tmp;

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        mergeSort(data100, 100);
        tmp = binarySearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data500, 500);
        tmp = binarySearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data1000, 1000);
        tmp = binarySearch(data1000, 1000, "ssz");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data5000, 5000);
        tmp = binarySearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data10000, 10000);
        tmp = binarySearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data50000, 50000);
        tmp = binarySearch(data50000, 50000, "erq");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data100000, 100000);
        tmp = binarySearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 3) {
        int tmp;

        mergeSort(data100, 100);
        mergeSort(data500, 500);
        mergeSort(data1000, 1000);
        mergeSort(data5000, 5000);
        mergeSort(data10000, 10000);
        mergeSort(data50000, 50000);
        mergeSort(data100000, 100000);

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();

        tmp = binarySearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data1000, 1000, "ssz");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data50000, 50000, "erq");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 4) {
        multimap <string, Accountant> map100 = {},
            map500 = {},
            map1000 = {},
            map5000 = {},
            map10000 = {},
            map50000 = {},
            map100000 = {};


        for (int i = 0; i < 100; i++)
            map100.insert(pair <string, Accountant>(data100[i].fname, data100[i]));

        for (int i = 0; i < 500; i++)
            map500.insert(pair <string, Accountant>(data500[i].fname, data500[i]));

        for (int i = 0; i < 1000; i++)
            map1000.insert(pair <string, Accountant>(data1000[i].fname, data1000[i]));

        for (int i = 0; i < 5000; i++)
            map5000.insert(pair <string, Accountant>(data5000[i].fname, data5000[i]));

        for (int i = 0; i < 10000; i++)
            map10000.insert(pair <string, Accountant>(data10000[i].fname, data10000[i]));

        for (int i = 0; i < 50000; i++)
            map50000.insert(pair <string, Accountant>(data50000[i].fname, data50000[i]));

        for (int i = 0; i < 100000; i++)
            map100000.insert(pair <string, Accountant>(data100000[i].fname, data100000[i]));

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        auto tmp = map100.find("hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = map500.find("nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map1000.find("zmg");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map5000.find("qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map10000.find("ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map50000.find("amt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map100000.find("otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }
}
    @endcode
*/

int main() {
    setlocale(LC_ALL, "Russian");

    Accountant* data100 = new Accountant[100],
        * data500 = new Accountant[500],
        * data1000 = new Accountant[1000],
        * data5000 = new Accountant[5000],
        * data10000 = new Accountant[10000],
        * data50000 = new Accountant[50000],
        * data100000 = new Accountant[100000];

    ifstream in100("100.txt");

    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Accountant(in100);
    in100.close();


    ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Accountant(in500);
    in500.close();

    ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Accountant(in1000);
    in1000.close();

    ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Accountant(in5000);
    in5000.close();

    ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Accountant(in10000);
    in10000.close();

    ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Accountant(in50000);
    in50000.close();

    ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Accountant(in100000);
    in100000.close();

    int choice;
    cout << "Search:\n1. Linear\n2. Binary with unsorted array\n3. Binary with sorted array\n4. Multimap\n";
    cin >> choice;

    if (choice == 1) {
        int tmp;

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        tmp = linearSearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data1000, 1000, "zmg");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data50000, 50000, "amt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = linearSearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 2) {
        int tmp;

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        mergeSort(data100, 100);
        tmp = binarySearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data500, 500);
        tmp = binarySearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data1000, 1000);
        tmp = binarySearch(data1000, 1000, "ssz");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data5000, 5000);
        tmp = binarySearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data10000, 10000);
        tmp = binarySearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data50000, 50000);
        tmp = binarySearch(data50000, 50000, "erq");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        mergeSort(data100000, 100000);
        tmp = binarySearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 3) {
        int tmp;

        mergeSort(data100, 100);
        mergeSort(data500, 500);
        mergeSort(data1000, 1000);
        mergeSort(data5000, 5000);
        mergeSort(data10000, 10000);
        mergeSort(data50000, 50000);
        mergeSort(data100000, 100000);

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();

        tmp = binarySearch(data100, 100, "hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data500, 500, "nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data1000, 1000, "ssz");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data5000, 5000, "qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data10000, 10000, "ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data50000, 50000, "erq");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();

        tmp = binarySearch(data100000, 100000, "otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }

    if (choice == 4) {
        multimap <string, Accountant> map100 = {},
            map500 = {},
            map1000 = {},
            map5000 = {},
            map10000 = {},
            map50000 = {},
            map100000 = {};


        for (int i = 0; i < 100; i++)
            map100.insert(pair <string, Accountant>(data100[i].fname, data100[i]));

        for (int i = 0; i < 500; i++)
            map500.insert(pair <string, Accountant>(data500[i].fname, data500[i]));

        for (int i = 0; i < 1000; i++)
            map1000.insert(pair <string, Accountant>(data1000[i].fname, data1000[i]));

        for (int i = 0; i < 5000; i++)
            map5000.insert(pair <string, Accountant>(data5000[i].fname, data5000[i]));

        for (int i = 0; i < 10000; i++)
            map10000.insert(pair <string, Accountant>(data10000[i].fname, data10000[i]));

        for (int i = 0; i < 50000; i++)
            map50000.insert(pair <string, Accountant>(data50000[i].fname, data50000[i]));

        for (int i = 0; i < 100000; i++)
            map100000.insert(pair <string, Accountant>(data100000[i].fname, data100000[i]));

        cout << "Data sampling with a volume of 100:\t";
        auto start_t = chrono::steady_clock::now();
        auto tmp = map100.find("hva");
        auto end_t = chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 500:\t";
        start_t = chrono::steady_clock::now();
        tmp = map500.find("nac");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 1000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map1000.find("zmg");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 5000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map5000.find("qmt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 10000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map10000.find("ocp");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 50000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map50000.find("amt");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";

        cout << "Data sampling with a volume of 100000:\t";
        start_t = chrono::steady_clock::now();
        tmp = map100000.find("otu");
        end_t = chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        cout << elapsed_ms.count() << " nanoseconds\n";
    }
}


