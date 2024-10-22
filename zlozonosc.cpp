#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int kadane(int numbers[], int n)
{
    int maks= numbers[0];
    int suma = numbers[0];
    for (int i = 1; i < n; i++) 
    {
        suma = max(numbers[i], suma + numbers[i]);

        maks = max(maks, suma);
    }
    return maks;
}

int algorytm(int numbers[], int n)
{   
    int maks = numbers[0];
    for (int i = 0; i < n; ++i) 
    {
    int suma = 0;
    for (int j = i; j < n; ++j) 
        {
        suma += numbers[j];
        if (suma > maks) 
            {
            maks = suma; 
            }   
        }
    }
    return maks;
}

int main() 
{
    const int n = 100000;
    int numbers[n];

    srand(time(0));  
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 201 - 100;
    }

    clock_t start_time = clock();
    kadane(numbers, n);
    clock_t end_time = std::clock();
    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout << kadane(numbers, n) << endl;
    cout << fixed << setprecision(1000);
    cout << "Za pomoca Alogrytmu Kadane czas wykonania wynosi: " << execution_time << endl;

    start_time = clock();
    algorytm(numbers, n);
    end_time = std::clock();
    execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    cout << algorytm(numbers, n) << endl;
    cout << "Za pomoca zwyklego algorytmu o zlozonosci(N^2) czas wykonania wynosi: " << execution_time << endl;;

    return 0;
}
