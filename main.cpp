#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

const int THRESHOLD_EXCELLENT = 35;
const int THRESHOLD_GOOD = 20;
const int THRESHOLD_POOR = -30;

string getQuality(int snr) {
    if (snr >= THRESHOLD_EXCELLENT) {
        return "Отличный";
    } else if (snr >= THRESHOLD_GOOD) {
        return "Хороший";
    } else if (snr >= THRESHOLD_POOR) {
        return "Слабый";
    } else {
        return "Плохой";
    }
}

int main() {

    vector<int> snr = { -42, -38, -25, -17, -33, -45,
                        -29, -12, -36, -41, -22, 30 };

    int n = snr.size();


    int minVal = snr[0];
    int minIdx = 0;
    int maxVal = snr[0];
    int maxIdx = 0;


    int sum = 0;


    int countExcellent = 0;
    int countGood = 0;


    for (int i = 0; i < n; i++) {
        
        sum = sum + snr[i];

        if (snr[i] < minVal) {
            minVal = snr[i];
            minIdx = i;
        }

        if (snr[i] > maxVal) {
            maxVal = snr[i];
            maxIdx = i;
        }

        if (snr[i] >= THRESHOLD_EXCELLENT) {
            countExcellent++;
        }

        if (snr[i] >= THRESHOLD_GOOD) {
            countGood++;
        }
    }

    double avg = (double)sum / n;

    int spread = maxVal - minVal;

    cout << "======== Отчёт по соте Wi-Fi (N=" << n << ") ========\n\n";

    cout << "Минимальный SNR : " << minVal << " дБ (клиент "
         << setw(2) << setfill('0') << minIdx << setfill(' ')
         << ") — " << getQuality(minVal) << "\n";

    cout << "Максимальный SNR: " << maxVal << " дБ (клиент "
         << setw(2) << setfill('0') << maxIdx << setfill(' ')
         << ") — " << getQuality(maxVal) << "\n";

    cout << "Средний SNR : " << fixed << setprecision(2) << avg << " дБ\n\n";

    cout << "Клиентов с SNR >= " << THRESHOLD_EXCELLENT
         << " дБ : " << countExcellent << "\n";
    cout << "Клиентов с SNR >= " << THRESHOLD_GOOD
         << " дБ : " << countGood << "\n\n";

    cout << "Разброс (max-min) : " << spread << " дБ\n";

    if (countGood == n && countExcellent >= n / 2) {
        cout << "Оценка соты: отличная\n";
    } else if (countGood >= n / 2) {
        cout << "Оценка соты: рабочая, но есть проблемные клиенты\n";
    } else {
        cout << "Оценка соты: требует внимания (много слабых клиентов)\n";
    }

    return 0;
}