#include<iostream>
#include <cmath>

using namespace std;

int z10nadowolny(int tab[], int pods, int wartosc)
{
    int i=0;
    while(wartosc!=0) {
        tab[i] = wartosc % pods;
        wartosc /= pods;
        i++;
    }
    return i;
}

struct zestaw{
    int ile, wartosc;
};

int main()
{
    int podstawa, i_zapytan;
    cin >> podstawa >> i_zapytan;
    zestaw * karteczki = new zestaw[i_zapytan];
    int suma=0;
    for (int i = 0; i < i_zapytan; i++) {
        cin >> karteczki[i].ile;
        suma += karteczki[i].ile;
    }
    for (int i = 0; i < i_zapytan; i++) {
        cin >> karteczki[i].wartosc;
    }
    int * tablica = new int[suma];
    int rozmiar;
    for (int i = pow(podstawa, suma); i > 0 ; i--) {
        bool znaleziono=0;
        if(i%(podstawa-1)==0){
            rozmiar = z10nadowolny(tablica, podstawa, i);
            int * kopia = new int[i_zapytan];
            for (int j = 0; j < i_zapytan; j++) {
                kopia[j]=karteczki[j].ile;
            }
            for (int j = 0; j < rozmiar; j++){
                for (int k = 0; k < i_zapytan; k++) {
                    if(tablica[j]==karteczki[k].wartosc){
                        kopia[k]--;
                    }
                }
            }
            znaleziono=1;
            for (int j = 0;  j < i_zapytan; j++) {
                if(kopia[j]<0){
                    znaleziono=0;
                    break;
                }
            }
            delete [] kopia;
        }
        if(znaleziono)break;
    }
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << endl;
    }
    cout << "-1";
}