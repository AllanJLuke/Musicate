//
//  main.cpp
//  Musicate
//
//  Created by Aamir Jawaid on 12-07-27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <irrKlang.h>
#include "tinyxml2.h"

using namespace irrklang;
using namespace tinyxml2;
using namespace std;

bool play = false;
char* currentFile = NULL;
XMLDocument doc;

char* nextFile()
{
    char* File = NULL;
    return File;
}

char* prevFile()
{
    char* File = NULL;
    return File;
}

void Store(char* File)
{
    //Use Hash table
}

void Delete(char* File)
{
    //Delete
}

void List()
{
    
}

int LoadXMLFile()
{
    doc.LoadFile( "/Users/Aamir/Documents/workspace/Musicate/dream.xml" );
    
    return doc.ErrorID();
}

int main(int argc, const char * argv[])
{
    ISoundEngine *engine = createIrrKlangDevice(); 
    if (!engine)
        return 0;

    printf("Opening XML document\n");
    bool XMLloaded = false;
    XMLloaded = (LoadXMLFile() == 0);
    if (XMLloaded)
    {
        //Time to read
        XMLPrinter printer;
        doc.Print(&printer);
        doc.Parse(printer.CStr());
        XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
        const char* title = titleElement->GetText();
        printf( "Name of play (1): %s\n", title );
    }
    
    /* --- PLAYING FILE --*/
    engine->play2D("/Users/Aamir/Documents/workspace/Musicate/Musicate/02 Daaru Desi  - DownloadMing.INFO.mp3", true);
    play = true;
    
	
    printf("\nPlaying...\n");
    char i = 0;
    while(i != 'q')
    {
        cout << "Press q to quit, p to toggle play and pause: \n";
        cin >> i;
        switch (i)
        {
            case 'p':
            {
                engine->setAllSoundsPaused(play);
                    if (play)
                        play = false;
                    else
                        play = true;
                break;
            }
            case 'q':
            {
                cout << "Quitting...\n";
                break;
            }
            default:
            {
                cout << "No operation for this key";
                break;
            }
        }
    }
    engine->drop();
    
    // insert code here...
    std::cout << "Quitting!\n";
    return 0;
}

