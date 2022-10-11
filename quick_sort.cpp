#include <iostream>

int parts(int *a, int st, int en){
    int targ = a[(st+en) / 2];
    int j = en;
    int i = st;
    while (i <= j){
        while (a[i] < targ){
            i++;
        }
        while (a[j] > targ) {
            j--;
        }
        if (i >= j){
            break;
        }
        std::swap(a[j], a[i]);
        j--;
        i++;
    }
    return j;
}

void quick_sort(int *a, int st, int en){
    if (st < en){
        int q = parts(a, st, en);
        quick_sort(a, st, q);
        quick_sort(a, q  + 1, en);
    }
}


int main() {
    int n;
    std::cin >> n;
    int s[n];
    for (int i = 0; i < n; i++){
        std::cin >> s[i];
    }
    quick_sort(s, 0, n - 1);
    for (int i = 0; i < n; i++){
        std::cout << s[i] << ' ';
    }
    return 0;
}