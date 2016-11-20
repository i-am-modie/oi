#include <iostream>
#include <vector>

using namespace std;

struct zapytanie{
    int liczba;
    int x,y;
    bool test=0;
};

int main() {
    ios_base::sync_with_stdio(0);
    int i_Zapytan;
    cin >> i_Zapytan;
    vector < zapytanie> zaptania;
    for (int i = 0; i < i_Zapytan; i++) {
        zaptania.push_back(zapytanie());
        cin >> zaptania[i].liczba;
    }
    vector < unsigned long long > ciag;
    unsigned int n=0;
    unsigned int i_roznica=1;
    unsigned int pom=3;
    bool test=1;
    while(test){
        if(n<2)ciag.push_back(n+1);
        else{
            if(n%2==0)ciag.push_back(ciag[n-1]*2);
            else{
                pom=i_roznica+1;
                for( long i=n-1; i>0; i--){
                    for (long j = i-1; j >=0; j--) {
                        for (int k = 0; k < i_Zapytan; k++) {
                            if (ciag[i] - ciag[j] == zaptania[k].liczba) {
                                zaptania[k].x = i+1;
                                zaptania[k].y = j+1;
                                zaptania[k].test = 1;
                            }
                        }

                        if(pom==ciag[i]-ciag[j]){
                            i=n;
                            pom++;
                        }
                    }
                }
                i_roznica=pom;
                ciag.push_back(ciag[n-1]+i_roznica);
                for (int i = 0; i < zaptania.size(); i++) {
                    if(zaptania[i].test)test=0;
                    else{
                        test=1;
                        break;
                    }
                }
            }
        }
        n++;
        if(!test)break;
        }
        for (int i = 0; i < i_Zapytan; i++) {
            cout << zaptania[i].x <<" " << zaptania[i].y << endl;
        }
        return 0;
}