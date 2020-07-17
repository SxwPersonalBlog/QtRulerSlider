#ifndef RULERSLIDER_H
#define RULERSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include  <QRect>
#include  <QScreen>
#include  <QGuiApplication>

#define SMALL_Y 5 //小刻度
#define MIDDLE_Y 7 //中刻度
#define BIG_Y 10  //大刻度

#define DIFFERVALUE 1 //最小差值(最大值与最小值的差)
#define SIDEDISTANCE 10 //尺子距离左边的距离
#define SIDEDISTANCER 50 //尺子距离右边的距离
#define HANDLEWIDTH 10 //滑块的宽度
#define HANDLEHEIGHT 15 //滑块的高度
#define MININTERVSL 10 //最小刻度之间距离
#define MAXINTERVSL 20 //最大刻度之间距离

#define DISTANCEMOUSE 20 //鼠标悬停距离箭头的位置

class RulerSlider : public QSlider
{
public:
    RulerSlider(QWidget *parent = nullptr);
    ~RulerSlider();
    //刻度之间的距离
    qreal sliderInterval = 1;
    //显示刻度值
    QLabel *valueLabel;
    //滑块
    QLabel *handleLabel;
    //鼠标是否点击
    bool mouseIsClick = false;
    //设置控件的范围
    void setRulerSliderRange(int min,int max);
    //设置当前值
    void setRulerSliderValue(int value);
private:
    //绘制尺子背景
    void drawRulerBackgroud(QPainter *painter);
    //绘制刻度线与值
    void drawSliderMark(QPainter *painter);
    //根据坐标位置计算当前值
    void eventPosGetValue(QMouseEvent *ev);
    //鼠标事件
    void mouseFilterEvent(QMouseEvent *event);
protected:
    //重新绘制
    void paintEvent(QPaintEvent *);
    //过滤器
    bool eventFilter(QObject *watched,QEvent *event);
};

#endif // RULERSLIDER_H
