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
