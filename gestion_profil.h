#ifndef GESTION_SALLES_H
#define GESTION_SALLES_H
#include <QMessageBox>
#include <QDialog>
#include "cruds_profil.h"
#include <QMediaPlayer>

namespace Ui {
class gestion_profil;
}

class gestion_profil : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_profil(QWidget *parent = nullptr);
    ~gestion_profil();

private slots:
    void on_ajouter_profil_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_ajouter_clicked();

private:
    Ui::gestion_profil *ui;
    cruds_profil tempsalles;
     QMediaPlayer* player;

};

#endif // GESTION_PROFIL_H
