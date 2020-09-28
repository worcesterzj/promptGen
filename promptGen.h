/* promptGen.h
 * by Anon TG
 * Last modification: 9/27/2020
 *
 * WHAT THIS DUMB PIECE OF SHIT DOES:
 * Provides a prompt, as well as a method of generating said prompt,
 * and a method of reading in more options for said said prompt from a file.
*/

#ifndef PROMPTGEN_H
#define PROMPTGEN_H

#include <QString>
#include <QObject>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QMessageBox>

#include <vector>
#include <iostream>


const QString YOUARE = ">You are some sort of:\n";
const QString WHOMUST = ">And you must:\n";
const QString BY = ">You will achieve this by:\n";
const QString SOTHAT = ">So that you may:\n";

class prompt{
public:
    prompt();                                       // Default constructor.

    ~prompt() {/* look at me I'm a worthless piece  // little baby destructor don't do nothing waa waa
                  of absolute shit.*/ }

    void generatePrompt();                          // Generate a prompt. Duh.

    const QString& getText() const;                 // Get yo shit

private:
    QString text;                                   // text     :   QString................The text to be displayed in the prompt.

    std::vector<QString*> youare;                   // youare   :   vector<QString*>.......Vector of prompt options for the >You Are part.
    std::vector<QString*> youmust;                  // youmust  :   vector<QString*>.......Vector of prompt options for the >You Must part.
    std::vector<QString*> by;                       // by       :   vector<QString*>.......Vector of prompt options for the >By Doing part.
    std::vector<QString*> sothat;                   // sothat   :   vector<QString*>.......Vector of prompt options for the >So That part.

};

#endif // PROMPTGEN_H
