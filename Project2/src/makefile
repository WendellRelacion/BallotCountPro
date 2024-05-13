CC = g++

CFLAGS = -c

SOURCES = main.cpp Election.cpp Party.cpp PartyMPO.cpp PartyMV.cpp Candidate.cpp CandidateMPO.cpp CandidateMV.cpp  Ballot.cpp CandidateOPL.cpp OPLParty.cpp Seat.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = myprogram

all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean run
