#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string lastname;
    int passengerId;

public:
    Person(); // Default constructor
    Person(string, string, int); // Parameterized constructor

    string getName() const { return name; }
    string getLastName() const { return lastname; }
    int getPassengerId() const { return passengerId; }

    void display() const {
        cout << "Name: " << name << ", Last Name: " << lastname << ", ID: " << passengerId << endl;
    }
};

// Implementation of Person constructors
Person::Person() : name("Unknown"), lastname("Unknown"), passengerId(-1) {
    cout << "Default Constructor - Person" << endl;
}

Person::Person(string n, string ln, int id) : name(n), lastname(ln), passengerId(id) {}

// Vehicle class
class Vehicle {
protected:
    string color;
    double price;
    int model_year;

public:
    Vehicle(); // Default constructor
    Vehicle(string, int, double); // Parameterized constructor
    ~Vehicle() { cout << "Destructor - Vehicle" << endl; }

    virtual void getInfo() const;
};

// Implementation of Vehicle constructors
Vehicle::Vehicle() : color("White"), price(0.0), model_year(0) {
    cout << "Default Constructor - Vehicle" << endl;
}

Vehicle::Vehicle(string c, int year, double p) : color(c), model_year(year), price(p) {}

void Vehicle::getInfo() const {
    cout << "Color: " << color << ", Year: " << model_year << ", Price: $" << price << endl;
}

// Subway class
class Subway : public Vehicle {
protected:
    string lineName;
    int numberofCars;

public:
    Subway(); // Default constructor
    Subway(string, int, double, string, int); // Parameterized constructor
    ~Subway() { cout << "Destructor - Subway" << endl; }

    void getInfo() const override;
};

// Implementation of Subway constructors
Subway::Subway() : Vehicle(), lineName("Unknown"), numberofCars(0) {
    cout << "Default Constructor - Subway" << endl;
}

Subway::Subway(string c, int year, double p, string line, int cars)
    : Vehicle(c, year, p), lineName(line), numberofCars(cars) {}

void Subway::getInfo() const {
    Vehicle::getInfo();
    cout << "Line Name: " << lineName << ", Number of Cars: " << numberofCars << endl;
}

// PassengerTrain class
class PassengerTrain : public Vehicle {
private:
    int currentPassengerCount;
    Person passengers[10];

public:
    PassengerTrain(); // Default constructor
    PassengerTrain(string, double, int); // Parameterized constructor

    bool isFull() const { return currentPassengerCount >= 10; }
    void boardPassenger(const Person&);
    void disembarkPassenger(int);
    void displayPassengers() const;
};

// Implementation of PassengerTrain constructors
PassengerTrain::PassengerTrain() : Vehicle(), currentPassengerCount(0) {
    cout << "Default Constructor - PassengerTrain" << endl;
}

PassengerTrain::PassengerTrain(string c, double p, int year)
    : Vehicle(c, year, p), currentPassengerCount(0) {}

void PassengerTrain::boardPassenger(const Person& p) {
    if (!isFull()) {
        passengers[currentPassengerCount++] = p;
        cout << "Passenger boarded successfully!" << endl;
    }
    else {
        cout << "Train is full!" << endl;
    }
}

void PassengerTrain::disembarkPassenger(int id) {
    for (int i = 0; i < currentPassengerCount; ++i) {
        if (passengers[i].getPassengerId() == id) {
            for (int j = i; j < currentPassengerCount - 1; ++j) {
                passengers[j] = passengers[j + 1];
            }
            --currentPassengerCount;
            cout << "Passenger with ID " << id << " disembarked." << endl;
            return;
        }
    }
    cout << "Passenger with ID " << id << " not found." << endl;
}

void PassengerTrain::displayPassengers() const {
    cout << "Current Passengers:" << endl;
    for (int i = 0; i < currentPassengerCount; ++i) {
        passengers[i].display();
    }
}

// Main Function
int main() {
    PassengerTrain train;
    Person p1("John", "Doe", 1), p2("Jane", "Smith", 2);
    int option, passengerId;

    do {
        cout << "1) Board the train\n2) Exit the train\n3) Display Passengers\n4) Display Train Info\n5) Exit the app\nOption: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter your passenger ID: ";
            cin >> passengerId;
            train.boardPassenger(Person("Passenger", "X", passengerId));
            break;
        case 2:
            cout << "Enter your passenger ID to exit the train: ";
            cin >> passengerId;
            train.disembarkPassenger(passengerId);
            break;
        case 3:
            train.displayPassengers();
            break;
        case 4:
            train.getInfo();
            break;
        case 5:
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
        }
    } while (option != 5);

    return 0;
}