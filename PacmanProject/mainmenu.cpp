#include "mainmenu.h"
#include "ui_mainmenu.h"

mainMenu::mainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainMenu){
    ui->setupUi(this);
}

mainMenu::~mainMenu(){
    delete ui;
}
