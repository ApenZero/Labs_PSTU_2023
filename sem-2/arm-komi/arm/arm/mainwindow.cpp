#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (db.open()){
        ui->statusbar->showMessage("Успешное подключение к базе данных");

        model = new QSqlTableModel(this, db);
        model->setTable("lib");
        model->select();

        ui->tableView->setModel(model);
    }
    else{
        ui->statusbar->showMessage("Ошибка про подключении к базе данных");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString number = ui->number->text();
    QString name = ui->name->text();
    QString year = ui->year->text();
    QString place = ui->place->text();
    QString opisaniye = ui->opisaniye->text();
    model->insertRow(model->rowCount());
    QSqlQuery query;
    query.prepare("INSERT INTO lib (Номер, Тип, Название, Год, Место выпуска, Описание) "
                               "VALUES (:number, Текст, :name, :year, :place, :opisaniye )");
    query.bindValue(":number", number);
    query.bindValue(":name", name);
    query.bindValue(":year", year);
    query.bindValue(":place", place);
    query.bindValue(":opisaniye", opisaniye);
    query.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString number = ui->number->text();
    QString name = ui->name->text();
    QString year = ui->year->text();
    QString place = ui->place->text();
    QString opisaniye = ui->opisaniye->text();
    model->insertRow(model->rowCount());
    QSqlQuery query;
    query.prepare("INSERT INTO lib (Номер, Тип, Название, Год, Место выпуска, Описание) "
                               "VALUES (:number, Аудио, :name, :year, :place, :opisaniye )");
    query.bindValue(":number", number);
    query.bindValue(":name", name);
    query.bindValue(":year", year);
    query.bindValue(":place", place);
    query.bindValue(":opisaniye", opisaniye);
    query.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString number = ui->number->text();
    QString name = ui->name->text();
    QString year = ui->year->text();
    QString place = ui->place->text();
    QString opisaniye = ui->opisaniye->text();
    model->insertRow(model->rowCount());
    QSqlQuery query;
    query.prepare("INSERT INTO lib (Номер, Тип, Название, Год, Место выпуска, Описание) "
                               "VALUES (:number, :type, :name, :year, :place, :opisaniye )");
    query.bindValue(":number", number);
    query.bindValue(":type", "Видео");
    query.bindValue(":name", name);
    query.bindValue(":year", year);
    query.bindValue(":place", place);
    query.bindValue(":opisaniye", opisaniye);
    query.exec();
}

