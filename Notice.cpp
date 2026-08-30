#include "Notice.h"
#include <iostream>

Notice::Notice()
{
    this->type=OPEN_NOTICE;
    this->message="Event open";
    this->severity=0;
}
Notice::Notice(Noticetype type, const string& message,int severity)
{
    this->type=type;
    this->message=message;
    this->severity=severity;
}
Noticetype Notice::getType()const
{
    return this->type;
}
string Notice::getMessage()const
{
    return message;
}
int Notice:: getSeverity()const
{
    return severity;
}