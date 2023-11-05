#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void inputInt(int *var, char *instructions);
void menuFibonacci(int *number);
unsigned long long fibonacciIterative(int number);
unsigned long long fibonacciRecursive( int number);
void fibonacciResult(unsigned long long (*result)(int), int number);

void inputInt(int *var, char *instructions) {
    char buff[1024];
    char cek;

    while (1) {
        printf("%s", instructions);
        fflush(stdin);
        if (fgets(buff, sizeof(buff), stdin) != NULL) {
            if (sscanf(buff, "%d %c", var, &cek) == 1 && *var >= 0) {
                break;
            }
        }
        printf("\n\t\e[31m[]======================================[]\e[0m");
        printf("\n\t\e[31m[] Input anda salah !                   []\e[0m");
        printf("\n\t\e[31m[] Silahkan masukkan bilangan positif ! []\e[0m"); 
        printf("\n\t\e[31m[]======================================[]\e[0m");
    }
}

void intro()
{
    system("cls");
    printf("\n\t[]==========================================[]");
    printf("\n\t||               PROGRAM FIBONACCI          ||");
    printf("\n\t||                  KELOMPOK 3              ||");
    printf("\n\t[]==========================================[]");
    printf("\n\t||ANGGOTA:                                  ||");
    printf("\n\t|[1] Putu Gede Pradnya Wiswambra            ||");
    printf("\n\t|[NIM] (2305551033)                         ||");
    printf("\n\t|[2] Made Indira Prawita Utari              ||");
    printf("\n\t|[NIM] (2305551038)                         ||");
    printf("\n\t|[3] Putu Arya Ekananda Kusuma Negara       ||");
    printf("\n\t|[NIM] (2305551057)                         ||");
    printf("\n\t|[4] Pyari Visvapujita Devi Dasi            ||");
    printf("\n\t|[NIM] (2305551069)                         ||");
    printf("\n\t|[5] Ida Ayu Maytha Devi Kencana            ||");
    printf("\n\t|[NIM] (2305551087)                         ||");
    printf("\n\t|[6] Ni Kadek Anggita Pradnya Dewi          ||");
    printf("\n\t|[NIM] (2305551127                          ||");
    printf("\n\t|[7] Anthony Wisnu Jati                     ||");
    printf("\n\t|[NIM] (2305551138)                         ||");
    printf("\n\t[]==========================================[]");
    printf("\n\tEnter untuk melanjutkan..");
    while (_getch() != 13);
}

int main() {
    intro();
    int number;
    menuFibonacci(&number);
    return 0;
}
void menuFibonacci(int *number) {
    int frontMenu = 1;

    while (frontMenu) {
        system("cls");
        printf("\n\t[+]===========================[+]");
        printf("\n\t||            [MENU]           ||");
        printf("\n\t[=]===========================[=]");
        printf("\n\t|[1] Fibonacci (Iteratif)      ||");
        printf("\n\t|[2] Fibonacci (Rekursif)      ||");
        printf("\n\t|[3] Selesai                   ||");
        printf("\n\t[+]===========================[+]");
        inputInt(number, "\n\t||[Pilihlah menu (1/2/3)]: ");

        switch (*number) {
            case 1:
                while (1) {
                    int n;
                    system("cls");
                    printf("\n\t[]==============================================[]");
                    printf("\n\t||               Fibonacci (Iteratif)           ||");
                    printf("\n\t[]==============================================[]");
                    inputInt(&n, "\n\tMasukkan jumlah angka dalam deret fibonacci: ");
                    fibonacciResult(fibonacciIterative, n);
                    
                    int back;
                    printf("\n\t[]===========================[]");
                    printf("\n\t||            MENU           ||");
                    printf("\n\t[]===========================[]");
                    printf("\n\t|[1] Ulangi memasukkan angka ||");
                    printf("\n\t|[2] Kembali ke menu         ||");
                    printf("\n\t|[3] Selesai                 ||");
                    printf("\n\t[]===========================[]");
                    inputInt(&back, "\n\tPilihlah menu (1/2/3): ");
                    
                    if (back == 1) {
                        continue;
                    } else if (back == 2) {
                        break;
                    } else if (back == 3) {
                        frontMenu = 0;
                        system("cls");
                        printf("\n\t[]========================================[]");
                        printf("\n\t| Terimakasih sudah mencoba program kami ! |");
                        printf("\n\t[]========================================[]");
                        break;
                    }
                }
                break;

            case 2:
                while (1) {
                    int n;
                    system("cls");
                    printf("\n\t[]==============================================[]");
                    printf("\n\t||               Fibonacci (Rekursif)           ||");
                    printf("\n\t[]==============================================[]");
                    inputInt(&n, "\n\tMasukkan jumlah angka dalam deret fibonacci: ");
                    fibonacciResult(fibonacciRecursive, n);

                    int back;
                    printf("\n\t[]===========================[]");
                    printf("\n\t||            MENU           ||");
                    printf("\n\t[]===========================[]");
                    printf("\n\t|[1] Ulangi memasukkan angka ||");
                    printf("\n\t|[2] Kembali ke menu         ||");
                    printf("\n\t|[3] Selesa                  ||");
                    printf("\n\t[]===========================[]");
                    inputInt(&back, "\n\tPilihlah menu (1/2/3): ");
                    
                    if (back == 1) {
                        continue;
                    } else if (back == 2) {
                        break;
                    } else if (back == 3) {
                        frontMenu = 0;
                        system("cls");
                        printf("\n\t[]========================================[]");
                        printf("\n\t| Terimakasih sudah mencoba program kami ! |");
                        printf("\n\t[]========================================[]");
                        break;
                    }
                }
                break;

            case 3:
                frontMenu = 0;
                system("cls");
                    printf("\n\t[]========================================[]");
                    printf("\n\t| Terimakasih sudah mencoba program kami ! |");
                    printf("\n\t[]========================================[]");
                break;

            default:
                printf("\n\t[]========================================[]");
                printf("\n\t||   Oopsies. Pilihan kamu salah. Hehehe  ||");
                printf("\n\t[]========================================[]");
                break;
        }
    }
}




unsigned long long fibonacciIterative(int number) {
    if (number <= 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        long long firstNumber = 0, secondNumber = 1, result = 0;
        for (int i = 2; i <= number; i++) {
            result = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = result;
        }
        return result;
    }
}

unsigned long long fibonacciRecursive(int number) {
    if (number <= 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    }
}

void fibonacciResult(unsigned long long (*result)(int), int number) 
{
    system("cls");
    printf(  "\t[]===========================================================[]");
    printf("\n\t[]                     Deret Fibonacci                       []");
    printf("\n\t[]===========================================================[]\n");
    for (int i = 0; i < number; i++) {
        printf("\t %llu,", result(i));
        if (i %5 == 0)
        {
            printf("\n");
        }
        
        
    }
    printf("\n\t");
}



