#include <bits/stdc++.h>
using namespace std;
class Profile{
private:
    string Id;
    string Mail;
public:
    Profile(){};
    Profile(string Id, string Mail);
    string getId();
    string getMail();
};

// Iterator class
class ProfileIterator{
private:
    Profile data;
    ProfileIterator *next;
public:
    ProfileIterator(){};
    ProfileIterator(const Profile& x);
    Profile getdata();
    ProfileIterator* getNext();
    bool hasMore();
};

// Iterable Collection class
class SocialNetWork{
protected:
    vector <Profile> profileUsers;
public:
    virtual FacebookIterator createFriendsIterator(string proFileId) = 0;
    virtual FacebookIterator createCoworkersIterator(string proFileId) = 0;
};

// Concrete collection class
class Facebook: public SocialNetWork{
public:
    // Iterator creation code
    FacebookIterator createFriendsIterator(string proFileId);
    FacebookIterator createCoworkersIterator(string proFileId);
    vector <Profile> getAllUsers();
};

// Concrete iterator class
class FacebookIterator: public ProfileIterator{
private:
    Facebook facebook;
    string profileId;
    string type;
    int currentPosition;
    vector <Profile> cache;
    void lazyInit();
public:
    FacebookIterator(){};
    FacebookIterator(const Facebook& facebook, string profileId, string type);
    Profile getNext();
    bool hasMore();
};

// Client class
class SocialSpammer{
public:
    System system;
    void send(ProfileIterator* iterator, string message);
    
};
class Application{
public:
    Facebook network;
    SocialSpammer spammer;

    void config(Facebook& x);
    void sendSpam(Profile& x);
};

// System
class System{
public:
    // no implement, just define the way how Social Spammers work
    void sendEmail(string email, string message);
};