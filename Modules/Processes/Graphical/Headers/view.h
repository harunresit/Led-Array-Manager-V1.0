#ifndef VIEW_H
#define VIEW_H

#include <QFrame>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QLabel;
class QSlider;
class QToolButton;
QT_END_NAMESPACE

class View;

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(View *v) : QGraphicsView(), view(v) { }
protected:
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *) override;
    ///Added
    //void mousePressEvent(QMouseEvent *event) override;
    ///
#endif

private:
    View *view;
};

class View : public QFrame
{
    Q_OBJECT
public:
    explicit View(const QString &name, QWidget *parent = 0);

    QGraphicsView *view() const;

    ///Added
    bool ledAddable = false;
    int indis = 0;
    int ticknumber = 0;
    int tickindisextra = 0;
    bool tickorder = 0;
    ///

    bool modeAnim();

signals:
    void sendAnimSignal();
    void stopAnimSignal();
    void triggerTimeLineMenu();

public slots:
    void zoomIn(int level = 1);
    void zoomOut(int level = 1);

private slots:
    void resetView();
    void setResetButtonEnabled();
    void setupMatrix();
    void togglePointerMode();
    void toggleOpenGL();
    void toggleAntialiasing();
    void print();
    void rotateLeft();
    void rotateRight();
    void animationStart();
    void animationStop();
    void animSetMode();

private:
    GraphicsView *graphicsView;
    QLabel *label;
    QLabel *label2;
    QToolButton *selectModeButton;
    QToolButton *dragModeButton;
    QToolButton *animationaddModeButton;
    QToolButton *startAnimationButton;
    QToolButton *stopAnimaitonButton;
    ///Added
    //QToolButton *ledAddButton;
    ///
    QToolButton *openGlButton;
    QToolButton *antialiasButton;
    QToolButton *printButton;
    QToolButton *resetButton;
    QSlider *zoomSlider;
    QSlider *rotateSlider;

};

#endif // VIEW_H
