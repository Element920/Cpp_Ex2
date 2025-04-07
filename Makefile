#israelmor555@gmail.com

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

SRC = Graph.cpp main.cpp Algorithms.cpp DataStructures.cpp
OBJS = $(SRC:.cpp=.o)
EXEC = graph

TEST_SRC = Tests.cpp Algorithms.cpp Graph.cpp DataStructures.cpp
TEST_OBJS = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_graph

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main: $(EXEC)
	./$(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

valgrind_tests: $(TEST_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_EXEC)


clean:
	rm -f $(OBJS) $(TEST_OBJS) $(EXEC) $(TEST_EXEC)
