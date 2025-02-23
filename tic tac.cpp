#include<iostream>

using namespace std;

class gameboard{
    private:
    char board[3][3];

    public:
    gameboard(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = '_';
            }
        }
    }

    void print(){
        cout << "'  0  1  2" << endl;
        for(int i = 0; i < 3; i++){
            cout << i << "  ";
            for(int j = 0; j < 3; j++){
                cout << board[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void new_move(int i, int j, char m){
        board[i][j] = m;
    }

    bool valid_move(int i, int j){
        if(board[i][j] == '_') return true;
        else return false;
    }

    bool win_condition(){
        for(int i = 0; i < 3; i++){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_'){
                cout << board[i][0] << " WON the match.";
                return true;
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_'){
                cout << board[i][0] << " WON the match.";
                return true;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_'){
            cout << board[0][0] << " WON the match.";
            return true;
        }
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '_'){
            cout << board[2][0] << " WON the match.";
            return true;
        }
        return false;
    }

};

int main(){
    gameboard *b1 = new gameboard;
    b1->print();
    
    for(int i = 0; i < 9; i++){
        b1->print();
        if(i%2 == 0){
            cout << "X's move" << endl;
            int a, b;
            cin >> a >> b;
            while(!b1->valid_move(a,b)){
                cout << "Enter an empty space" << endl;
                cin >> a >> b;
                if(b1->valid_move(a,b)) break;
            }
            b1->new_move(a,b, 'X');
        }
        else{
            cout << "O's move" << endl;
            int a, b;
            cin >> a >> b;
            while(!b1->valid_move(a,b)){
                cout << "Enter an empty space" << endl;
                cin >> a >> b;
                if(b1->valid_move(a,b)) break;
            }
            b1->new_move(a,b, 'O');
        }
        if(i > 3){
            if(b1->win_condition()) break;
        }
    }
    b1->print();
    
    return 0;
}