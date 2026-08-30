CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

TARGET = eventflow

SOURCES = main.cpp \
          EventComponent.cpp \
          EventUnit.cpp \
          EventGroup.cpp \
          AirDisplayStage.cpp \
          Gate.cpp \
          VendorStall.cpp \
          MedicalPost.cpp \
          ShuttleStop.cpp \
          InformationScreen.cpp \
          DroneDisplayUnit.cpp \
          FireResponseTeam.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)