#ifndef GESTION_EMPLYER_H
#define GESTION_EMPLOYER_H
#include "cruds_employer.h"
#include <QMessageBox>
#include <QDialog>
#include <QMediaPlayer>


namespace Ui {
class gestion_employer;
}

class gestion_employer : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_employer(QWidget *parent = nullptr);
    ~gestion_employer();

private slots:
    void on_pushButton_clicked();

    void on_ajouter_employer_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_nom_clicked();

    void on_prenom_clicked();

    void on_id_clicked();





    void on_checkBoxprenom_clicked();

    void on_checkBoxnom_clicked();

    void on_checkBoxid_clicked();


    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::gestion_employer *ui;
    cruds_employer tempemployer;
    QMediaPlayer* player;

};

#endif // GESTION_EMPLOYER_H
