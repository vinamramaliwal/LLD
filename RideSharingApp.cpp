#include<bits/stdc++.h>
using namespace std;
enum RideStatus {IDLE,CREATED,WITHDRAWN,COMPLETED};
class Ride;
class Driver
{
    public:
    string name;
    Ride* ride_assigned;
     Driver(string name)
    {
        this->name=name;
        ride_assigned=NULL;
    }
    
};
class Ride{
    public:
    int id;
    int origin;
    int destination;
    int seats;
    int amount;
    static const int AMT_PER_KM= 20;
    RideStatus rideStatus;
    Driver* driverAssigned;
    Ride(int id,int origin,int destination,int seats)
    {
        this->id=id;
        this->origin=origin;
        this->destination=destination;
        this->seats=seats;
    }
    int calculateAmout(bool isPriorityRider)
    {
        
        int numerOfKilometers=destination-origin;
        
        if(seats>=2)
            amount=numerOfKilometers*seats*(isPriorityRider?0.75:1);
        else if(seats==1)
            amount=numerOfKilometers*AMT_PER_KM*(isPriorityRider?0.75:1);
        
        return amount;
    }
    
};

class Rider
{
    public:
    string name;
    list<Ride*> ridesBooked;
    Rider(string name)
    {
        this->name=name;
    }
    Ride* createRide(int id,int origin,int destination,int seats)
    {
        Ride* newRide=new Ride(id,origin,destination,seats);
        newRide->rideStatus=CREATED;
        ridesBooked.push_back(newRide);
        return newRide;
    }
    void updateRide(int id,int origin,int destination,int seats)
    {
        auto it=ridesBooked.rbegin();
        for(;it!=ridesBooked.rend();it++)
        {
            if((*it)->id==id)
                break;
        }
        if((*it)->rideStatus!=RideStatus::CREATED)
        {
            cout<<"Ride Not in Progress,Can't Update"<<endl;
            return;
        }
        (*it)->origin=origin;
        (*it)->destination=destination;
        (*it)->seats=seats;
    }
    void withdrawRide(Ride* ride)
    {
        ride->rideStatus=RideStatus::WITHDRAWN;
        ridesBooked.remove(ride);
    }
    int closRide(Ride* ride)
    {
        int amount=ride->calculateAmout(ridesBooked.size()>=10);
        Driver* d1=ride->driverAssigned;
        d1->ride_assigned=NULL;
        ride->rideStatus=RideStatus::COMPLETED;
        return amount;
    }
};
class RideSharingApp
{
    public:
    list<Rider*> listOfRiders;
    list<Driver*> listOfDrivers;
    Driver* addDriver(string name)
    {
        Driver* d1=new Driver(name);
        listOfDrivers.push_back(d1);
        return d1;
    }
    Rider* addRider(string name)
    {
        Rider* r1=new Rider(name);
        listOfRiders.push_back(r1);
        return r1;
    }
    void showdrivers()
    {
        cout<<"Drivers Available"<<endl;
        for(auto it=listOfDrivers.begin();it!=listOfDrivers.end();it++)
        {
            cout<<(*it)->name<<" ";
        }
        cout<<endl;
    }
};

int main() {
    RideSharingApp* Uber=new RideSharingApp();
    Uber->addDriver("Ayush");
    Uber->addDriver("Abhishek");
    Uber->addDriver("Avanish");
    Uber->addDriver("Kuldeep");
    Uber->addDriver("Nikhil");
    Uber->showdrivers();
    
    Rider* r1=Uber->addRider("Vinamra");
    cout<<"Enter details for Rider Vinamra"<<endl;
    Ride* ride1=r1->createRide(0,50,60,2);
    cout<<"Ride started"<<endl;
    auto it=Uber->listOfDrivers.begin();
    for(;it!=Uber->listOfDrivers.end();it++)
    {
        if((*it)->ride_assigned==NULL)
        {
            (*it)->ride_assigned=ride1;
            break;
        }
    }
    ride1->driverAssigned=*it;
    cout<<"Driver assigned="<<ride1->driverAssigned->name<<endl;
    int e=r1->closRide(ride1);
    cout<<"Ride ended:Amout charged="<<e<<endl;
    
    
}
