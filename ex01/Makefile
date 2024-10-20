# 変数の定義
NAME = serialize_test
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# 実行ファイルの生成
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# オブジェクトファイルの生成
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# プログラムの実行
run: $(NAME)
	./$(NAME)

# クリーンアップ
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re run
