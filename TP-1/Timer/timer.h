#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QWidget {
    Q_OBJECT

public:
    // Constructor
    Timer(QWidget *parent = nullptr);

    // Destructor
    ~Timer();

private slots:
    void onTimerInterupt();
    void onSpeedChange();

private:
    Ui::Timer *ui;
    QTimer *timer;
};

#endif // TIMER_H
