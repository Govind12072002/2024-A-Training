
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int BinarySearch(int *a, int n, int target) {
    int l = 0, h = n-1;

    while(l <= h) {
        int mid = l + ((h - l) >> 1);

        if(a[mid] == target) return mid;
        else if(a[mid] < target) l = mid + 1;
        else h = mid - 1;
    }

    return -1;
}

int main() {
    int a[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    cout << "ARRAY CONTENT :" << endl;
    for(int *i=a ; i<a+10 ; ++i) cout << *i << " ";
    cout << endl;

    int target = 40;
    int index = BinarySearch(a, 10, target);

    if(index != -1) cout << "Value " << target << " is found at index " << index << "." << endl;
    else cout << "Value " << target << " is not found in array." << endl;

    target = 45;
    index = BinarySearch(a, 10, target);

    if(index != -1) cout << "Value " << target << " is found at index " << index << "." << endl;
    else cout << "Value " << target << " is not found in array." << endl;

    return 0;
}