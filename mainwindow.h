/* mainwindow.h
 * by Anon TG
 * Last modification: 9/27/2020
 *
 * WHAT THIS DUMB PIECE OF SHIT DOES:
 * Provides UI for the main window.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <deque>

#include "promptGen.h"

const size_t MAX_DEQUE_SIZE = 32;      // Change this if you want your history to bigger. You can probably get away with pretty huge numbers these days...

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);      // Default constructor. Does some QT shit man, fuck why you always gotta ask me man, like fuck man idk
    ~MainWindow();                              // Default destructor. Deletes ui or some shit...

private slots:
    void on_createPrompt_clicked();             // Creates a prompt.

    void on_pushButton_2_clicked();             // Exit the program.

    void on_pushButton_clicked();               // Undo this prompt (go to last prompt). Deletes current one.

    void on_pushButton_3_clicked();             // Clear the prompt history.

private:
    Ui::MainWindow *ui;

    prompt p;                       //  p           :   prompt.......................Prompt handler.
    std::deque<QString*> dq;        //  dq          :   deque<QString*>..............History. Max size is 32 to prevent stack overflow. SEE const size_t MAX_DEQUE_SIZE above tho.
};

#endif // MAINWINDOW_H
