#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "palette.h"
#include "pixelartcanvas.h"
#include "imagesequence.h"
#include "moviescreen.h"
#include "tools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void createInterface();
    
public slots:
    void createNew();
    void openFile();
    void doExport();
    void play();
    void stop();
    void addImage();
    void save();

private:
    QString getLastOpenedFileName();
    void saveLastOpenedFileName();
    void loadFile(QString filename);
    void styleButton(QPushButton *button, QFont &font);
    void write(QJsonObject &json);
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    PixelArtCanvas *pixelArtCanvas;
    Palette *palette;
    ImageSequence *imageSequence;
    MovieScreen *movieScreen;
    Tools *tools;

    QPushButton *newFileButton;
    QPushButton *openButton;
    QPushButton *exportButton;
    QPushButton *addFrameButton;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *saveButton;
    std::vector<PixelImage*> frames;
    int frameIndex = 0;
    QString fileName;
    int toolSelection;
    const QString lastOpenedReferenceFilename = "previous.json";
};

#endif // MAINWINDOW_H
