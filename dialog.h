#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_envoyer_clicked();

    void on_lineEdit_adresse_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
