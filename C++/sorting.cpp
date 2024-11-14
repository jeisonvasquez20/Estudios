#include <iostream>
#include <ctime>
#include <algorithm>


using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selection_sort (int arr[], int n, int x) {     // Basicamente aqui quise hacer la funcion que ordene de menor a mayor y de mayor a menor. El cambio es nada mas cambiar el signo en la linea 18
    int small = 0;                                  // y ya. hice un if para hacer las dos versiones, i si x es verdad, menor a mayor, si es falso, mayor a menor.
    if (x) {                                        // no se si hay una forma en c++ de hacer un if que solo cambie el signo para ahorrarse codigo.
        for (int i = 0; i < n; i++) {               // en las demas funciones es igual.
            for (int j = i; j < n; j++) {
                if (arr[j] < arr[small])
                    small = j;
                }
            swap (arr[i], arr[small]);
            small = i+1;
        }
        
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (arr[j] > arr[small])
                    small = j;
                }
            swap (arr[i], arr[small]);
            small = i+1;
        }

    }
}


void bubble_sort (int arr[], int n, int x) {
    if (x) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                    if (arr[j] < arr[j - 1])
                        swap (arr[j], arr[j - 1]);
            }

        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                    if (arr[j] > arr[j - 1])
                        swap (arr[j], arr[j - 1]);
            }
        }
    }
}

void insertion_sort (int arr[], int n, int x) {
    
    int temp, j = 0;
    if (x) {
    for (int i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    } else {
      for (int i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && arr[j] < temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }  
    }
}

void merge (int arr[], int p, int q, int r, int x) {
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl];
    int R[nr];
    for (int i = 0; i < nl; i++)
        L[i] = arr[p + i];
    for (int i = 0; i < nr; i++)
        R[i] = arr[q + i + 1];
    
    int i = 0, j = 0;
    int k = p;
    if (x) {
    while (i < nl && j < nr) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    } else {
    while (i < nl && j < nr) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    }
    while (i < nl){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort (int arr[], int p, int r, int x) {
    if (p >= r)
        return;
    int q = (p + r) / 2;
    merge_sort (arr, p, q, x);
    merge_sort (arr, q+1, r, x);
    merge (arr, p, q, r, x);
}

int main () {
    srand(time(NULL));
    int x = rand () % 2;    
    int arr[20];
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        arr[i] = rand () % 100 + 1;
    print_array (arr, n);
    insertion_sort (arr, n, x);
    print_array (arr, n);
    return 0;

}