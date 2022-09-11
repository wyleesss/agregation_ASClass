#pragma once
class Bus {
    unsigned seats;
    string model;
public:
    Bus(unsigned seats, string model) : seats(seats), model(model) {}
    Bus() : Bus(0, "") {}
    void get(int& get_seats, string& get_model) {
        get_model = model;
        get_seats = seats;
    }
    void set(unsigned set_seats, string& set_model) {
        model = set_model;
        seats = set_seats;
    }
    void print_info() {
        cout << "Model -> " << model << "; Seats -> " << seats << ";\n";
    }
};