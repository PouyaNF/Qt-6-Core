#ifndef TOASTER_H
#define TOASTER_H

class Toaster   // not inherited from QObjec . It is interface 
{
public:
    virtual bool grill() = 0; //Most of the time
};

#endif // TOASTER_H
