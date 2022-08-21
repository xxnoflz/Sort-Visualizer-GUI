#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SortVisualizerGUI.h"

#include "SortVisualizer/Objects/SortObject.h"
#include "SortVisualizer/Objects/CollumnArrayObject.h"

class SortVisualizerGUI : public QMainWindow {
    Q_OBJECT
public:
    SortVisualizerGUI(QWidget *parent = nullptr);
    ~SortVisualizerGUI();
public slots:
    void StartSort();
private:
    void Init();
private:
    Ui::SortVisualizerGUIClass ui;

    CollumnArrayObject* collumns;
    SortObject* sort;
};
