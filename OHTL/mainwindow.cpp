#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <cmath>
#include <qdebug.h>
//Done By Alaa Essam
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;



}

void MainWindow::on_pushButton_clicked()
{
    float d1 = (ui->d1->toPlainText()).toDouble();
    float d2 = (ui->d2->toPlainText()).toDouble();
    float d3 = (ui->d3->toPlainText()).toDouble();
    float gmri = (ui->gmri->toPlainText()).toDouble();
    float r = (ui->r->toPlainText()).toDouble();

    if (this->ui->comboBox->currentIndex() == 0 && (this->ui->comboBox_2->currentIndex() ==0 ||this->ui->comboBox_2->currentIndex() ==1 )){
       ui->gmd->setText("GMD = "+ QString::number(d1) + "cm");
       ui->gmr->setText("GMR = "+ QString::number(r)+ "cm");
       ui->c->setText("C = "+ QString::number(0.0556/log(d1/r))+"μF/km");

    }else if (ui->comboBox->currentIndex() == 0 && ui->comboBox_2->currentIndex() == 2){
        ui->gmd->setText("GMD = "+ QString::number(pow((d1*d2*d3),0.3333)) + "cm");
        ui->gmr->setText("GMR = "+ QString::number(r)+ "cm");
        ui->c->setText("C = "+ QString::number(0.0556/log(pow((d1*d1*d3),0.33333)/r))+"μF/km");
    }else if (ui->comboBox->currentIndex() == 1 && (this->ui->comboBox_2->currentIndex() ==0 ||this->ui->comboBox_2->currentIndex() ==1 )){
        ui->gmd->setText("GMD = "+ QString::number(d1) + "cm");
        ui->gmr->setText("GMR = "+ QString::number(gmri)+ "cm");
        ui->c->setText("C = "+ QString::number(0.0556/log(d1/gmri))+"μF/km");
    }else if (ui->comboBox->currentIndex() == 1 && this->ui->comboBox_2->currentIndex() == 2){
        ui->gmd->setText("GMD = "+ QString::number(pow((d1*d1*d3),0.33333)) + "cm");
        ui->gmr->setText("GMR = "+ QString::number(gmri)+ "cm");
        ui->c->setText("C = "+ QString::number(0.0556/log(pow((d1*d1*d3),0.33333)/gmri))+"μF/km");
    }else if ((ui->comboBox->currentIndex()== 2 || ui->comboBox->currentIndex() == 3) && (ui->comboBox_2->currentIndex() == 0 || ui->comboBox->currentIndex()  == 1) ){
        if(ui->comboBox_5->currentIndex()==0){
            ui->gmd->setText("GMD = "+ QString::number(d1) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(r*pow(d1,0.5))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(d1/(r*pow(d1,0.5))))+"μF/km");
        }else if (ui->comboBox_5->currentIndex() ==1 ){
            ui->gmd->setText("GMD = "+ QString::number(d1) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(pow((r*pow(d1,2)),0.3333))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(d1/pow((r*pow(d1,2)),0.3333)))+"μF/km");
        }else if (ui->comboBox_5->currentIndex() ==2 ){
            ui->gmd->setText("GMD = "+ QString::number(d1) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(1.09*pow((r*pow(d1,3)),0.25))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(d1/1.09*pow((r*pow(d1,3)),0.25)))+"μF/km");
        }

    }else if ((ui->comboBox->currentIndex()== 2 || ui->comboBox->currentIndex() == 3)&&ui->comboBox_2->currentIndex()== 2){

        if(ui->comboBox_5->currentIndex()==0){
            ui->gmd->setText("GMD = "+ QString::number(pow((d1*d1*d3),0.33333)) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(r*pow(d1,0.5))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(pow((d1*d1*d3),0.33333)/(r*pow(d1,0.5))))+"μF/km");
        }else if (ui->comboBox_5->currentIndex() ==1 ){
            ui->gmd->setText("GMD = "+ QString::number(pow((d1*d1*d3),0.33333)) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(pow((r*pow(d1,2)),0.3333))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(pow((d1*d1*d3),0.33333)/pow((r*pow(d1,2)),0.3333)))+"μF/km");
        }else if (ui->comboBox_5->currentIndex() ==2 ){
            ui->gmd->setText("GMD = "+ QString::number(pow((d1*d1*d3),0.33333)) + "cm");
            ui->gmr->setText("GMR = "+ QString::number(1.09*pow((r*pow(d1,3)),0.25))+ "cm");
            ui->c->setText("C = "+ QString::number(0.0556/log(pow((d1*d1*d3),0.33333)/1.09*pow((r*pow(d1,3)),0.25)))+"μF/km");
        }
    }

}

void MainWindow::on_comboBox_currentIndexChanged(int)
{

}

void MainWindow::on_pushButton_3_clicked()
{
    double P = 0;
    double r = (ui->R->toPlainText()).toDouble();
    double Nb = (ui->q->toPlainText()).toDouble();
    double A= 0;
    double n=  (ui->layers->toPlainText()).toDouble();
    if (ui->material->currentIndex()==0){
         P=0.00000172;
         ui->p->setText("Resistivity = 1.72*10^-6");
    }else{

         P=0.00000265;
         ui->p->setText("Resistivity = 2.65*10^-6");

    } if (ui->comboBox_7->currentIndex()==0){
        A= 3.14*pow(r,2);
        ui->area->setText("Area = "+ QString::number(A) + "cm^2");
        ui->res->setText("Resistance = " + QString::number(P/A));

    }else if (ui->comboBox_7->currentIndex() == 1){
        ui->wires->setText("Num of wires = "+ QString::number(3*n*(n+1)+1));
        A= 3.14*pow(r,2)*(3*n*(n+1)+1);
        ui->area->setText("Area = "+ QString::number(A) + "cm^2");
        ui->res->setText("Resistance = " + QString::number(P/A));

    }else if (ui->comboBox_7->currentIndex()==2){
        A= 3.14*pow(r,2)*Nb;
        ui->area->setText("Area = "+ QString::number(A) + "cm^2");
        ui->res->setText("Resistance = " + QString::number(P/A));
  }else{

        ui->wires->setText("Num of wires = "+ QString::number(3*n*(n+1)+1));

        A= 3.14*pow(r,2)*Nb* (3*n*(n+1)+1);
        ui->area->setText("Area = "+ QString::number(A) + "cm^2");
         ui->res->setText("Resistance = " + QString::number(P/A));

    }

}

void MainWindow::on_material_currentIndexChanged(int index)
{
    if (ui->material->currentIndex()==0){
         //P=0.00000172;
         ui->p->setText("Resistivity = 1.72*10^-6");
    }else{

       //  P=0.00000265;
         ui->p->setText("Resistivity = 2.65*10^-6");

    }
}

void MainWindow::on_pushButton_7_clicked()
{
        float d1 = (ui->dis1->toPlainText()).toDouble();
        float d2 = (ui->dis2->toPlainText()).toDouble();
        float d3 = (ui->dis3->toPlainText()).toDouble();
        float GMRi = (ui->gmrii->toPlainText()).toDouble();
        float spacing = (ui->spacing->toPlainText()).toDouble();
        float r = (ui->rad->toPlainText()).toDouble();
    if(ui->comboBox_9->currentIndex()==0){
        if (ui->comboBox_10->currentIndex()==0){
            float GMD = d1;
            float GMR = r*qExp(qreal(-0.25));
            qDebug()<<GMR;

            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }else if (ui->comboBox_10->currentIndex()==1){
            float GMD = d1;
            float GMR = r*qExp(qreal(-0.25));
            qDebug()<<GMR;
            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }else if (ui->comboBox_10->currentIndex() == 2){
            float GMD = pow(d1*d2*d3,0.3333);
            float GMR = r*qExp(qreal(-0.25));
            qDebug()<<GMR;
            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }
    }else if (ui->comboBox_9->currentIndex()==2){
        if (ui->comboBox_10->currentIndex()==0){
            float GMD = d1;
            float GMR = GMRi;
            qDebug()<<GMR;
            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }else if (ui->comboBox_10->currentIndex()==1){
            float GMD = d1;
            float GMR = GMRi;
            qDebug()<<GMR;
            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }else if (ui->comboBox_10->currentIndex() == 2){
            float GMD = pow(d1*d2*d3,0.3333);
            float GMR = GMRi;
            qDebug()<<GMR;
            ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
            ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
            ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
        }
    }else if (ui->comboBox_9->currentIndex() == 3){
        if (ui->comboBox_10->currentIndex()==0){
            if (ui->cb->currentIndex() == 0){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = pow(ds*d,0.5);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            } else if (ui->cb->currentIndex() == 1){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = pow(ds*pow(d,2),0.3333);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            }else if (ui->cb->currentIndex() == 2){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = 1.09*pow(ds*pow(d,3),0.25);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            }else  if (ui->comboBox_10->currentIndex()==1){
                if (ui->cb->currentIndex() == 0){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = pow(ds*d,0.5);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                } else if (ui->cb->currentIndex() == 1){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = pow(ds*pow(d,2),0.3333);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                }else if (ui->cb->currentIndex() == 2){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = 1.09*pow(ds*pow(d,3),0.25);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                }else if (ui->comboBox_10->currentIndex()==2){
                    if (ui->cb->currentIndex() == 0){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = pow(ds*d,0.5);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    } else if (ui->cb->currentIndex() == 1){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = pow(ds*pow(d,2),0.3333);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    }else if (ui->cb->currentIndex() == 2){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = 1.09*pow(ds*pow(d,3),0.25);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    }
                }
            }
        }
    }else if (ui->comboBox_9->currentIndex()==4){
        if (ui->comboBox_10->currentIndex()==0){
            if (ui->cb->currentIndex() == 0){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = pow(ds*d,0.5);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            } else if (ui->cb->currentIndex() == 1){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = pow(ds*pow(d,2),0.3333);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            }else if (ui->cb->currentIndex() == 2){
                float GMD = d1;
                float ds = r*qExp(qreal(-0.25));
                float d= spacing;
                float GMR = 1.09*pow(ds*pow(d,3),0.25);
                qDebug()<<GMR;
                ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                ui->i->setText("I = "+ QString::number(0.2*log(GMD/GMR)*2)+"mH/km");
                ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
            }else  if (ui->comboBox_10->currentIndex()==1){
                if (ui->cb->currentIndex() == 0){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = pow(ds*d,0.5);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                } else if (ui->cb->currentIndex() == 1){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = pow(ds*pow(d,2),0.3333);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                }else if (ui->cb->currentIndex() == 2){
                    float GMD = d1;
                    float ds = r*qExp(qreal(-0.25));
                    float d= spacing;
                    float GMR = 1.09*pow(ds*pow(d,3),0.25);
                    qDebug()<<GMR;
                    ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                    ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                    ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                }else if (ui->comboBox_10->currentIndex()==2){
                    if (ui->cb->currentIndex() == 0){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = pow(ds*d,0.5);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    } else if (ui->cb->currentIndex() == 1){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = pow(ds*pow(d,2),0.3333);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    }else if (ui->cb->currentIndex() == 2){
                        float GMD = pow(d1*d2*d3,0.3333);
                        float ds = r*qExp(qreal(-0.25));
                        float d= spacing;
                        float GMR = 1.09*pow(ds*pow(d,3),0.25);
                        qDebug()<<GMR;
                        ui->GMD->setText("GMD = "+ QString::number(GMD) + "cm");
                        ui->GMR->setText("GMR = "+ QString::number(GMR)+ "cm");
                        ui->L->setText("C = "+ QString::number(0.2*log(GMD/GMR))+"mH/km");
                    }
                }
            }
        }

    }
}
