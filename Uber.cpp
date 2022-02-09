/*
Problem Statement:

We want to build a cab booking platform to allow a rider to book a cab.

Details:

The location is represented as a (x, y) coordinate.
Distance between two points (x1, y1) and(x2, y2) is sqrt((x1-x2)^2 + (y1-y2)^2)
Platform has decided upon maximum distance a driver has to travel to pickup a rider.
A cab has only 1 driver.
Sharing of cab is not allowed between riders
There is a single type of cab
Please build an application that exposes following features to riders and drivers.

Register a rider.
Register a driver/cab
Update a cab's location
A driver can switch on/off his availability
A rider can book a cab
Fetch history of all rides taken by a rider.
End the Trip
Expectation from this round

Demonstrable code is first expectation. To do this, you can choose any interface you are comfortable with - CLI, WebApp, MobileApp, APIs or even simply run the code via Tests or a main method.
Code should be extensible.
Clean professional level code.
Functional Completeness including good modelling.
User Identification but not authentication.
Backend Database is optional. However modelling should be complete.
*/



#define MAX_DISTANCE_FOR_DRIVER 20
class Driver;
enum RideStatus {CREATED,WITHDRAWN,COMPLETED};
class Location {
    public:
    int x;
    int y;
    Location(int x,int y){
        this->x=x;
        this->y=y;
    }
};
class Ride {
    public:
    Location* origin;
    Location* destination;
    int distance;
    Driver* driverassigned;
    RideStatus rideStatus;
    Ride(Location* o,Location* d,Driver* dr){
        this->origin=o;
        this->destination=d;
        this->driverassigned=dr;
        this->distance=sqrt(pow(o->x-d->x,2)+pow(o->y-d->y,2));
        rideStatus=CREATED;
    }
    
};
class Rider {
    public:
    list<Ride*> ridesBooked;
    Location* location;
    string name;
    Rider(string name,Location* l){
        this->location=l;
        this->name=name;
    }
    void createRide(Location* o,Location* d,Driver* dr){
        Ride* ride=new Ride(o,d,dr);
        ridesBooked.push_back(ride);
    }
};
class Driver {
    public:
    Location* location;
    string name;
    bool availability;
    Driver(string name,Location* l){
        this->location=l;
        this->name=name;
        this->availability=true;
    }
    void updateAvailabiliy(bool a){
        this->availability=a;
    }
    void updateLocation(int x,int y){
        this->location->x=x;
        this->location->y=y;
    }
};

class RideSharingApp{
    public:
    list<Driver*> listOfDrivers;
    list<Rider*> listOfRider;
    void addDriver(string name,Location* l){
        Driver* d1=new Driver(name,l);
        listOfDrivers.push_back(d1);
    }
    Rider* addRider(string name,Location* l){
        Rider* d1=new Rider(name,l);
        listOfRider.push_back(d1);
        return d1;
    }
    Driver* selectDriver(Rider* rider){
        
        return NULL;
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
    std::cout << "Hello World!\n";
    RideSharingApp* Uber=new RideSharingApp();
    Uber->addDriver("Ayush",new Location(1,0));
    Uber->addDriver("Abhishek",new Location(1,0));
    Uber->addDriver("Avanish",new Location(1,0));
    Uber->addDriver("Kuldeep",new Location(1,0));
    Uber->addDriver("Nikhil",new Location(1,0));
    Uber->showdrivers();
     Rider* r1=Uber->addRider("Vinamra",new Location(0,1));
    cout<<"Enter details for Rider Vinamra"<<endl;
    //Ride* ride1=r1->createRide(0,50,60,2);
    cout<<"Ride started"<<endl;
}
