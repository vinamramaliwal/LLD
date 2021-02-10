#include<bits/stdc++.h>
using namespace std;
public class Movie{
    int id;
    string name;
    //other metadata
}
public class SeatLock {
    private Seat seat;
    private Show show;
    private Integer timeoutInSeconds;
    private Date lockTime;
    private String lockedBy;

    public boolean isLockExpired() {
        final Instant lockInstant = lockTime.toInstant().plusSeconds(timeoutInSeconds);
        final Instant currentInstant = new Date().toInstant();
        return lockInstant.isBefore(currentInstant);
    }
}
public class Booking{
    Movie* movie;
    Threatre* theatre;
    Screen* screen;
    Show* show;
    List<seats*> seatsBooked;
    
}
public class Theatre{
    int id;
    string name;
    list<Screen*> lisofScreens;
    set<Movie*> setofMovies;
}
public class Screen{
    int id;
    string name;
    list<Show*> lisofShows;
    Theatre* Theatre;
    
}
public class Show{
    Movie* curr_movie;
    int startTime;
    int endTime;
    Screen* screen;
    List<Seats*> listofSeats;
};
public class Seat{
    int rownum;
    int colnum;
    Seatstatus st;
    int price;
};
public enum Seatstatus{Booked,Available,Not_Available};

int main()
{
    
      
 
}
