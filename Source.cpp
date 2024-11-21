#include <iostream>
#include <string>
using namespace std;

// calculatePrice fonksiyonu
float* calculatePrice(string* displayTech, int screenSize) {
    float* price = new float; // Dinamik olarak fiyat i�in bir bellek alan� ay�r�yoruz.
    if (*displayTech == "undefined" && screenSize == 0) {
        *price = 0.0f;
    }
    else if (*displayTech == "LED" && screenSize > 32) {
        *price = 12500.0f;
    }
    else {
        *price = 10000.0f;
    }
    return price;
}

// TV s�n�f�
class TV {
private:
    string* displayTech;
    int refreshRate;
    string connectivity;
    int screenSize;

public:
    // Yap�c� metot
    TV(string tech, int rate, string conn, int size) {
        displayTech = new string(tech); // Dinamik bellek ayr�l�yor.
        refreshRate = rate;
        connectivity = conn;
        screenSize = size;
    }

    // Y�k�c� metot
    ~TV() {
        delete displayTech; // Dinamik belle�i serbest b�rak�yoruz.
    }

    // display() metodu
    void display() {
        cout << "Display Technology: " << *displayTech << endl;
        cout << "Refresh Rate: " << refreshRate << " Hz" << endl;
        cout << "Connectivity: " << connectivity << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;

        // calculatePrice fonksiyonunu �a��r�yoruz.
        float* price = calculatePrice(displayTech, screenSize);
        cout << "Price: $" << *price << endl;
        delete price; // Dinamik belle�i serbest b�rak�yoruz.
    }
};

int main() {
    // Ana program
    TV myTV("LED", 120, "Wi-Fi, HDMI", 40); // �rnek TV nesnesi olu�turuyoruz.
    myTV.display(); // Bilgileri ekrana yazd�r�yoruz.

    return 0;
}