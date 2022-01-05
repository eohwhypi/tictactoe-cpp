#include <iostream>
#include <array>
enum class Value{
    e = 0, // e stands for empty
    x = 1,
    o = 2,
};

class TicTacToe{
    private:
    std::array <std::array<Value, 3>, 3> board = {{
        {Value::e,Value::e,Value::e},
        {Value::e,Value::e,Value::e},
        {Value::e,Value::e,Value::e},
    }};
    public:
    void begin(){
        char choice;
        char ans1[] = {'1', 'x', 'X'};
        char ans2[] = {'2', 'o', 'O'};
        const char * text = R"(Tic-Tac-Toe game
        Choose who begins:
        1. X
        2. O)";

        Value k = Value::e;
        std::cout << text << std::endl;
        std::cin >> choice;
        if (choice == ans1[0] | choice == ans1[1] | choice == ans1[2]){
            k = Value::x;
            move(k);
        }
        else{
            if (choice == ans2[0] | choice == ans2[1] | choice == ans2[2]){
                k = Value::o;
                move(k);
            }
            else{
                std::cout << "That's not a valid answer." << std::endl;
                begin();
            }
        }
    }

    void draw(){
        char p;
        for (int i = 0; i < 3; i++){
            for (auto j : board.at(i)){
                if (j == Value::e) p = 'e';
                else{
                    if (j == Value::x) p = 'X';
                    else p = 'O';
                }
                std::cout.width(3);
                std::cout << p;
            }
            std::cout << std::endl;
        }
    }

    void move(Value k){
        int column, row;
        const char * text = R"(
    Column number from left to right - 1, 2, 3
    Row number from top to bottom - 1, 2, 3
    In which row do you want to move?)";
        draw();
        std::cout << text << std::endl;
        std::cin >> row;
        boundCheck(row, k);
        std::cout << "In which column do you want to move?" << std::endl;
        std::cin >> column;
        boundCheck(column, k);
        if (board.at(row - 1).at(column - 1) == Value::e){
            board.at(row - 1).at(column - 1) = k;
            if (k == Value::x) k = Value::o;
            else k = Value::x;
            result(k);
        }
        else{
            std::cout << "This spot is taken" << std::endl;
            move(k);
        }
    }

    void boundCheck(int check, Value k){
        if (check != 1 && check != 2 && check != 3){
            std::cout << "Wrong number" << std::endl;
            move(k);
        }
    }

    bool resultCheck(){
        for (int i = 0; i < 3; i++){
            if(board.at(0).at(i) == board.at(1).at(i)
            && board.at(0).at(i) == board.at(2).at(i)
            && board.at(0).at(i) != Value::e) return true;
            else{
                if(board.at(i).at(0) == board.at(i).at(1)
                && board.at(i).at(0) == board.at(i).at(2)
                && board.at(i).at(0) != Value::e) return true;
                else{
                    if(board.at(0).at(0) == board.at(1).at(1)
                    && board.at(0).at(0) == board.at(2).at(2)
                    && board.at(0).at(0) != Value::e) return true;
                    else{
                        if(board.at(0).at(2) == board.at(1).at(1)
                        && board.at(0).at(2) == board.at(2).at(0)
                        && board.at(0).at(2) != Value::e) return true;
                        else return false;
                    }
                }

            }
        }
    }

    void result(Value k){
        if (resultCheck() == true){
            if (k == Value::o){
                draw();
                std::cout << "X won!" << std::endl;
            }
            else{
                draw();
                std::cout << "O won!" << std::endl;
            }
        }
        else move(k);
    }
};

int main(){
    TicTacToe game;
    game.begin();
}