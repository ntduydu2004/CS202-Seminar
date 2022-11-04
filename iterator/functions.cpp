#include "functions.h"
using namespace std;
//Profile
string Profile::getId(){
    return Id;
}
string Profile::getMail(){
    return Mail;
}
Profile::Profile(string Id, string Mail){
    this->Id = Id;
    this->Mail = Mail;
}


// Profile Iterator
ProfileIterator::ProfileIterator(const Profile& x){
    data = x;
    next = NULL;
}
ProfileIterator* ProfileIterator::getNext(){
    if (hasMore()) return next;
}
bool ProfileIterator::hasMore(){
    return next != NULL;
}
Profile ProfileIterator::getdata(){
    return data;
}


// facebook, social network
FacebookIterator Facebook::createFriendsIterator(string proFileId){
    return FacebookIterator(*this, proFileId, "friends");
}
FacebookIterator Facebook::createCoworkersIterator(string proFileId){
    return FacebookIterator(*this, proFileId, "coworkers");
}
vector <Profile> Facebook::getAllUsers(){
    return profileUsers;
}


// Facebook Iterator
void FacebookIterator::lazyInit(){
    if (cache.size() == 0){
        cache = facebook.getAllUsers();
    }
}
FacebookIterator::FacebookIterator(const Facebook& facebook, string profileId, string type): facebook(facebook), profileId(profileId), type(type) {
}
Profile FacebookIterator::getNext(){
    if (hasMore()){
        currentPosition++;
    }
    return cache[currentPosition];
}
bool FacebookIterator::hasMore(){
    lazyInit();
    return (int)cache.size() < currentPosition;
}


// Social Spammers
void SocialSpammer::send(ProfileIterator* iterator, string message){
    while(iterator->hasMore()){
        Profile usertemp = iterator->getdata();
        system.sendEmail(usertemp.getMail(), message);
        iterator = iterator->getNext();
    }
}



// Application
void Application::config(Facebook& x){
    network = x;
}
void Application::sendSpam(Profile& x){
    ProfileIterator* temp = new ProfileIterator(x);
    spammer.send(temp, "Very Important Message!!");
}