    #include <iostream>
    #include <iomanip>
    #include <time.h>
    using namespace std;

    void Create(int* a, const int size, const int Low, const int High)
    {
        for (int i = 0; i < size; i++)
            a[i] = Low + rand() % (High - Low + 1);
    }

    void Print(int* a, const int size)
    {
        for (int i = 0; i < size; i++)
            cout << setw(4)  << a[i];
        cout << endl;
    }

    int Sum(int* a, const int size, const int n) {
        int suma = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] >= 0) {
                suma += a[i];
            }
        }
        return suma;
    }

    int Max(int* a, const int size)
    {
        int max = a[0];
        for (int i = 1; i < size; i++)
            if (a[i] > max)
                max = abs(a[i]);
        return max;
    }



    

    int Min(int* a, const int size)
    {
        int min = abs(a[0]); 

        for (int i = 1; i < size; i++) {
            if (abs(a[i]) < min) {
                min = abs(a[i]);
                if (min < 0)
                {
                    min *= -1;
                }
            }
        }
        return min;
    }


    int Pro(int* a, const int size, const int* max, const int* min)
    {

        int prod = 1;
        for (int i = 0; i < size; i++) {
            if (a[i] < *max && a[i] > *min) {
                prod *= a[i];
            }
        }
        return prod;
    }
   
    void Sort(int* a, const int size)
    {
        for (int i = 0; i < size - 1; i++) 
        {
            if (a[i] % 2 != 0) 
            {
                int max = a[i]; 
                int imax = i; 
                for (int j = i + 1; j < size; j++)
                {
                    if (a[j] % 2 != 0 && max < a[j]) 
                    {
                        max = a[j];
                        imax = j;
                    }
                }

                if (imax != i)
                {
                    int temp = a[i];
                    a[i] = a[imax];
                    a[imax] = temp;
                }
            }
        }
    }



    int main()
    {
        srand((unsigned)time(NULL));
        int n;
        cout << "n = ";
        cin >> n;
        int* a = new int[n];
        int Low = -10;
        int High = 10;
        Create(a, n, Low, High);
        cout << "Original" << endl;
        Print(a, n);
        cout << "Sum = " << Sum(a, n, n) << endl;

        int maxVal = Max(a, n);
        int minVal = Min(a, n);
        cout << "Max = " << maxVal << endl;
        cout << "Min = " << minVal << endl;
        cout << "Prod = " << Pro(a, n, &maxVal, &minVal) << endl;
        cout << "" << endl;
        cout << "Sorted" << endl;
        Sort(a, n);
        Print(a, n);
        return 0;
    }
