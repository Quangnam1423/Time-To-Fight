CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD -MP -g  # Thêm cờ -g để tạo thông tin gỡ lỗi
CPPFLAGS = 
LDFLAGS = 
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Tìm tất cả các file .cpp trong thư mục con
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) \
          $(wildcard $(SRC_DIR)/*/*.cpp) \
          $(wildcard $(SRC_DIR)/*/*/*.cpp)

# Chuyển đổi các file .cpp thành .o tương ứng trong thư mục obj
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Tự động tạo file .d cho các phụ thuộc
DEPENDS = $(OBJECTS:.o=.d)

# Tên file thực thi
TARGET = $(BIN_DIR)/Time_To_Fight

# Quy tắc chính
all: $(TARGET)

# Quy tắc tạo file thực thi
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

# Quy tắc tạo file .o từ file .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@) # Tạo thư mục nếu chưa tồn tại
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Tạo thư mục bin nếu chưa tồn tại
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Quy tắc dọn dẹp
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Quy tắc để chạy chương trình trong GDB
debug: $(TARGET)
	gdb ./$(TARG
