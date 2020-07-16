#include "song.h"

Buzzer buzzer(14);
int i_note_song = 0;
// int StarWarsNote[] = {
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_F3,
//     NOTE_C4,
//     NOTE_A3,
//     NOTE_F3,
//     NOTE_C4,
//     NOTE_A3,
//     NOTE_E4,
//     NOTE_E4,
//     NOTE_E4,
//     NOTE_F4,
//     NOTE_C4,
//     NOTE_GS3,
//     NOTE_F3,
//     NOTE_C4,
//     NOTE_A3,
//     NOTE_A4,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A4,
//     NOTE_GS4,
//     NOTE_G4,
//     NOTE_FS4,
//     NOTE_E4,
//     NOTE_F4,
//     0,
//     NOTE_AS3,
//     NOTE_DS4,
//     NOTE_D4,
//     NOTE_CS4,
//     NOTE_C4,
//     NOTE_B3,
//     NOTE_C4,
//     0,
//     NOTE_F3,
//     NOTE_GS3,
//     NOTE_F3,
//     NOTE_A3,
//     NOTE_C4,
//     NOTE_A3,
//     NOTE_C4,
//     NOTE_E4,
//     NOTE_A4,
//     NOTE_A3,
//     NOTE_A3,
//     NOTE_A4,
//     NOTE_GS4,
//     NOTE_G4,
//     NOTE_FS4,
//     NOTE_E4,
//     NOTE_F4,
//     0,
//     NOTE_AS3,
//     NOTE_DS4,
//     NOTE_D4,
//     NOTE_CS4,
//     NOTE_C4,
//     NOTE_B3,
//     NOTE_C4,
//     0,
//     NOTE_F3,
//     NOTE_GS3,
//     NOTE_F3,
//     NOTE_C4,
//     NOTE_A3,
//     NOTE_F3,
//     NOTE_C4,
//     NOTE_A3};
// int StarWarsRytm[] = {
//  500, 500, 500, 375, 125, 500, 375, 125, 1000, 500, 500, 500, 375, 125, 500, 375, 125, 1000, 500, 375, 125, 500, 375, 125, 125, 125,
// 250, 250, 250, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 500, 375, 125, 1000, 500, 375, 125, 500, 375, 125, 125, 125, 250,
//  250, 250, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 500, 375, 125, 1000};

// void starwars_song()
// {
//     Serial.println("StarWars");
//     if (i_note_song == 0)
//     {
//         buzzer.begin(10);
//     }

//     if (StarWarsNote[i_note_song] != sizeof(StarWarsNote))
//     {
//         buzzer.sound(StarWarsNote[i_note_song], StarWarsRytm[i_note_song]);
//         ++i_note_song;
//     }
//     else
//     {
//         i_note_song = 0;
//         buzzer.end(2000);
//     }
// }
int melody[] = {

    // Game of Thrones
    // Score available at https://musescore.com/user/8407786/scores/2156716

    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_DS4,
    16,
    NOTE_F4,
    16, //1
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_E4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_E4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_E4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    8,
    NOTE_C4,
    8,
    NOTE_E4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    -4,
    NOTE_C4,
    -4, //5

    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    4,
    NOTE_C4,
    4,
    NOTE_DS4,
    16,
    NOTE_F4,
    16, //6
    NOTE_D4,
    -1, //7 and 8
    NOTE_F4,
    -4,
    NOTE_AS3,
    -4,
    NOTE_DS4,
    16,
    NOTE_D4,
    16,
    NOTE_F4,
    4,
    NOTE_AS3,
    -4,
    NOTE_DS4,
    16,
    NOTE_D4,
    16,
    NOTE_C4,
    -1, //11 and 12

    //repeats from 5
    NOTE_G4,
    -4,
    NOTE_C4,
    -4, //5

    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    4,
    NOTE_C4,
    4,
    NOTE_DS4,
    16,
    NOTE_F4,
    16, //6
    NOTE_D4,
    -1, //7 and 8
    NOTE_F4,
    -4,
    NOTE_AS3,
    -4,
    NOTE_DS4,
    16,
    NOTE_D4,
    16,
    NOTE_F4,
    4,
    NOTE_AS3,
    -4,
    NOTE_DS4,
    16,
    NOTE_D4,
    16,
    NOTE_C4,
    -1, //11 and 12
    NOTE_G4,
    -4,
    NOTE_C4,
    -4,
    NOTE_DS4,
    16,
    NOTE_F4,
    16,
    NOTE_G4,
    4,
    NOTE_C4,
    4,
    NOTE_DS4,
    16,
    NOTE_F4,
    16,

    NOTE_D4,
    -2, //15
    NOTE_F4,
    -4,
    NOTE_AS3,
    -4,
    NOTE_D4,
    -8,
    NOTE_DS4,
    -8,
    NOTE_D4,
    -8,
    NOTE_AS3,
    -8,
    NOTE_C4,
    -1,
    NOTE_C5,
    -2,
    NOTE_AS4,
    -2,
    NOTE_C4,
    -2,
    NOTE_G4,
    -2,
    NOTE_DS4,
    -2,
    NOTE_DS4,
    -4,
    NOTE_F4,
    -4,
    NOTE_G4,
    -1,

    NOTE_C5,
    -2, //28
    NOTE_AS4,
    -2,
    NOTE_C4,
    -2,
    NOTE_G4,
    -2,
    NOTE_DS4,
    -2,
    NOTE_DS4,
    -4,
    NOTE_D4,
    -4,
    NOTE_C5,
    8,
    NOTE_G4,
    8,
    NOTE_GS4,
    16,
    NOTE_AS4,
    16,
    NOTE_C5,
    8,
    NOTE_G4,
    8,
    NOTE_GS4,
    16,
    NOTE_AS4,
    16,
    NOTE_C5,
    8,
    NOTE_G4,
    8,
    NOTE_GS4,
    16,
    NOTE_AS4,
    16,
    NOTE_C5,
    8,
    NOTE_G4,
    8,
    NOTE_GS4,
    16,
    NOTE_AS4,
    16,

    0,
    4,
    NOTE_GS5,
    16,
    NOTE_AS5,
    16,
    NOTE_C6,
    8,
    NOTE_G5,
    8,
    NOTE_GS5,
    16,
    NOTE_AS5,
    16,
    NOTE_C6,
    8,
    NOTE_G5,
    16,
    NOTE_GS5,
    16,
    NOTE_AS5,
    16,
    NOTE_C6,
    8,
    NOTE_G5,
    8,
    NOTE_GS5,
    16,
    NOTE_AS5,
    16,
};
int tempo = 85;
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void gotSong()
{
    if (i_note_song != notes)
    {
        // calculates the duration of each note

        divider = melody[i_note_song + 1];
        if (divider > 0)
        {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0)
        {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        buzzer.sound(melody[i_note_song], noteDuration * 0.9);
        // we only play the note for 90% of the duration, leaving 10% as a pause
        // tone(buzzer, melody[thisNote], noteDuration * 0.9);

        // // Wait for the specief duration before playing the next note.
        // delay(noteDuration);

        // // stop the waveform generation before the next note.
        // noTone(buzzer);
        i_note_song += 2;
    }
    else
    {
        i_note_song = 0;
    }
}