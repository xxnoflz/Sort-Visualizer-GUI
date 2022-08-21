#include "SortVisualizerGUI.h"

SortVisualizerGUI::SortVisualizerGUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->Init();
}

SortVisualizerGUI::~SortVisualizerGUI() {
    delete collumns;
    delete sort;
}

void SortVisualizerGUI::Init() {
    connect(this->ui.startButton, &QPushButton::clicked, this, &SortVisualizerGUI::StartSort);

    collumns = new CollumnArrayObject();
    sort = new SortObject(ui.render, this->collumns);
}

void SortVisualizerGUI::StartSort() {
    collumns->SetData(ui.min_value_input->text().toInt(), ui.max_value_input->text().toInt());
    sort->SetType(ui.sort_type_input->currentText().toStdString());
    ui.render->SetSpeed(ui.speed_input->text().toInt());
    ui.render->SetCollumnObject(this->collumns);

    sort->Start();
}