#ifndef ORDER_H
#define ORDER_H
#include "QString"

#include "word.h"

class Order : public word
{
public:
    Order(QString a);

    QString nazwaklasy() override;
};

#endif // ORDER_H
