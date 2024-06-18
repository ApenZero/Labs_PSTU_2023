#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Add_Node_Btn, SIGNAL(clicked()),this,SLOT(Add_node()));
    connect(ui->Add_Edge_Btn, SIGNAL(clicked()), this,SLOT(Add_edge()));
    connect(ui->Width_traversal_Btn, SIGNAL(clicked()), this, SLOT(Width_traversal()));
    connect(ui->Deep_crawl_Btn, SIGNAL(clicked()), this, SLOT(Deep_crawl()));
    connect(ui->Dijkstra_Btn, SIGNAL(clicked()), this, SLOT(Dijkstra_algorithm()));

    graphicsView = ui -> graphicsView;
    scene = new QGraphicsScene;
    graphicsView -> setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Add_node(){
    graph.Add_Vertice();
    QString node = QString("%1").arg(graph.Get_matrix_size()-1);
    QGraphicsEllipseItem *ellipse = scene->addEllipse(640, 275, 50, 50, QPen(Qt::black), QBrush(Qt::lightGray));
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsTextItem *textItem = scene->addText(node);
    textItem->setPos(ellipse->boundingRect().center().x() - textItem->boundingRect().width() / 2,
                     ellipse->boundingRect().center().y() - textItem->boundingRect().height() / 2);
    textItem->setParentItem(ellipse);
    scene->installEventFilter(this);
    ellipses.push_back(ellipse);
}
void MainWindow::Add_edge(){
    if((ui->Output_lineEdit->text() == "") or (ui->Input_lineEdit->text() == "") or (ui->weight_lineEdit->text() =="")){
        qDebug() << "Не все поля заполнены";
        return;
    }
    int out = (ui->Output_lineEdit->text()).toInt();
    int in = (ui->Input_lineEdit->text()).toInt();
    int weight = (ui->weight_lineEdit->text()).toInt();
    if(out < 1 or in < 1 or weight < 1){
        qDebug() << "ни какое из значений не может быть меньше единицы";
        return;
    }
    if(graph.Get_matrix_size()-1 < out or graph.Get_matrix_size()-1 < in){
        qDebug() << "Таких(ой) вершин(ы) нет";
        return;
    }
    graph.Add_Edge(out, in, weight);
    Print_edge(out, in, weight);
}
void MainWindow::Print_edge(int ou, int inn, int we){
    if(we == 0){
        return;
    }
    int out = ou;
    int in = inn;
    int weight = we;


    if(in != out){                        //стрелка
        QGraphicsEllipseItem *out_ellipse = ellipses[out];
        QGraphicsEllipseItem *in_ellipse = ellipses[in];

        QPointF center1 = out_ellipse->mapToScene(out_ellipse->boundingRect().center());
        QPointF center2 = in_ellipse->mapToScene(in_ellipse->boundingRect().center());


        qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());

        QPointF new_out(center1.x() + 25 * qCos(angle), center1.y() + 25 * qSin(angle));
        QPointF new_in(center2.x() + 25 * qCos(angle + M_PI), center2.y() + 25 * qSin(angle + M_PI));

        QGraphicsLineItem *line1 = new QGraphicsLineItem();
        line1->setLine(QLineF(new_out, new_in));
        scene->addItem(line1);

        QPolygonF arrowHead;

        qreal angle_arrow = qAtan2(new_in.y() - new_out.y(), new_in.x() - new_out.x());
        qreal arrowLength = 10.0;

        qreal arrowAngle = M_PI / 6.0;

        QPointF arrowP1 = new_in - QPointF(arrowLength * std::cos(angle_arrow + arrowAngle), arrowLength * std::sin(angle_arrow + arrowAngle));
        QPointF arrowP2 = new_in - QPointF(arrowLength * std::cos(angle_arrow - arrowAngle), arrowLength * std::sin(angle_arrow - arrowAngle));

        arrowHead << new_in << arrowP1 << arrowP2;

        QGraphicsPolygonItem *arrow1 = new QGraphicsPolygonItem(arrowHead);
        arrow1->setBrush(Qt::black);
        arrow1->setPen(Qt::NoPen);
        scene->addItem(arrow1);

        QPointF textPos2 = arrowP2;
        QGraphicsTextItem* textItem2 = scene->addText(QString::number(weight));
        textItem2->setPos(textPos2);

        QList<QGraphicsItem*> items;
        items << arrow1 << textItem2 <<line1;
        QGraphicsItemGroup *group = scene->createItemGroup(items);
        arrows.push_back(group);

        out_ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
        in_ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
    }

    if(in == out){                                      //петля
         QGraphicsEllipseItem *ellipse = ellipses[out];

         QPointF center = ellipse->mapToScene(ellipse->boundingRect().center());

         qreal radius = ellipse->boundingRect().width() / 2.0;

         qreal angle_loop = 45 * M_PI / 180;

         QPointF start(center.x() + radius * qCos(angle_loop), center.y() + radius * qSin(angle_loop));
         QPointF end(center.x() + radius * qCos(angle_loop + M_PI), center.y() + radius * qSin(angle_loop + M_PI));

         radius *= 4;

         QPointF controlPoint1(center.x() + radius * qCos(angle_loop - M_PI / 4), center.y() + radius * qSin(angle_loop - M_PI / 4));
         QPointF controlPoint2(center.x() + radius * qCos(angle_loop + M_PI + M_PI / 4), center.y() + radius * qSin(angle_loop + M_PI + M_PI / 4));

         QPainterPath loopPath;
         loopPath.moveTo(start);
         loopPath.cubicTo(controlPoint1, controlPoint2, end);
         scene->addPath(loopPath);


         QPointF textPos2(center.x() + radius * qCos(angle_loop + M_PI + M_PI / 4), center.y() + 25 + radius * qSin(angle_loop + M_PI + M_PI / 4));
         QGraphicsTextItem* textItem2 = scene->addText(QString::number(weight));
         textItem2->setPos(textPos2);

         QGraphicsPathItem *loopItem = new QGraphicsPathItem(loopPath);

         QList<QGraphicsItem*> items;
         items << loopItem << textItem2;
         QGraphicsItemGroup *group = scene->createItemGroup(items);
         arrows.push_back(group);


         ellipse->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}

void MainWindow::Width_traversal(){
    ui->Output_algoritms->clear();
    int start = (ui->Wide_lineEdit->text()).toInt();
    std::vector<int> BFS;
    BFS = graph.BFS(start);
    QString result;
    for(int i = 0; i < BFS.size();i++){
        result.append(QString::number(BFS[i]));
        if (i < BFS.size()){
            result.append(", ");
        }
    }
    ui->Output_algoritms->setText(result);
}
void MainWindow::Deep_crawl(){
    ui->Output_algoritms->clear();
    int start = (ui->Deep_lineEdit->text()).toInt();
    std::vector<int> DFS;
    DFS = graph.DFS(start);
    QString result;
    for(int i = 0; i < DFS.size();i++){
        result.append(QString::number(DFS[i]));
        if (i < DFS.size()){
            result.append(", ");
        }
    }
    ui->Output_algoritms->setText(result);
}
void MainWindow::Dijkstra_algorithm(){
    ui->Output_algoritms->clear();
    int start = (ui->Dijkstra_start_lineEdit->text()).toInt();
    int end = (ui->Dijkstra_end_lineEdit->text()).toInt();
    std::vector<int> D;
    D = graph.Dijkstra(start, end);
    QString result;
    for(int i = D.size()-2; i > 0; i--){
        if(D[i]!=0){
            result.append(QString::number(D[i]));
            if (i > 0 + 1){
                result.append("->");
            }
        }
    }
    result.append(" Answer = ");
    result.append(QString::number(D[D.size()-1]));
    ui->Output_algoritms->setText(result);
}
