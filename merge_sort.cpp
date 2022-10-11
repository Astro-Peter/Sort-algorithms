#include <iostream>

void merge(int *a, int start, int middle, int end){
    int it1 = 0;
    int it2 = 0;
    int result[end - start];
    while (start + it1 < middle && middle + it2 < end){
        if (a[start + it1] < a[middle + it2]){
            result[it1 + it2] = a[start + it1];
            it1++;
        } else{
            result[it1 + it2] = a[middle + it2];
            it2++;
        }
    } while (start + it1 < middle){
        result[it1+it2] = a[start + it1];
        it1++;
    } while (middle + it2 < end){
        result[it1 + it2] = a[middle + it2];
        it2++;
    } for (int i = 0; i < it1 + it2; i++){
        a[start + i] = result[i];
    }
}

void merge_sort(int *a, int start, int end){
    if (start + 1 >= end){
        return;
    }
    int mid = (start+end) / 2;
    merge_sort(a, start, mid);
    merge_sort(a, mid, end);
    merge(a, start, mid, end);
}



int main() {
    int n;
    std::cin >> n;
    int s[n];
    for (int i = 0; i < n; i++){
        std::cin >> s[i];
    }
    merge_sort(s, 0, n);
    for (int i = 0; i < n; i++){
        std::cout << s[i] << ' ';
    }
    return 0;
}