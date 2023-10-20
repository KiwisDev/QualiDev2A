#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent) : QWidget(parent), ui(new Ui::Timer) {
    ui->setupUi(this);

    // Spin box
    ui->spinBox->setMaximum(999);

    // Progress bar setup
    ui->progressBar->setMaximum(1000);
    onTimerInterupt();

    // Button setup
    ui->mediumButton->setChecked(true);
    connect(ui->slowButton, SIGNAL(clicked()), this, SLOT(onSpeedChange()));
    connect(ui->mediumButton, SIGNAL(clicked()), this, SLOT(onSpeedChange()));
    connect(ui->fastButton, SIGNAL(clicked()), this, SLOT(onSpeedChange()));

    // Timer setup
    this->timer = new QTimer();
    this->onSpeedChange();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimerInterupt()));
    this->timer->start();
}

Timer::~Timer() {
    delete timer;
    delete ui;
}

void Timer::onTimerInterupt() {
    int value = ui->spinBox->value();
    ++value;
    ui->spinBox->setValue(value);
    ui->progressBar->setValue(value%1000);
}

void Timer::onSpeedChange() {
    if(ui->slowButton->isChecked()) {
        this->timer->setInterval(2000);
    }else if(ui->mediumButton->isChecked()) {
        this->timer->setInterval(1000);
    }else if(ui->fastButton->isChecked()) {
        this->timer->setInterval(10);
    }
}
