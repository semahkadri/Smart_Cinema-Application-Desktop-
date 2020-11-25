#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QVariant>
#include<QSqlQuery>
#include<QString>
#include<QSqlQueryModel>

class employer
{
    int idemp;
    QString nomemp;
    QString prenomemp;
     QString mailemp;

public:
    employer();
    employer(int,QString,QString,QString);
    int get_idemp(){return idemp;}
    QString get_nomemp(){return nomemp;}
    QString get_prenomemp(){return prenomemp;}
    QString get_mailemp(){return mailemp;}
      bool ajouter();
      bool supprimer(int);
};

#endif // EMPLOYER_H
