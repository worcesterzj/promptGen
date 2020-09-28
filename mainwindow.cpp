/* mainwindow.cpp
 * by Anon TG
 * Last modification: 9/27/2020
 *
 * WHAT THIS DUMB PIECE OF SHIT DOES:
 * Implementation of class f(x)s found in mainwindow.h
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createPrompt_clicked()
{
    /************************************************
     *
     * 1) If the deque has reached its maximum size,
     *    pop_front() to clear up some space.
     * 2) Add the current prompt being displayed to
     *    the "history" deque, dq.
     * 3) Generate a new prompt.
     * 4) Change the text in the window to the new
     *    prompt's text.
     *
     ************************************************/

    if(dq.size() >= MAX_DEQUE_SIZE)
        dq.pop_front();
    dq.push_back(new QString(ui->plainTextEdit->toPlainText()));
    p.generatePrompt();

    ui->plainTextEdit->setPlainText(p.getText());

}

void MainWindow::on_pushButton_2_clicked()
{
    // Pretty self explanatory desu
    qApp->exit(); // WHAT COULD THIS FUNCTION POSSIBLY DO?
}

void MainWindow::on_pushButton_clicked()
{
    /************************************************
     *
     * 1) Check if the deque is empty.
     *   If so:
     *    a) Clear the text field to flush out un-
     *       -wanted ghost text.
     *    b) Infrom the user that there is no
     *       operation to complete on this data
     *       structure.
     *   Else:
     *    a) Clear the text field to flush out ghost
     *       text. Boo!
     *    b) Replace the text field with the last
     *       string on the deque.
     *    c) Pop the last item on the deque so it
     *       does not cause problems later.
     *
     ************************************************/

    if(dq.empty()){
        ui->plainTextEdit->clear();
        QMessageBox::information(this, "No more!", "There is nothing left to undo.", QMessageBox::StandardButtons(QMessageBox::Ok));
    }
    else{
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(*dq.back());
        dq.pop_back();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    /************************************************
     *
     * 1) Check if deque is empty. Only cares about
     *    the last bit... pretty cool huh?
     *  If not:
     *    a) Ask the user if they want to kill all of
     *       the refugees in the deque.
     *    b) If they say "Ok" then... kill them.
     *  Else:
     *    a) Tell the user he/she's a retard.
     *
     ************************************************/

    if (dq.size()){
        QMessageBox::StandardButton warn = QMessageBox::information(this, "Are you sure?", "This will delete the prompt history, including the current one.", QMessageBox::StandardButtons(QMessageBox::Ok | QMessageBox::No));

        if(warn == QMessageBox::StandardButton::Ok){
            dq.clear();
            ui->plainTextEdit->clear();
        }
    }
    else
        QMessageBox::question(this, "What are you doing?", "There is nothing to clear.", QMessageBox::StandardButtons(QMessageBox::Ok));
}
