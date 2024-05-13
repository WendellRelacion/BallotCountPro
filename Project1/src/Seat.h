/*****************************************************************//**
 * \file   Seat.h
 * \brief 
 *
 * \author Team 11
 * \date   March 2024
***********************************************************************/
#ifndef SEAT_H
#define SEAT_H

/**
 * @class Seat
 * @brief Seat class that defines the functionalites for the seat object
 * 
 */
class Seat {
private:
    int seats;

public:
    /**
     * \brief Gets the seat object
     * 
     * \param none
     * \return An integer representing the number of seats
     */
    int getSeats();

    /**
     * \brief Sets the seat object
     * 
     * \param numSeats This is a 
     * \return none
     */
    void setSeats(int numSeats);
    
    /**
     * \brief Adds one to the existing integer seats
     * 
     * \param none
     * \return none
     */
    void incSeats();
};

#endif /* SEAT_H */
