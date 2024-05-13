#include "../../src/Seat.cpp"
#include "gtest/gtest.h"

class SeatTest : public ::testing::Test {
protected:
    Seat seat;

    void SetUp() override {
        seat.setSeats(10);
    }
};

TEST_F(SeatTest, GetSeats) {
    EXPECT_EQ(seat.getSeats(), 10);
}

TEST_F(SeatTest, SetSeats) {
    seat.setSeats(5);
    EXPECT_EQ(seat.getSeats(), 5);
}

TEST_F(SeatTest, IncSeats) {
    seat.incSeats();
    seat.incSeats();
    seat.incSeats();
    EXPECT_EQ(seat.getSeats(), 13);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
