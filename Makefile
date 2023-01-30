TARGET = K_tech
COMPILE = g++ -std=c++17

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC_F = src/
OBJ_F = obj/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
	$(COMPILE) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(COMPILE) -c $< -o $@

clean : 
	rm 	$(TARGET) $(PREF_OBJ)*.o



