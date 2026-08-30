#ifndef NOTICE_H
#define NOTICE_H
#include <iostream>

using namespace std;
enum Noticetype
{
    OPEN_NOTICE,
    CLOSE_NOTICE,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    TRANSPORT_DELAY,
    EVACUATE,
    RESUME,
    RUNWAY_ACTIVE
};
class Notice
{
    public:
        Notice(Noticetype type,const string& message,int severity);
        Noticetype getType()const;
        string getMessage()const;
        int getSeverity() const;
        Notice();
    private:
        Noticetype type;
        string message;
        int severity;

};
#endif/*Notice*/