#pragma once
class Truck {
    unsigned seats, weight;
    string model;
public:
    Truck(int seats, int weight, string model) : seats(seats), weight(weight), model(model) {}
    Truck() : Truck(0, 0, "") {}
    void get(int get_seats, int get_weight, string& get_model) {
        get_model = model;
        get_weight = weight;
        get_seats = seats;
    }
    void set(int set_seats, int set_weight, string set_model) {
        model = set_model;
        weight = set_weight;
        seats = set_seats;
    }
    void print_info() {
        cout << "Model -> " << model << "; Seats -> " << seats << "; Weight -> " << weight << ";\n";
    }
};
