#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FlappyBird;
}
QT_END_NAMESPACE

class FlappyBird : public QMainWindow
{
    Q_OBJECT

public:
    FlappyBird(QWidget *parent = nullptr);
    ~FlappyBird();

private:
    Ui::FlappyBird *ui;
};
#endif // FLAPPYBIRD_H
