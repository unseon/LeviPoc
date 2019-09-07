#ifndef QQUICKEDITORWIDGET_H
#define QQUICKEDITORWIDGET_H

#include <QWidget>
#include <QImage>

class MovieRenderer;

class QQuickEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QQuickEditorWidget(QWidget *parent = 0);
    ~QQuickEditorWidget();

public slots:
    void renderMovie();

private slots:
    void handleMovieFinished();
    void rendered(QImage *image);

private:
    MovieRenderer *m_movieRenderer;

protected:
    void paintEvent(QPaintEvent* event);

};

#endif // QQUICKEDITORWIDGET_H
