//
//  event.cpp
//  hw3
//
//  Created by William  Escobar on 5/7/23.
//

//#include <iostream>
//#include <string>
////using namespace std;

//Your declarations and implementations would go here

//-----------------EVENT BASE CLASS--------------------------
class Event
{
    public:
    //cunstructor and destructor
    Event(std::string name) : eventName(name){}
    virtual ~Event(){}
    
    //accessors
    virtual bool isSport() const{return false;}
    std::string name() const{return eventName;}
    virtual std::string need() const = 0; //because we have one pure virtual function, we can't just create an Event object
                                    //it has to be a derived class which has the fully defined function
    private:
    std::string eventName;
};
//-----------BasketballGame Derived Class--------------------
class BasketballGame : public Event
{
    public:
    BasketballGame(std::string gameName) : Event(gameName){}
    virtual ~BasketballGame(){std::cout <<"Destroying the " << name() << " basketball game\n";}
    virtual bool isSport() const {return true;}
    virtual std::string need() const {return "hoops";}
    
};
//--------------HockeyGame Derived Class----------------------
class HockeyGame : public Event
{
    public:
    HockeyGame(std::string gameName) : Event(gameName){}
    virtual ~HockeyGame(){std::cout <<"Destroying the " << name() << " hockey game\n";}
    virtual bool isSport() const{return true;}
    virtual std::string need() const{return "ice";}
    
};
//---------------Concert Derived Class------------------------
class Concert : public Event
{
    public:
    Concert(std::string gameName, std::string musicGenre) : Event(gameName), genre(musicGenre) {}
    virtual ~Concert(){std::cout <<"Destroying the " << name() << " " << genre << " concert\n";}
    virtual bool isSport() const{return false;}
    virtual std::string need() const{return "a stage";}
    
    private:
    std::string genre;
    
};
