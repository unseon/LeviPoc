#include "qquickeditorwidget.h"
#include "movierenderer.h"

#include <QPainter>


QQuickEditorWidget::QQuickEditorWidget(QWidget* parent)
    : QWidget(parent)
    , m_movieRenderer(new MovieRenderer)
{
    connect(m_movieRenderer, SIGNAL(finished()), this, SLOT(handleMovieFinished()));
}

QQuickEditorWidget::~QQuickEditorWidget()
{
    delete m_movieRenderer;
}

void QQuickEditorWidget::renderMovie()
{


    //Star Render
    m_movieRenderer->renderMovie("/Users/unseon/github/LeviPoc/RenderControlExercise/main.qml", "output.png",
                                 ".", "png",
                                 QSize(100, 100), 1.0,
                                 0, 0);

}

void QQuickEditorWidget::handleMovieFinished()
{

}

void QQuickEditorWidget::rendered(QImage *image)
{

}

void QQuickEditorWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, m_movieRenderer->image());
}
