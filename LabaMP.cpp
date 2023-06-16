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

class Accountant {
public:

    string fname;
    string lname;
    string mname;
    string title;
    string subdiv;
    int salary;

    Accountant();
    Accountant(ifstream& in);
    ~Accountant();

    Accountant& operator= (const Accountant& A);
    friend ostream& operator<< (ostream& out, const Accountant& A);
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

bool operator== (const Accountant& A, const Accountant& B) {
    return ((A.fname == B.fname) &&
        (A.lname == B.lname) &&
        (A.mname == B.mname) &&
        (A.title == B.title) &&
        (A.subdiv == B.subdiv) &&
        (A.salary == B.salary));
}

bool operator!= (const Accountant& A, const Accountant& B) {
    return !(A == B);
}

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

bool operator< (const Accountant& A, const Accountant& B) {
    return (A != B && !(A > B));
}

bool operator >= (const Accountant& A, const Accountant& B) {
    return (A == B || A > B);
}

bool operator <= (const Accountant& A, const Accountant& B) {
    return (A == B || A < B);
}

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
























/*
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
    cout << "Сортировка:\n1. Insert sort\n2. Shaker sort\n3. Merge sort\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        insertSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        insertSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        insertSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        insertSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        insertSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        insertSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        insertSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100insert.txt"),
            out500("500insert.txt"),
            out1000("1000insert.txt"),
            out5000("5000insert.txt"),
            out10000("10000insert.txt"),
            out50000("50000insert.txt"),
            out100000("10000insert.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 2) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        shakerSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        shakerSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        shakerSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        shakerSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        shakerSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        shakerSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        shakerSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100shaker.txt"),
            out500("500shaker.txt"),
            out1000("1000shaker.txt"),
            out5000("5000shaker.txt"),
            out10000("10000shaker.txt"),
            out50000("50000shaker.txt"),
            out100000("10000shaker.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    if (choice == 3) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        mergeSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        mergeSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        mergeSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        mergeSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        mergeSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        mergeSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        mergeSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        ofstream out100("100merge.txt"),
            out500("500merge.txt"),
            out1000("1000merge.txt"),
            out5000("5000merge.txt"),
            out10000("10000merge.txt"),
            out50000("50000merge.txt"),
            out100000("10000merge.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];

        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }
    if (choice == 4) {
        cout << "Выборка данных объемом 100:\t";
        clock_t start100 = clock();
        selectSort(data100, 100);
        cout << (double)(clock() - start100) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 500:\t";
        clock_t start500 = clock();
        selectSort(data500, 500);
        cout << (double)(clock() - start500) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 1000:\t";
        clock_t start1000 = clock();
        selectSort(data1000, 1000);
        cout << (double)(clock() - start1000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 5000:\t";
        clock_t start5000 = clock();
        selectSort(data5000, 5000);
        cout << (double)(clock() - start5000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 10000:\t";
        clock_t start10000 = clock();
        selectSort(data10000, 10000);
        cout << (double)(clock() - start10000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 50000:\t";
        clock_t start50000 = clock();
        selectSort(data50000, 50000);
        cout << (double)(clock() - start50000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";

        cout << "Выборка данных объемом 100000:\t";
        clock_t start100000 = clock();
        selectSort(data100000, 100000);
        cout << (double)(clock() - start100000) * 1000 / CLOCKS_PER_SEC << " милисекунд\n";
        
        ofstream out100("100select.txt"),
            out500("500select.txt"),
            out1000("1000select.txt"),
            out5000("5000select.txt"),
            out10000("10000select.txt"),
            out50000("50000select.txt"),
            out100000("10000select.txt");

        for (size_t i = 0; i < 100; i++)
            out100 << data100[i];

        for (size_t i = 0; i < 500; i++)
            out500 << data500[i];

        for (size_t i = 0; i < 1000; i++)
            out1000 << data1000[i];

        for (size_t i = 0; i < 5000; i++)
            out5000 << data5000[i];

        for (size_t i = 0; i < 10000; i++)
            out10000 << data10000[i];

        for (size_t i = 0; i < 50000; i++)
            out50000 << data50000[i];

        for (size_t i = 0; i < 100000; i++)
            out100000 << data100000[i];
        
        out100.close();
        out500.close();
        out1000.close();
        out5000.close();
        out10000.close();
        out50000.close();
        out100000.close();
    }

    return 0;
}*/