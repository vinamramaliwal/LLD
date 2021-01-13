enum Celltype{EMPTY,FOOD,SNAKE_NODE};
class cell
{
    public:
    Celltype ctp;
    int i;
    int j;
    cell();
    cell(int i,int j)
    {
        this->i=i;
        this->j=j;
        this->ctp=EMPTY;
    }
    void setCelltype(Celltype name)
    {
        this->ctp=name;
    }
    Celltype getCelltype()
    {
        return this->ctp;
    }
};
class Snake
{
    public:
    list<cell*> mysnake;
    cell* head;
    Snake(cell* initpos)
    {
        head=initpos;
        initpos->setCelltype(SNAKE_NODE);
        mysnake.push_back(initpos);
        
    }
    void grow(cell* nextcell)
    {
        cout<<"Snake is growing to "<<nextcell->i<<" "<<nextcell->j<<endl;
        nextcell->setCelltype(SNAKE_NODE);
        mysnake.push_front(nextcell);
        head=nextcell;
        
    }
        bool checkcrash(cell* nextcell)
        {
            cout<<"Going to check for crash"<<endl;
            for(auto it=mysnake.begin();it!=mysnake.end();it++)
            {
               if((*it)->i==nextcell->i&&(*it)->j==nextcell->j)
                        return true;
            }
            return false;
        }
    void move(cell* nextcell)
    {
        
        cout<<"Snake is moving to "<<nextcell->i<<" "<<nextcell->j<<endl;
        head=nextcell;
        cell *c=mysnake.back();
        (*c).setCelltype(EMPTY);
        nextcell->setCelltype(SNAKE_NODE);
        mysnake.push_front(nextcell);
        mysnake.pop_back();
    }
    
    
};


class Board
{
    public:
    int n,m;
    vector<vector<cell*>> matrix;
    Board(int n,int m)
    {
        this->n=n;
        this->m=m;
        int i,j;
        matrix.resize(n);
        for(i=0;i<n;i++)
        {
            matrix[i].resize(j);
            for(j=0;j<m;j++)
                matrix[i][j]=new cell(i,j);
        }
    }
    void generateFood()
    {
        cout<<"Going to generate food"<<endl;
        int x,y;
        while(1)
        {
            x=rand()%n;
            y=rand()%m;
            if((*matrix[x][y]).getCelltype()!=SNAKE_NODE||(*matrix[x][y]).getCelltype()!=FOOD)
            {
                break;
            }
        }
        matrix[x][y]->setCelltype(FOOD);
        return;
    }
};
class Game
{
    public:
    static const int DIRECTION_NONE=0,DIRECTION_RIGHT = 1,DIRECTION_LEFT = -1,DIRECTION_UP = 2,DIRECTION_DOWN = -2;
    Snake* snake;
    Board* board;
    int direction;
    bool gameOver;
    Game(Snake* snake,Board *board)
    {
        this->snake=snake;
        this->board=board;
    }
    void update()
    {
        cout<<"Going to update game"<<endl;
        if(!gameOver&&direction!=DIRECTION_NONE)
        {
            cell* nextcell=getNextCell(snake->head);
            if(gameOver)
                return;
            if(snake->checkcrash(nextcell))
            {
                direction=DIRECTION_NONE;
                gameOver=true;
            }
            else
            {
                
                if (nextcell->ctp==FOOD) {
                        snake->grow(nextcell);
                        board->generateFood();
                    }
                else
                    snake->move(nextcell);
            }
        }
    }
    cell* getNextCell(cell* currentPosition)
    {
        cout<<"Going to find next cell"<<endl;
        int row=currentPosition->i;
        int col=currentPosition->j;
         if (direction == DIRECTION_RIGHT) {
            col++;
        }
        else if (direction == DIRECTION_LEFT) {
            col--;
        }
        else if (direction == DIRECTION_UP) {
            row--;
        }
        else if (direction == DIRECTION_DOWN) {
            row++;
        }
        if(row<0||row>=10||col<0||col>=10)
        {
            gameOver=true;
            cout<<"NextCell out of Range::Game Over"<<endl;
            return NULL;
        }
        return board->matrix[row][col];
    }
    
};
int main() {
    std::cout <<"Going to start game";
       cell* initPos = new cell(0, 0);
       Snake *initSnake = new Snake(initPos);
        Board* board = new Board(10, 10);
        Game* newGame = new Game(initSnake, board);
        newGame->gameOver = false;
        newGame->direction = Game::DIRECTION_RIGHT;
    while(1)
    {
            for (int i = 0; i < 5; i++) 
            {
                if (i == 0)
                newGame->direction = Game::DIRECTION_DOWN;
            if (i == 2)
                newGame->board->generateFood();
             newGame->update();
            if (i == 3)
                newGame->direction = Game::DIRECTION_RIGHT;
            if (newGame->gameOver == true)
                return 0;
            }
    }
    return 0;
}
