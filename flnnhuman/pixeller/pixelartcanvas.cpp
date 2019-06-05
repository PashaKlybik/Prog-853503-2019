#include "pixelartcanvas.h"
#include <QDebug>
#include <tools.h>

PixelArtCanvas::PixelArtCanvas(std::vector<PixelImage*>  *frames, int *frameIndex, int *toolSelection, QWidget *parent) {
    this->frames = frames;
    this->frameIndex = frameIndex;
    this->toolSelection = toolSelection;
    scene = new QGraphicsScene();
    setScene(scene);
    setSceneRect(scene->sceneRect());
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("background: transparent; border: transparent;");

    borderPen = new QPen("#000000");
    borderPen->setWidth(10);
    borderPen->setCapStyle(Qt::SquareCap);
    borderPen->setJoinStyle(Qt::MiterJoin);

    noPen = new QPen(Qt::NoPen);
    noBrush = new QBrush(Qt::NoBrush);

    render(true);
}

void PixelArtCanvas::scrollContentsBy(int, int)
{

}

void PixelArtCanvas::setPalette(Palette *p) {
    palette = p;
}

void PixelArtCanvas::setImageSequence(ImageSequence *sequence) {
    imageSequence = sequence;
}

int PixelArtCanvas::getWidth() {
    return row_count * cellSize + borderSize*2;
}

int PixelArtCanvas::getHeight() {
    return col_count * cellSize + borderSize*2;
}

PixelArtCanvas::~PixelArtCanvas() {
    delete scene;
    delete borderPen;
    delete noPen;
    delete noBrush;
}

void PixelArtCanvas::mousePressEvent(QMouseEvent * e) {

    if (isMousePressed) {
        return;
    }

    int yOffset = 10;
    int xOffset = 10;

    int x = e->pos().x() - xOffset;
    x /= cellSize;
    x %= col_count;

    int y = e->pos().y() - yOffset;
    y /= cellSize;

    int selectionIndex = x + y * col_count;

    if (*toolSelection == Tools::Eraser) {
        frames->at(*frameIndex)->canvasColors[selectionIndex]->setRgba(qRgba(5,100,44,0));}
    else
{
    if (*toolSelection == Tools::Fill) {
        int x = selectionIndex % col_count;
        int y = selectionIndex / row_count;
        QColor *color = frames->at(*frameIndex)->canvasColors[selectionIndex];
        int colorIndex = x + y * col_count;
        QColor *nextColor = frames->at(*frameIndex)->canvasColors[colorIndex];

        if (nextColor->name() != color->name()) {
            return;

        }
        else {
          doFloodFill(x, y, *color);
        }

    } else {
        QColor selectedColor = palette->getSelectedColor();
        frames->at(*frameIndex)->canvasColors[selectionIndex]->setNamedColor(selectedColor.name());
    }
}
    render(true);
    isMousePressed = true;
    imageSequence->render(false);
}

void PixelArtCanvas::mouseReleaseEvent(QMouseEvent * e) {
    isMousePressed = false;
}

void PixelArtCanvas::mouseDoubleClickEvent(QMouseEvent * e) {

}

void PixelArtCanvas::mouseMoveEvent(QMouseEvent * e) {

    if (*toolSelection == Tools::Fill) {
        return;
    }

    if (!isMousePressed) {
        return;
    }

    int yOffset = 10;
    int xOffset = 10;

    int minMove = 5;

    int xChange = abs(lastMousePosX - e->pos().x());
    int yChange = abs(lastMousePosY - e->pos().y());

    if (xChange < minMove && yChange < minMove) {
        return;
    }

    lastMousePosX = e->pos().x();
    lastMousePosY = e->pos().y();

    int x = e->pos().x() - xOffset;
    x /= cellSize;
    x %= col_count;

    int y = e->pos().y() - yOffset;
    y /= cellSize;

    selectionIndex = x + y * col_count;

    QColor selectedColor = palette->getSelectedColor();
    if (selectionIndex > col_count * row_count) {
        selectionIndex = 0;
    }
    if (*toolSelection == Tools::Eraser) {
       frames->at(*frameIndex)->canvasColors[selectionIndex]->setRgba(qRgba(5,100,44,0));
    } else {
frames->at(*frameIndex)->canvasColors[selectionIndex]->setNamedColor(selectedColor.name());
}
    render(true);
    imageSequence->render(true);
}

void PixelArtCanvas::render(bool all) {

    if (frames->size() == 0) {
        return;
    }


    if (all) {
        scene->clear();
        for (int i = 0; i < frames->at(*frameIndex)->canvasColors.size(); i++) {
            int x = i % col_count;
            int y = i / row_count;
            QColor *color = frames->at(*frameIndex)->canvasColors[i];
            QBrush brush(*color);
            scene->addRect(QRect((x*cellSize) + borderSize/2,(y*cellSize) + borderSize/2,cellSize,cellSize), *noPen, brush);
        }
    } else {
        int x = selectionIndex % col_count;
        int y = selectionIndex / row_count;
        QColor *color = frames->at(*frameIndex)->canvasColors[selectionIndex];
        QBrush brush(*color);
        scene->addRect(QRect((x*cellSize) + borderSize/2,(y*cellSize) + borderSize/2,cellSize,cellSize), *noPen, brush);
        if (imageSequence) {
            imageSequence->render(false);
        }
    }
    scene->addRect(QRect(0.0, 0.0, cellSize*col_count + borderSize, cellSize*row_count + borderSize), *borderPen, *noBrush);
}

void PixelArtCanvas::doFloodFill(int x, int y, QColor color) {


    if (x < 0 || x >= col_count || y < 0 || y >= row_count) {
        return;
    }

    int colorIndex = x + y * col_count;



    QColor *nextColor = frames->at(*frameIndex)->canvasColors[colorIndex];

    if (nextColor->name() != color.name()) {
        return;

    }

    frames->at(*frameIndex)->canvasColors[colorIndex]->setNamedColor(palette->getSelectedColor().name());
    doFloodFill(x+1, y, color);
    doFloodFill(x-1, y, color);
    doFloodFill(x, y+1, color);
    doFloodFill(x, y-1, color);
}


