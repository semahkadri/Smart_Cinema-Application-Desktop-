#ifndef GESTION_SALLES_H
#define GESTION_SALLES_H
#include <QMessageBox>
#include <QDialog>
#include "cruds_salles.h"


namespace Ui {
class gestion_salles;
}

class gestion_salles : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_salles(QWidget *parent = nullptr);
    ~gestion_salles();

private slots:
    void on_ajouter_chaise_clicked();

    void on_pushButton_supprimer_chaise_clicked();

private:
    Ui::gestion_salles *ui;
    cruds_salles tempsalles;
};

#endif // GESTION_SALLES_H
