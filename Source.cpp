#include <iostream>
#include <string>
using namespace std;

// calculatePrice fonksiyonu
float* calculatePrice(string* displayTech, int screenSize) {
    float* price = new float; // Dinamik olarak fiyat için bir bellek alaný ayýrýyoruz.
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

// TV sýnýfý
class TV {
private:
    string* displayTech;
    int refreshRate;
    string connectivity;
    int screenSize;

public:
    // Yapýcý metot
    TV(string tech, int rate, string conn, int size) {
        displayTech = new string(tech); // Dinamik bellek ayrýlýyor.
        refreshRate = rate;
        connectivity = conn;
        screenSize = size;
    }

    // Yýkýcý metot
    ~TV() {
        delete displayTech; // Dinamik belleði serbest býrakýyoruz.
    }

    // display() metodu
    void display() {
        cout << "Display Technology: " << *displayTech << endl;
        cout << "Refresh Rate: " << refreshRate << " Hz" << endl;
        cout << "Connectivity: " << connectivity << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;

        // calculatePrice fonksiyonunu çaðýrýyoruz.
        float* price = calculatePrice(displayTech, screenSize);
        cout << "Price: $" << *price << endl;
        delete price; // Dinamik belleði serbest býrakýyoruz.
    }
};

int main() {
    // Ana program
    TV myTV("LED", 120, "Wi-Fi, HDMI", 40); // Örnek TV nesnesi oluþturuyoruz.
    myTV.display(); // Bilgileri ekrana yazdýrýyoruz.

    return 0;
}