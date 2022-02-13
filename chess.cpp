enum Color {WHITE,BLACK};
class Cellposition{
    int x;
    char y;
};
class Player{
    int id;
    string name;
    Color color;
    
};
class Piece{
    Color color;
    int alive_dead;
     virtual void move(Cellposition fromPosition,Cellposition toPosition)=0;
    virtual vector<Cellposition> possibleMoves(Cellposition fromPosition)=0;
    virtual bool validMove(Cellposition fromPosition,Cellposition toPosition)=0;
};
class pawn: Piece{
    
    void move(Cellposition fromPosition,Cellposition toPosition);
    vector<Cellposition> possibleMoves(Cellposition fromPosition);
    bool validMove(Cellposition fromPosition,Cellposition toPosition);
    
};

class Move{
    Cellposition fromPosition;
    Cellposition tofromPosition;
    Player* player;
    Piece* piece;
    Piece* peiceKilled;
};


class Positions{
    Cellposition cellposition;
    Piece* peice;
};
enum GameStatus { A_WON,B_WON,PREPARING,ABORTED,IN_PROGRESS};
class ChessGame{
    vector<vector<Positions*>> chessBoard;
    vector<Player*> players;
    GameStatus gameStatus;
    list<Move*> lisofMoves;
    Player* turn; 
    void updateBoard(Move* move){
        
    }
    void changeGameStatus(GameStatus gameStatus){
        
        
    }
    void move(Cellposition fromPosition,Cellposition toPosition);
};
int main() {
    std::cout << "Hello World!\n";
    ChessGame* chess=new ChessGame();
    Position* first=new Position()
}
