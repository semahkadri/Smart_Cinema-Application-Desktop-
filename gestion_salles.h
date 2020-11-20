#ifndef GESTION_SALLES_H
#define GESTION_SALLES_H
#include <QMessageBox>
#include <QDialog>
#include "cruds_salles.h"
#include <QMediaPlayer>

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

    void on_pushButton_modifier_clicked();

    void on_checkBox_clicked();

private:
    Ui::gestion_salles *ui;
    cruds_salles tempsalles;
     QMediaPlayer* player;

};

#endif // GESTION_SALLES_H
