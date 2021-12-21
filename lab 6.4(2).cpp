#include <iostream>
#include <iomanip>

using namespace std;

void Create(int*& a, const int size, int Min, int Max, int i);
void findMaxAbs(int* list, const int size, int& indexMax, int i);
void Sum(int* list, const int size, int& sumEl, bool summing, int i);
void Sort(int* list, const int size, int*& inLimit, int left, int*& outLimit, int right, int i, int j, int k);
void Merge(int* list, const int size, int* listA, const int sizeListA, int* listB, const int sizeListB);
void Print(int* list, const int size, int i);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    cout << "Рекурсивний спосiб" << endl;
    cout << endl;

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    int n, leftLimit, rightLimit;
    cout << "N: "; cin >> n;
    cout << "Left limit: "; cin >> leftLimit;
    cout << "Right limit: "; cin >> rightLimit;

    int* a;

    int Min = -10;
    int Max = 10;
    int MaxItemI = 0;
    int sumEl = 0;

    Create(a, n, Min, Max, 0);
    cout << "Before:"; Print(a, n, 0);

    findMaxAbs(a, n, MaxItemI, 0);
    Sum(a, n, sumEl, false, 0);

    int* inLimit = new int[n];
    int* outLimit = new int[n];
    Sort(a, n, inLimit, leftLimit, outLimit, rightLimit, 0, 0, 0);

    cout << "After: "; Print(a, n, 0); cout << endl;
    cout << "Max element (№): " << MaxItemI + 1 << endl;
    cout << "Sum elements (№): " << sumEl << endl;

    delete[] a;
    delete[] inLimit;
    delete[] outLimit;
}



void Create(int*& a, const int size, int Min, int Max, int i)
{
    if (i == 0)
        a = new int[size]; // виділили пам'ять
    if (i < size)
    {
        a[i] = (Max - Min) * rand() / RAND_MAX + Min;
        return Create(a, size, Min, Max, ++i);
    }
}

void findMaxAbs(int* list, const int size, int& indexMax, int i)
{
    if (i < size) {
        if (abs(list[i]) > abs(list[indexMax]))
            indexMax = i;
        return findMaxAbs(list, size, indexMax, ++i);
    }
}

void Sum(int* list, const int size, int& sumEl, bool summing, int i)
{
    if (i < size)
    {
        if (list[i] > 0 && !summing) {
            summing = true;
        }
        if (summing)
            sumEl += list[i];

        Sum(list, size, sumEl, summing, ++i);
    }
}

void Merge(int* list, const int size, int* listA, const int sizeListA, int* listB, const int sizeListB) {
    int indexA = 0, indexB = 0;
    for (int i = 0; i < size; i++) {
        if (indexA < sizeListA) {
            list[i] = listA[indexA];
            indexA++;
            continue;
        }
        list[i] = listB[indexB];
        indexB++;
    }
}

void Sort(int* list, const int size, int*& inLimit, int left, int*& outLimit, int right, int i, int j, int k)
{
    if (i < size) {
        if (list[i] >= left && list[i] <= right) {
            inLimit[j] = list[i];
            Sort(list, size, inLimit, left, outLimit, right, ++i, ++j, k);
        }
        else {
            outLimit[k] = list[i];
            Sort(list, size, inLimit, left, outLimit, right, ++i, j, ++k);
        }
    }
    else
        Merge(list, size, inLimit, j, outLimit, k);
}

void Print(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}