#ifndef GESTION_FILM_H
#define GESTION_FILM_H
#include "cruds_films.h"
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class gestion_film;
}

class gestion_film : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_film(QWidget *parent = nullptr);
    ~gestion_film();

private slots:
    void on_pushButton_clicked();

    void on_ajouter_film_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::gestion_film *ui;
    cruds_films tempfilm;
};

#endif // GESTION_FILM_H
