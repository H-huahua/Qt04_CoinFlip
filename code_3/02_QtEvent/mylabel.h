#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入事件：
    void enterEvent(QEvent * event);

    //鼠标离开事件：
    void leaveEvent(QEvent *);

    //鼠标的按下
    void mousePressEvent(QMouseEvent *ev);
    //鼠标的释放
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标的移动
    void mouseMoveEvent(QMouseEvent *ev);

    //通过event事件分发器拦截鼠标按下事件：
    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
