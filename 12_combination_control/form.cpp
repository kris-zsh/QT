#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    void (QSpinBox::*change_value)(int) = &ui->spinBox->valueChanged;
    connect(ui->spinBox, change_value, [=](int num){
        ui->horizontalSlider->setValue(num);
    });

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int num){
        ui->spinBox->setValue(num);
    });

}

Form::~Form()
{
    delete ui;
}

void Form::setValue(int num)
{
    ui->horizontalSlider->setValue(num);
}

int Form::getValue()
{
    return ui->horizontalSlider->value();
}
