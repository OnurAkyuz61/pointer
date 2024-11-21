#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string lastname;
    int passengerId;

public:
    Person();
    Person(string, string, int);
    ~Person();

    string getName() const {
        return name;
    }

    string getLastName() const {
        return lastname;
    }

    int getPassengerId() const {
        return passengerId;
    }

    void display() const {
        cout << "Name: " << name << ", Last Name: " << lastname << ", ID: " << passengerId << endl;
    }
};


Person::Person() : name("Unknown"), lastname("Unknown"), passengerId(-1) {
    cout << "Default constructor: Person." << endl;
}

Person::Person(string n, string ln, int id) : name(n), lastname(ln), passengerId(id) {
    cout << "Parameterized constructor: Person." << endl;
}

Person::~Person() {
    cout << "Destructor called for Person: " << name << " " << lastname << endl;
}


class PassengerTrain {
private:
    int currentPassengerCount;
    Person passengers[10];

public:
    PassengerTrain();
    ~PassengerTrain();

    bool isFull() const{
        return currentPassengerCount >= 10;
    }

    void boardPassenger(const Person&);
    void disembarkPassenger(int);
    void displayPassengers() const;
};

PassengerTrain::PassengerTrain() : currentPassengerCount(0) {
    cout << "Default constructor: PassengerTrain." << endl;
}

PassengerTrain::~PassengerTrain() {
    cout << "Destructor: PassengerTrain." << endl;
}

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
    if (currentPassengerCount == 0) {
        cout << "No passengers on board." << endl;
        return;
    }

    cout << "Current Passengers:" << endl;
    for (int i = 0; i < currentPassengerCount; ++i) {
        passengers[i].display();
    }
}


int main() {
    PassengerTrain train;
    int option, passengerId;
    string name, lastname;

    do {
        cout << "1) Board the train\n2) Exit the train\n3) Display Passengers\n4) Exit the app\nOption: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your last name: ";
            cin >> lastname;
            cout << "Enter your passenger ID: ";
            cin >> passengerId;
            train.boardPassenger(Person(name, lastname, passengerId));
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
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
        }
    } while (option != 4);

    return 0;
}