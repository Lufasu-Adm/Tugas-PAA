#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max_size 100

int bf_penukaran_uang(){

}

int greedy_penukaran_uang(){
}

void penukaran_uang(){
    int method, coin, nilai_tukar, hasilBF, hasilGreedy;
    int nilai_coin[max_size];
    printf("Pilih metode: \n");
    printf("1. Brute Force\n");
    printf("2. Greedy\n");
    printf("Silahkan pilih metode: ");
    scanf("%d", &method);
    system("cls");
    printf("Masukkan jumlah koin: ");
    scanf("%d", &coin);
    printf("Masukkan nilai koin: ");
    for (int i = 1; i <= coin; i++){
        scanf("%d", &nilai_coin[i]);
    }
    printf("Masukkan jumlah penukaran: ");
    scanf("%d", &nilai_tukar);
}

void bf_penjadwalan(int n, int *waktu, int *profit){
    int i, j, maxprofit = 0, temp, sum, bit[max_size] = {0}, bestset[max_size] = {0};
    
    for (i = 0; i < (1 << n); i++) {
        sum = 0;
        temp = i;
        for (j = 0; j < n; j++) {
            if (temp % 2 == 1)
                sum += waktu[j];
            temp /= 2;
        }
        if (sum <= max_size && sum > maxprofit) {
            maxprofit = sum;
            for (j = 0; j < n; j++)
                if (i & (1 << j))
                    bestset[j] = 1;
                else
                    bestset[j] = 0;
        }
    }
    
    printf("Jadwal dengan Brute Force: ");
    for (i = 0; i < n; i++) {
        if (bestset[i] == 1)
            printf("%d ", i + 1);
    }
    printf("\n");
}

void greedy_penjadwalan(int n, int *waktu, int *profit) {
    int i, j, sum = 0, maxprofit = 0, bestset[max_size] = {0}, temp[max_size] = {0};

    for (i = 0; i < n; i++) {
        temp[i] = profit[i] / waktu[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] < temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
                swap = waktu[i];
                waktu[i] = waktu[j];
                waktu[j] = swap;
                swap = profit[i];
                profit[i] = profit[j];
                profit[j] = swap;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sum + waktu[i] <= max_size) {
            sum += waktu[i];
            maxprofit += profit[i];
            bestset[i] = 1;
        }
    }

    printf("Jadwal dengan Greedy: ");
    for (i = 0; i < n; i++) {
        if (bestset[i] == 1)
            printf("%d ", i + 1);
    }
    printf("\n");
}

void penjadwalan(){
    int method;
    printf("Pilih metode: \n");
    printf("1. Brute Force\n");
    printf("2. Greedy\n");
    printf("Silahkan pilih metode: ");
    scanf("%d", &method);

    // Simulasi data waktu dan profit
    int n = 5; // Misalnya terdapat 5 tugas
    int waktu[] = {3, 1, 2, 4, 5}; // Waktu yang dibutuhkan untuk mengerjakan masing-masing tugas
    int profit[] = {10, 5, 7, 12, 15}; // Profit yang didapat dari masing-masing tugas

    if (method == 1)
        bf_penjadwalan(n, waktu, profit);
    else
        greedy_penjadwalan(n, waktu, profit);
}

void knapsack_problem(){
    int method;
    printf("Pilih metode: \n");
    printf("1. Brute Force\n");
    printf("2. Greedy\n");
    printf("Silahkan pilih metode: ");
    scanf("%d", &method);
}

void pilihan(int input){
    switch (input)
    {
    case 1:
        penukaran_uang();
        break;
    case 2:
        penjadwalan();
        break;
    case 3:
        knapsack_problem();
        break;
    default:
        break;
    }
}

void menu(){
    int input_menu;
    char buffer[100];
    do{
        printf("================================\n");
        printf("Pilih menu dibawah ini: \n");
        printf("================================\n");
        printf("1. Penukaran uang\n");
        printf("2. Penjadwalan\n");
        printf("3. Knapsack Problem\n");
        printf("4. Keluar\n");
        printf("\n");
        printf("Silahkan pilih menu: ");
        scanf("%d", &input_menu);
        if (input_menu != 1){
            if (input_menu > 4 || input_menu <= 0){
            system("cls");
            printf("Masukkan menu yang valid (1-4)\n");
            fgets(buffer, sizeof(buffer), stdin);
            system("pause");
            }
        }
        system("cls");
        pilihan(input_menu);
    }while (input_menu != 4);
}

int main(){
    menu();
}

