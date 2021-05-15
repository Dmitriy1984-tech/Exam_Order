#pragma once
#include "Order.h"
class RushOrder :
    public Order
{
protected:
    string courier;
    Date deliveryDate;

public:
    RushOrder();
    RushOrder(Date date, Time_ time, string id,
        string courier,   Date deliveryDate);
    ~RushOrder();



    void setCourier(string courier);
    string getCourier();

    void setDeliveryDate(Date deliveryDate);
    Date getDeliveryDate();

    virtual string type() override;
    virtual string toString() override;

    virtual void save(ofstream& file) override;
    virtual void load(ifstream& file) override;

   
};

