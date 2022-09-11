#include <iostream>
#include <vector>
using namespace std;

const unsigned MAX_SEATS = 50, MAX_WEIGHT = 10000, MAX_STATION_VEHICLES = 100;

class Bus {
    unsigned seats;
    string model;
public:
    Bus(int seats, string model) : seats(seats), model(model) {}
    Bus() : Bus(0, "") {}
    void get(int& get_seats, string& get_model) {
        get_model = model;
        get_seats = seats;
    }
    void set(int set_seats, string& set_model) {
        model = set_model;
        seats = set_seats;
    }
    void print_info() {
        cout << "(i) <Bus> Model -> " << model << "; Seats -> " << seats << ";\n";
    }
};

class Car {
    unsigned seats;
    string model;
public:
    Car(int seats, string model) : seats(seats), model(model) {}
    Car() : Car(0, "") {}
    void get(int& get_seats, string& get_model) {
        get_model = model;
        get_seats = seats;
    }
    void set(int set_seats, string& set_model) {
        model = set_model;
        seats = set_seats;
    }
    void print_info() {
        cout << "(i) <Car> Model -> " << model << "; Seats -> " << seats << ";\n";
    }
};

class Truck {
    unsigned seats, weight;
    string model;
public:
    Truck(int seats, int weight, string model) : seats(seats), weight(weight), model(model) {}
    Truck() : Truck(0, 0, "") {}
    void get(int& get_seats, int& get_weight, string& get_model) {
        get_model = model;
        get_weight = weight;
        get_seats = seats;
    }
    void set(int set_seats, int set_weight, string& set_model) {
        model = set_model;
        weight = set_weight;
        seats = set_seats;
    }
    void print_info() {
        cout << "(i) <Truck> Model -> " << model << "; Seats -> " << seats << "; Weight -> " << weight << "kg;\n";
    }
};

class AutoStation {
    vector<Bus>B;
    vector<Car>C;
    vector<Truck>T;
    unsigned truckN, carN, busN;
public:
    int get_busN() { return busN; }
    int get_carN() { return carN; }
    int get_truckN() { return truckN; }
    AutoStation() {
        truckN = carN = busN = 0;
    }
    void print_info() {
        cout << "//////////////////\\\\\\\\\\\n" <<
                "|STATION CAPACITY|[" << MAX_STATION_VEHICLES <<
             "]\n|FREE PLACES     |[" << MAX_STATION_VEHICLES - (get_carN() + get_busN() + get_truckN()) <<
             "]\n|::BUSES         |[" << get_busN() <<
             "]\n|::CARS          |[" << get_carN() <<
             "]\n|::TRUCKS        |[" << get_truckN() <<
             "]\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////\n";
    }
    Bus getBus(unsigned number) {
        if (number - 1 < busN) return B[number - 1];
        cout << "(!) bus number error\n";
        return Bus(0, "");
    }
    void addBus(int seats, string model) {
        if (carN + busN + truckN < MAX_STATION_VEHICLES && seats <= MAX_SEATS) {
            busN++;
            B.push_back(Bus(seats, model));
            cout << "(+) bus has been added\n";
            return;
        }
        cout << "(!) impossible to add new bus" << (seats > MAX_SEATS ? ":<too many seats>\n" : ":<station is full>\n");
    }
    void delBus(unsigned number) {
        if (busN > number - 1) {
            B.erase(B.begin() + (number - 1));
            busN--;
            cout << "(-) bus #" << number << " has been deleted\n";
            return;
        }
        cout << "(!) impossible to delete the bus\n";
    }

    Car getCar(unsigned number) {
        if (number - 1 < carN) return C[number - 1];
        cout << "(!) car number error\n";
        return Car(0, "");
    }
    void addCar(int seats, string model) {
        if (carN + busN + truckN < MAX_STATION_VEHICLES && seats <= MAX_SEATS) {
            carN++;
            C.push_back(Car(seats, model));
            cout << "(+) car has been added\n";
            return;
        }
        cout << "(!) impossible to add new car" << (seats > MAX_SEATS ? ":<too many seats>\n" : ":<station is full>\n");
    }
    void delCar(unsigned number) {
        if (carN > number - 1) {
            C.erase(C.begin() + (number - 1));
            carN--;
            cout << "(-) car #" << number <<" has been deleted\n";
            return;
        }
        cout << "(!) impossible to delete the car\n";
    }

    Truck getTruck(unsigned number) {
        if (number - 1 < truckN) return T[number - 1];
        cout << "(!) truck number error\n";
        return Truck(0, 0, "");
    }
    void addTruck(int seats, int weight, string model) {
        if (carN + busN + truckN < MAX_STATION_VEHICLES && weight <= MAX_WEIGHT) {
            truckN++;
            T.push_back(Truck(seats, weight, model));
            cout << "(+) truck has been added\n";
            return;
        }
        cout << "(!) impossible to add new truck" << (weight > MAX_WEIGHT ? ":<too much weigth>\n" : ":<station is full>\n");
    }
    void delTruck(unsigned number) {
        if (truckN > number - 1) {
            T.erase(T.begin() + (number - 1));
            truckN--;
            cout << "(-) truck #" << number << " has been deleted\n";
            return;
        }
        cout << "(!) impossible to delete the truck\n";
    }
};

int main() {
    srand(time(NULL));
    vector<string>bus_trucks_models{ "MERCEDES", "VOLVO", "SCANIA", "MAN", "SETRA", "TEMSA", "IVECO", "SUFFLE" };
    vector<string>car_models{ "AUDI", "MITSUBISHI", "MERCEDES", "VOLVO", "FORD", "BMW", "TOYOTA", "VOLKSWAGEN" };

    AutoStation station;

    station.addBus(60, bus_trucks_models[rand() % 8]);
    station.addBus(40, bus_trucks_models[rand() % 8]);
    station.addTruck(60, 10001, bus_trucks_models[rand() % 8]);
    station.getBus(1).print_info();
    station.getCar(8).print_info();
    station.delTruck(0);
    station.delBus(1);
    station.addTruck(2, 6733, bus_trucks_models[rand() % 8]);

    /*
    Для зручності закоментував. Код нижче створює та видяляє об'єкти на автостанції за допомогою функції rand()
    Деякі показники можуть спеціально перевищувати дозволену норму задля перевірки обмежень
    Код ніби стимулює роботу автостанції та в кінці можна побачити результати цієї роботи
    Але це може створити плутанину, тому виділений код не є обов'язковим у виконанні, всього лише творчий замисел
    */
    
    /*cout << "timeline:\n";
    for (int i = 0; i < 80; i++) {
        if(rand() % 2 == 0)
            station.addBus(rand() % 40 + 20, bus_trucks_models[rand() % 8]);
        if(rand() % 2 == 0)
            station.addCar(rand() % 4 + 4, car_models[rand() % 8]);
        if(rand() % 2 == 0)
            station.addTruck(rand() % 2 + 1, rand() % 8000 + 4000, bus_trucks_models[rand() % 8]);
    }

    for (int i = 0; i < 10; i++) {
        if (rand() % 2 == 0)
            station.delBus(rand() % station.get_busN());
        if (rand() % 2 == 0)
            station.delTruck(rand() % station.get_truckN());
        if (rand() % 2 == 0)
            station.delCar(rand() % station.get_carN());
    }*/
    cout << "Buses:\n";
    for (int i = 1; i <= station.get_busN(); i++)
        station.getBus(i).print_info();
    cout << "Cars:\n";
    for (int i = 1; i <= station.get_busN(); i++)
        station.getCar(i).print_info();
    cout << "Trucks:\n";
    for (int i = 1; i <= station.get_truckN(); i++)
        station.getTruck(i).print_info();


    station.print_info();
}