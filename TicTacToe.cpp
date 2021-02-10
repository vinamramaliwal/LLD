Pubic class User{
    string name;
    CellType c;
}
public class Game{
    Board* board;
    User* a;
    User* b;
    Game(User* a,User* b)
    {
        this.a=a;
        this.b=b;
        board=new Board();
    }
    bool checkifUserWon(User* user)
    {
        
    }
    void endGame{
        
    }
}
public class Board{
    public:
    list<Cell*> listofCell;
    list<EmptyCell*> lisofEmptyCell;
    Board()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                Cell* c=new Cell(i,j);
                listofCell.push_back(c);
                lisofEmptyCell.push_back(c);
            }
        }
    }
    Cell* getCell(int i,int j)
    {
        for(auto it=listofCell.begin();it!=listofCell.end();it++)
        {
            cell *c=*it;
            if(c->row==i&&c->col==j)
                return c;
        }
        return NULL;
    }
    bool move(int i,int j,CellType c)
    {
        Cell *cell=getCell(i,j);
        if(cell==NULL)
            return false;
        cell->celltype=c;
        listofemptycell.erase(cell);
        return true;
    }
}
enum CellType{CROSS,CIRCLE,EMPTY};
public class Cell{
    public:
    CellType celltype;   
    int row;
    int col;
    Cell(int i,int j)
    {
        row=i;
        col=j;
        cellType=CellType::EMPTY;   
    }
    
}
