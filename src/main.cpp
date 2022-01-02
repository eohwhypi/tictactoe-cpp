#include <iostream>
#include <array>
enum class Order{
    e = 0, // e stands for empty
    x = 1,
    o = 2,
};

class TicTacToe{
    private:
    std::array <std::array<Order, 3>, 3> board = {{
        {Order::e,Order::e,Order::e},
        {Order::e,Order::e,Order::e},
        {Order::e,Order::e,Order::e},
    }};
    public:
    void begin(){
        int choice;
        Order k = Order::e;
        std::cout << "Tic-Tac-Toe game" << std::endl;
        std::cout << "Choose who begins:" << std::endl;
        std::cout << "1. X" << std::endl;
        std::cout << "2. O" << std::endl;
        std::cin >> choice;
        if (choice == 1){
            k = Order::x;
            move(k);
        }
        else{
            if (choice == 2){
                k = Order::o;
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
                if (j == Order::e) p = 'e';
                else{
                    if (j == Order::x) p = 'X';
                    else p = 'O';
                }
                std::cout.width(3);
                std::cout << p;
            }
            std::cout << std::endl;
        }
    }

    void move(Order k){
        int column, row;
        draw();
        std::cout << "Column number from left to right - 1, 2, 3" << std::endl;
        std::cout << "Row number from top to bottom - 1, 2, 3" << std::endl;
        std::cout << "In which row do you want to move?" << std::endl;
        std::cin >> row;
        boundCheck(row, k);
        std::cout << "In which column do you want to move?" << std::endl;
        std::cin >> column;
        boundCheck(column, k);
        if (board.at(row - 1).at(column - 1) == Order::e){
            board.at(row - 1).at(column - 1) = k;
            if (k == Order::x) k = Order::o;
            else k = Order::x;
            result(k);
        }
        else{
            std::cout << "This spot is taken" << std::endl;
            move(k);
        }
    }

    void boundCheck(int check, Order k){
        if (check != 1 && check != 2 && check != 3){
            std::cout << "Wrong number" << std::endl;
            move(k);
        }
    }

    bool resultCheck(){
        for (int i = 0; i < 3; i++){
            if(board.at(0).at(i) == board.at(1).at(i)
            && board.at(0).at(i) == board.at(2).at(i)
            && board.at(0).at(i) != Order::e) return true;
            else{
                if(board.at(i).at(0) == board.at(i).at(1)
                && board.at(i).at(0) == board.at(i).at(2)
                && board.at(i).at(0) != Order::e) return true;
                else{
                    if(board.at(0).at(0) == board.at(1).at(1)
                    && board.at(0).at(0) == board.at(2).at(2)
                    && board.at(0).at(0) != Order::e) return true;
                    else{
                        if(board.at(0).at(2) == board.at(1).at(1)
                        && board.at(0).at(2) == board.at(2).at(0)
                        && board.at(0).at(2) != Order::e) return true;
                        else return false;
                    }
                }

            }
        }
    }

    void result(Order k){
        if (resultCheck() == true){
            if (k == Order::o){
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