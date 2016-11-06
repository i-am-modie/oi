#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i_Zapytan;
    cin >> i_Zapytan;
    int * t_zapytania = new int [i_Zapytan];
    int max_zapytanie=0;
    for (int i = 0; i < i_Zapytan; i++) {
        cin >> t_zapytania[i];
        if(t_zapytania[i]>max_zapytanie)max_zapytanie=t_zapytania[i];
    }
    vector < long int > ciag;
    int n=0;
    int i_roznica=1;
    int pom=3;
    while(i_roznica<max_zapytanie){
        if(n<2)ciag.push_back(n+1);
        else{
            if(n%2==0)ciag.push_back(ciag[n-1]*2);
            else{
                pom=i_roznica+1;
                for( int i=n-1; i>0; i--){
                    for (int j = i-1; j >=0; j--) {
                        if(pom==ciag[i]-ciag[j]){
                            i=n;
                            pom++;
                            break;
                        }
                    }
                }
                i_roznica=pom;
                ciag.push_back(ciag[n-1]+i_roznica);
            }
        }
        cout << n << ": " << ciag[n] << endl;
        n++;
    }
    for (int i = 0; i < i_Zapytan; i++) {
        for( int p=ciag.size(); p>0; p--){
            for (int q = p-1; q >=0; q--) {
                if(t_zapytania[i]==ciag[p]-ciag[q]){
                    cout << p+1 << " " << q+1 << endl;
                }
            }
        }
    }

    return 0;
}