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

using namespace irrklang;
using namespace std;

bool play = false;
char* currentFile = NULL;

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

int main(int argc, const char * argv[])
{
    ISoundEngine *engine = createIrrKlangDevice(); 
    if (!engine)
        return 0;

    engine->play2D("/Users/Aamir/Music/iTunes/iTunes Media/Music/www.Songs.PK/3 Idiots/07 Aal Izz Well (Remix) - www.Songs.PK.mp3", true);
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

