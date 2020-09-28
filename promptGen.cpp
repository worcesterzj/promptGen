/* promptGen.cpp
 * by Anon TG
 * Last modification: 9/27/2020
 *
 * WHAT THIS DUMB PIECE OF SHIT DOES:
 * Implementation of class f(x)s found in promptGen.h
*/

#include "promptGen.h"

prompt::prompt() {
    // Default Constructor takes all of the default prompts (hard-coded, below) and throws them into
    // a vector. That vector is used in generatePrompt() to... generate a prompt...

    // Default youare prompts
    youare.push_back(new QString("Knight"));
    youare.push_back(new QString("Spaceman"));
    youare.push_back(new QString("Wizard"));
    youare.push_back(new QString("Rogue"));
    youare.push_back(new QString("Punch Master"));
    youare.push_back(new QString("Reptillian"));

    // Default youmust prompts
    youmust.push_back(new QString("Save the princess"));
    youmust.push_back(new QString("Solve a mystery"));
    youmust.push_back(new QString("Slay the Dragon"));
    youmust.push_back(new QString("Master THAT technique"));
    youmust.push_back(new QString("Eat"));
    youmust.push_back(new QString("Steal something valuable"));

    // Default by prompts
    by.push_back(new QString("Wielding the Sacred Sword of the Knights Templar"));
    by.push_back(new QString("Piloting a prototype robot with a unique ability"));
    by.push_back(new QString("Mastering THE DANCE"));
    by.push_back(new QString("Using an advanced set of tools only you know how to use"));
    by.push_back(new QString("Burning a lot of shit"));
    by.push_back(new QString("Only using your wits and the things available to you on the street"));

    // Default sothat prompts
    sothat.push_back(new QString("Become King"));
    sothat.push_back(new QString("Get your kids back from the feds"));
    sothat.push_back(new QString("Make peace with your estranged brother"));
    sothat.push_back(new QString("Convince an interdimensional giant not to destroy reality"));
    sothat.push_back(new QString("Win the heart of a powerful sorceress who wants to use her magic to please you"));
    sothat.push_back(new QString("Spread your lizardman seed into the fertile swamps during mating season"));


    /************************************************
     *         FOR EACH PROMPT FILE INCLUDING:
     *      - youare.txt
     *      - youmust.txt
     *      - bydoing.txt
     *  and - sothat.txt
     *
     * 1) Declare a QFile that points to the
     *    filename.
     * 2) Declare a QTextSTream that reads in from
     *    the QFile.
     * 3) Open the QFile with READONLY and TEXT
     *    flags, check if successful.
     *   If Not:
     *    a) Say somewhere "I suck!"
     *   Else:
     *    a) While not at the end of file, add the
     *       current line to the respective vector.
     *    b) Close the file.
     *
     ************************************************/

  // READ IN: >You Are prompt begins here.

    QFile you_are("youare.txt");
    QTextStream arein(&you_are);

    if (!you_are.open(QIODevice::ReadOnly | QIODevice::Text))
        std::clog << "No youare.txt file found!\n";
    else{
        while (!arein.atEnd())
            youare.push_back(new QString(arein.readLine()));

        you_are.close();
    }

  // READ IN: >You Must prompt begins here.

    QFile you_must("youmust.txt");
    QTextStream mustin(&you_must);

    if (!you_must.open(QIODevice::ReadOnly | QIODevice::Text))
        std::clog << "No youmust.txt file found!\n";
    else{
        while (!mustin.atEnd())
            youmust.push_back(new QString(mustin.readLine()));

        you_must.close();
    }

  // READ IN: >By Doing prompt begins here.

    QFile by_doing("bydoing.txt");
    QTextStream doin(&by_doing);

    if (!by_doing.open(QIODevice::ReadOnly | QIODevice::Text))
        std::clog << "No bydoing.txt file found!\n";
    else{
        while (!doin.atEnd())
            by.push_back(new QString(doin.readLine()));

        by_doing.close();
    }

  // READ IN: >So That prompt begins here.

    QFile so_that("sothat.txt");
    QTextStream soin(&so_that);

    if (!so_that.open(QIODevice::ReadOnly | QIODevice::Text))
        std::clog << "No sothat.txt file found!\n";
    else{
        while (!soin.atEnd())
            sothat.push_back(new QString(soin.readLine()));

        so_that.close();
    }
}

void prompt::generatePrompt()  {

    // First the program generates 4 random numbers (using the QRandomGenerator engine) from 0 to vector::size() of the vector.

    int are = QRandomGenerator::global()->bounded(0, int(youare.size()));
    int mst = QRandomGenerator::global()->bounded(0, int(youmust.size()));
    int byd = QRandomGenerator::global()->bounded(0, int(by.size()));
    int sot = QRandomGenerator::global()->bounded(0, int(sothat.size()));

    // Then the program ABUSES the FUCK out of operator overloads to cobble together a QString and assigns it into text.
    // Sorry it's so unreadable. Youareyouare are whomust youmust must by by byd sothat sothatsot.

    text = YOUARE + youare[are] + ".\n\n" + WHOMUST + youmust[mst] + ".\n\n" + BY + by[byd] + ".\n\n" + SOTHAT + sothat[sot] + '.';
}

const QString& prompt::getText() const { return text; } // gets dat muddafuggin uuhhhhhhhhhhhhhhh text
