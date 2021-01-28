#include<bits/stdc++.h>
using namespace std;
class Room;
class Meeting
{
    int start;
    int end;
    Room* assigned_room;
    public:
    Meeting(int start,int end,Room* assigned_room)
    {
        this->start=start;
        this->end=end;
        this->assigned_room=assigned_room;
    }
    int getStart(){return start;}
    int getEnd(){return end;}
    
};
class Room{
    int id;
    string name;
    vector<Meeting*> calendar;
    public:
    Room(int id,string name)
    {
        this->id=id;
        this->name=name;
    }
    int getId(){return id;};
    vector<Meeting*> getCalendar(){return calendar;};
    void updateCalendar(Meeting* m)
    {
        calendar.push_back(m);
        return;
    }
    bool bookRoom(int start,int end)
    {
        int i;
        for(i=0;i<calendar.size();i++)
        {
            int x=calendar[i]->getStart();
            int y=calendar[i]->getEnd();
            if(end<=x||start>=y)
                continue;
            else
            {
                cout<<"Room not available for these timings. Choose another Room"<<endl;
                return false;
            }
        }
        Meeting *newMeeting=new Meeting(start,end,this);
        this->updateCalendar(newMeeting);
        cout<<"Meeting scheduled successfully"<<endl;
        return true;
    }
    
};

class Scheduler
{
    vector<Room*> listOfRooms;
    public:
    Room* createRoom(int id,string name)
    {
        Room* newRoom=new Room(id,name);
        listOfRooms.push_back(newRoom);
        return newRoom;
    }
    bool bookRoom(int start,int end,int id)
    {
        Room *r;
        int i;
        for(i=0;i<listOfRooms.size();i++)
        {
            r=listOfRooms[i];
            if(r->getId()==id)
                break;
        }
        if(i==listOfRooms.size())
        {
            cout<<"Invalid Room id"<<end;
            return false;
        }
        return r->bookRoom(start,end);
        
    }
    void showScheduleOfAllRooms()
    {
        for(int i=0;i<listOfRooms.size();i++)
        {
            Room *p=listOfRooms[i];
            cout<<"Room Id="<<p->getId()<<endl<<"Meeting timings are"<<endl;
            vector<Meeting*> v=p->getCalendar();
            for(int j=0;j<v.size();j++)
            {
                cout<<v[j]->getStart()<<" "<<v[j]->getEnd()<<endl;
            }
        }
    }
    
};
int main()
{
    Scheduler* Jeera=new Scheduler();
    Jeera->createRoom(1,"Conference Hall-1");
    Jeera->createRoom(2,"Conference Hall-2");
    Jeera->createRoom(3,"Conference Hall-3");
    Jeera->bookRoom(9,11,1);
    Jeera->bookRoom(10,12,1);
    Jeera->bookRoom(10,15,2);
    Jeera->bookRoom(15,16,2);
    Jeera->showScheduleOfAllRooms();
    
}
