#include <bits/stdc++.h>
using namespace std;
class Dice
{
	public:
	int throwDice()
	{
	return rand()%6+1;
	}
};
class Player:public Dice
{
	private:
	int position;
	public:
	string name;
	Player(string name)
	{
		this->position=0;
		this->name=name;
	}
	void setPosition(int x)
	{
		this->position=x;
	}
	int getPosition()
	{
		return this->position;
	}

};
class Board
{
   
	public:
	map<int,int> ladder;
	map<int,int> snake;
	
	void addSnake(int a ,int b)
	{
		this->snake[a]=b;
	}
	void addLadder(int a,int b)
	{
		this->ladder[a]=b;
	}
};
int main() {
	
	Board bd;
	cout<<"Enter the number of snakes"<<endl;
	int i,j,k,l,m,n,a,b,p,q;
	cin>>l;
	for(i=1;i<=l;i++)
	{
		cin>>a>>b;
		bd.addSnake(a,b);
		
	}
	cout<<"Enter the number of ladders"<<endl;
	cin>>l;
	for(i=1;i<=l;i++)
	{
		cin>>a>>b;
		bd.addLadder(a,b);
	}
	Player x("Gaurav");
	Player y("Sagar");
	srand(time(0)); 
	m=1;
	while(1)
	{
		a=x.getPosition();
		b=y.getPosition();
		if(a==100||b==100)
			break;
		if(m==1)
		{
				m=0;
				k=x.throwDice();
				if(a+k>100)
					{
						x.setPosition(a);
					}
				else{
						j=a+k;
					   x.setPosition(j);
						if(bd.snake.find(j)!=bd.snake.end())
						{
							x.setPosition(bd.snake[j]);
						}
						if(bd.ladder.find(j)!=bd.ladder.end())
						{
							x.setPosition(bd.ladder[j]);
						}
					}
			p=x.getPosition();
		cout<<x.name<<" rolled a "<<k<<" and moved from "<<a<<" to "<<p<<endl;
			
		}
		else{
			m=1;
				k=y.throwDice();
				if(b+k>100)
					{
						y.setPosition(b);
					}
				else{
						j=b+k;
					 y.setPosition(j);
						if(bd.snake.find(j)!=bd.snake.end())
						{
							y.setPosition(bd.snake[j]);
						}
						if(bd.ladder.find(j)!=bd.ladder.end())
						{
							y.setPosition(bd.ladder[j]);
						}
					}
			p=y.getPosition();
		cout<<y.name<<" rolled a "<<k<<" and moved from "<<b<<" to "<<p<<endl;
			
			
		}
		
		
	}
	if(a==100)
		cout<<"Gaurav won the game"<<endl;
	else if(b==100)
		cout<<"Sagar won the game"<<endl;
	
	
	return 0;
}
