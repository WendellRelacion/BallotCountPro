#include "Seat.h"

int Seat::getSeats() {
    return seats;
}

void Seat::setSeats(int numSeats) {
    seats = numSeats;
}

void Seat::incSeats() {
    seats += 1;
}
