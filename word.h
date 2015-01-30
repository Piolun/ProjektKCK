#ifndef WORD_H
#define WORD_H
#include <QString>
#include <QStringList>

class word
{
public:
    word(QString a);
    QStringList names;

    virtual QString nazwaklasy()=0;
    ~word();
};

#endif // WORD_H
