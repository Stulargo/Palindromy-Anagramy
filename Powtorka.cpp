//Zadanie 2
#include <iostream>
#include <fstream>

using namespace std;

bool isWK(string word) {
    int wCount = 0;
    int kCount = 0;
    for (char c : word) {
        if (c == 'w') {
            wCount++;
        } else if (c == 'k') {
            kCount++;
        }
    }
    return wCount == kCount;
}

int countWakacje(string word) {
    int wakacje[6] = {0};
    for (char c : word) {
        switch (c) {
            case 'w':
                wakacje[0]++;
            break;
            case 'a':
                wakacje[1]++;
            break;
            case 'k':
                wakacje[2]++;
            break;
            case 'c':
                wakacje[3]++;
            break;
            case 'j':
                wakacje[4]++;
            break;
            case 'e':
                wakacje[5]++;
            break;
        }
    }
    if (wakacje[1] > 1) {
        if (wakacje[1] % 2 == 1)
            wakacje[1]--;
        wakacje[1] = wakacje[1] / 2;
        // Bubblesort
        for (int j = 0; j < 6 - 1; j++) {
            for (int k = 0; k < 6 - j - 1; k++) {
                if (wakacje[k] > wakacje[k + 1]) {
                    int temp = wakacje[k];
                    wakacje[k] = wakacje[k + 1];
                    wakacje[k + 1] = temp;
                }
            }
        }
        return wakacje[0];
    } else {
        return 0;
    }
}

int main() {
    ifstream plik("slowa.txt");
    ofstream output_a("wyniki2_a.txt");
    ofstream output_b("wyniki2_b.txt");

    string word;
    while (plik >> word) {
        if (isWK(word)) {
            output_a << word << endl;
        }
        output_b << countWakacje(word) << endl;
    }

    plik.close();
    output_a.close();
    output_b.close();
    return 0;
}




//Zadanie 1


#include <iostream>
#include <fstream>

using namespace std;

int liczE(string zdanie) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak == 'e') {
            licznik++;
        }
    }
    return licznik;
}

int liczSpacje(string zdanie) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak == ' ') {
            licznik++;
        }
    }
    return licznik;
}

string zamienI(string zdanie) {
    for (char& znak : zdanie) {
        if (znak == 'i') {
            znak = '&';
        }
    }
    return zdanie;
}

string ostatniWyraz(string zdanie) {
    string ostatni = "";
    for (int i = zdanie.length() - 1; i >= 0; i--) {
        if (zdanie[i] == ' ') {
            break;
        }
        else {
            ostatni = zdanie[i] + ostatni;
        }
    }
    return ostatni;
}

bool czyPalindrom(string slowo) {
    int dlugosc = slowo.length();
    for (int i = 0; i < dlugosc / 2; i++) {
        if (slowo[i] != slowo[dlugosc - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream plikWe("dane.txt");
    ofstream plikWy("zmienione_zdania.txt");

    string zdanie;
    while (getline(plikWe, zdanie)) {
        int liczbaE = liczE(zdanie);
        cout << "Liczba liter 'e' w zdaniu: " << liczbaE << endl;

        int liczbaSpacji = liczSpacje(zdanie);
        cout << "Liczba spacji w zdaniu: " << liczbaSpacji << endl;

        string zmodyfikowaneZdanie = zamienI(zdanie);
        plikWy << zmodyfikowaneZdanie << endl;

        string ostatni = ostatniWyraz(zdanie);
        cout << "Ostatni wyraz: " << ostatni << ", Palindrom: " << czyPalindrom(ostatni) << endl;
    }

    plikWe.close();
    plikWy.close();

    return 0;
}


//Zad 1 
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("slow.txt");

    int count = 0;
    char word1[20], word2[20];

    while (file >> word1 >> word2) {
        int len = 0;
        while (word2[len] != '\0') {
            len++;
        }
        char last_char = word2[len - 1];
        if (last_char == 'A') {
            count++;
        }
    }

    cout << "Liczba słów kończących się na literę 'A': " << count << endl;

    file.close();

    return 0;
}




#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream plik("slow.txt");

    int liczba_slow_z_koncowka_a = 0;
    char slowo1[20], slowo2[20];

    while (plik >> slowo1 >> slowo2) {
        int dlugosc = 0;
        while (slowo2[dlugosc] != '\0') { 
            dlugosc++;
        }
        char ostatni_znak = slowo2[dlugosc - 1]; 
        if (ostatni_znak == 'A') {
            liczba_slow_z_koncowka_a++;
        }
    }

    cout << "Liczba słów kończących się na literę 'A': " << liczba_slow_z_koncowka_a << endl;

    plik.close();

    return 0;
}



//

#include <iostream>
#include <fstream>

using namespace std;

bool zawiera(char slowo1[], char slowo2[]) {
    int i = 0, j = 0;
    while (slowo2[j] != '\0') {
        if (slowo1[i] == slowo2[j]) {
            i++;
            j++;
            if (slowo1[i] == '\0')
                return true;
        } else {
            j++;
            i = 0;
        }
    }
    return false;
}

int main() {
    ifstream plik("slow.txt");

    int liczba_wierszy = 0;
    char slowo1[20], slowo2[20];

    while (plik >> slowo1 >> slowo2) {
        if (zawiera(slowo1, slowo2)) {
            liczba_wierszy++;
        }
    }

    cout << "Liczba wierszy zawierających pary słów, gdzie pierwsze słowo zawiera się w drugim: " << liczba_wierszy << endl;

    plik.close();

    return 0;
}



