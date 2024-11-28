#include <iostream>
#include <string>
using namespace std;

// Template for a simple key-value storage
template <typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}

    void displayPair() const {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

class Person {
private:
    string name;
    string lastname;
    int passengerId;

public:
    Person();
    Person(string, string, int);
    virtual ~Person();

    string getName() const { return name; }
    string getLastName() const { return lastname; }
    int getPassengerId() const { return passengerId; }

    virtual void display() const {
        cout << "Name: " << name << ", Last Name: " << lastname << ", ID: " << passengerId << endl;
    }
};

Person::Person() : name("Unknown"), lastname("Unknown"), passengerId(0) {
    cout << "Default constructor - Person." << endl;
}

Person::Person(string n, string ln, int id) : name(n), lastname(ln), passengerId(id) {
    cout << "Constructor - Person" << endl;
}

Person::~Person() {
    cout << "Destructor - Person" << endl;
}

class Passengers : public Person {
private:
    int ticketNumber;

public:
    Passengers();
    Passengers(string, string, int, int);
    ~Passengers();
    void display() const override; // Override the display method for passengers
};

Passengers::Passengers() : ticketNumber(0) {
    cout << "Default Constructor - Passengers" << endl;
}

Passengers::Passengers(string a, string b, int c, int t) : Person(a, b, c), ticketNumber(t) {
    cout << "Constructor - Passengers" << endl;
}

Passengers::~Passengers() {
    cout << "Destructor - Passengers" << endl;
}

void Passengers::display() const {
    Person::display();
    cout << "Ticket Number: " << ticketNumber << endl;
}

// Overloaded display method for different parameter types
void display(string message) {
    cout << "Message: " << message << endl;
}

void display(int number) {
    cout << "Number: " << number << endl;
}

class PassengerTrain {
private:
    int currentPassengerCount;
    Person* passengers[3];

public:
    PassengerTrain();
    ~PassengerTrain();

    void boardPassenger(string name, string lastname, int id);
    void boardPassenger(string name, string lastname, int id, int ticketNumber); // Overloaded version

    bool isFull() const {
        return currentPassengerCount >= 3;
    }

    void disembarkPassenger(int);
    void displayPassengers() const;
};

PassengerTrain::PassengerTrain() : currentPassengerCount(0) {
    cout << "Default constructor - PassengerTrain." << endl;
    for (int i = 0; i < 3; ++i) {
        passengers[i] = nullptr;
    }
}

PassengerTrain::~PassengerTrain() {
    cout << "Destructor - PassengerTrain." << endl;
    for (int i = 0; i < currentPassengerCount; ++i) {
        delete passengers[i];
        passengers[i] = nullptr;
    }
}

void PassengerTrain::boardPassenger(string name, string lastname, int id) {
    if (!isFull()) {
        passengers[currentPassengerCount] = new Passengers(name, lastname, id, 0);
        cout << "Passenger boarded successfully!" << endl;
        ++currentPassengerCount;
    }
    else {
        cout << "Train is full!" << endl;
    }
}

void PassengerTrain::boardPassenger(string name, string lastname, int id, int ticketNumber) {
    if (!isFull()) {
        passengers[currentPassengerCount] = new Passengers(name, lastname, id, ticketNumber);
        cout << "Passenger with ticket number " << ticketNumber << " boarded successfully!" << endl;
        ++currentPassengerCount;
    }
    else {
        cout << "Train is full!" << endl;
    }
}

void PassengerTrain::disembarkPassenger(int id) {
    for (int i = 0; i < currentPassengerCount; ++i) {
        if (passengers[i]->getPassengerId() == id) {
            delete passengers[i];
            for (int j = i; j < currentPassengerCount - 1; ++j) {
                passengers[j] = passengers[j + 1];
            }
            passengers[currentPassengerCount - 1] = nullptr;
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
        passengers[i]->display();
    }
}

int main() {
    PassengerTrain train;

    train.boardPassenger("Alice", "Black", 1);
    train.boardPassenger("Bob", "White", 2, 1001); // Overloaded version

    train.displayPassengers();

    train.disembarkPassenger(1);

    train.displayPassengers();

    // Testing the template class
    Pair<string, int> trainInfo("Speed", 120);
    trainInfo.displayPair();

    // Testing overloaded display function
    display("Welcome aboard!");
    display(42);

    return 0;
}