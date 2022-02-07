#ifndef NEWSKETCH_SCREEN_H
#define NEWSKETCH_SCREEN_H

#include <QDialog>
#include <QListWidgetItem>
#include <QAbstractButton>

namespace Ui {
class newsketch_screen;
}

class newsketch_screen : public QDialog
{
    Q_OBJECT

public:
    explicit newsketch_screen(QWidget *parent = nullptr);
    ~newsketch_screen();

private slots:
    void on_buttonBox_accepted();

    void on_controllerTypeList_itemClicked(QListWidgetItem *item);

    void on_lightNumberlineEdit_textEdited(const QString &arg1);

    void on_broweButtonSketchPath_clicked();

    void on_browseButtonBytePath_clicked();

    void on_openSketchpushButton_clicked();

private:
    QListWidgetItem controllertypeitem;

    int lightnumber = 0;

    QString sketchpath = "";

    QString bytepath = "";

    Ui::newsketch_screen *ui;
};

#endif // NEWSKETCH_SCREEN_H
