#include "head2.h"

using namespace std;
int main(){
    int a = Power(3,4), *arr = new int[ELEMS], *sorted = nullptr;
    cout << a << endl;

    for(int i = 0; i < ELEMS; i++){
        arr[i] = rand()%30;
        cout << arr[i] << " ";
    }

    cout << endl;

    sorted = Bubblesort(arr, ELEMS);
    for(int i = 0; i < ELEMS; i++)
        cout << sorted[i] << " ";

    delete[] arr;
    return EXIT_SUCCESS;
}