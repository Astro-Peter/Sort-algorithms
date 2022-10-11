#include <iostream>

void parts(int *a, int st, int en, int k){
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
        if (i <= j) {
            std::swap(a[j], a[i]);
            j--;
            i++;
        }
    }
    if ((st <= k) && (k <= j)){
        parts(a, st, j, k);
    } if ((i <= k) && (k <= en)){
        parts(a, i, en, k);
    }
}


int main(){
    int n, k;
    std::cin >> n >> k;
    int A, B, C, a1;
    std::cin >> A >> B >> C;
    auto a = new int[n];
    for (int i = 0; i < n and i < 2; i++){
        std::cin >> a1;
        a[i] = a1;
    }
    for (int i = 2; i < n; i++){
        a[i] = A * a[i - 2] + a[i - 1] * B + C;
    }
    parts(a, 0, n - 1, k - 1);
    std::cout << a[k - 1];
    return 0;
}