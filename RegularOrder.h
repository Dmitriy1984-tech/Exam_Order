#pragma once
#include "Order.h"
class RegularOrder :
    public Order
{

public:
    RegularOrder();
    RegularOrder(Date date, Time_ time, string id);
    ~RegularOrder();

    virtual string type() override;
    virtual string toString() override;

    virtual void save(ofstream& file) override;
    virtual void load(ifstream& file) override;

   
};

