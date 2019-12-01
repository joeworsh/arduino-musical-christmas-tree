// Joe Worsham 2019
// Musical Christmas Tree

/*
 * Hardware configuration
 */
#define  LATCH_PIN      12 // shift register pins
#define  CLOCK_PIN      8
#define  DATA_PIN       11
#define  BUZZER_PIN     10
#define  TREE_PIN       9
#define  BTN_INPUT_PIN  13

#define  C_LED        1  // LEDs are represented as bit shifted int values for shift register
#define  D_LED        2
#define  E_LED        4
#define  F_LED        8
#define  G_LED        16
#define  A_LED        32
#define  B_LED        64
#define  C2_LED       128

/*
 * Frequencies in Hz of notes played on the arduino board. The frequencies are
 * in the lowest octave. The octaves can range from 0 to 8. The correct value of
 * frequency in octave is: freq * 2^octave
 */
#define  C_FREQ  16.35
#define  CS_FREQ 17.35
#define  D_FREQ  18.35
#define  DS_FREQ 19.475
#define  E_FREQ  20.60
#define  ES_FREQ 21.215
#define  F_FREQ  21.83
#define  FS_FREQ 23.165
#define  G_FREQ  24.50
#define  GS_FREQ 26.0
#define  A_FREQ  27.50
#define  AS_FREQ 29.185
#define  B_FREQ  30.87
#define  BS_FREQ 31.785

// constants to define the lengths of each song
#define  JINGLE_BELLS_LEN    51
#define  JOY_TO_WRLD_LEN     57
#define  GOD_REST_GENTS_LEN  68
#define  SONG_COUNT          3


bool pressed = false;
int songIdx = 0;

struct note
{
  int key;
  bool sharp;
  int octave;
  int duration;
};

void populateNote(struct note* n, int key, bool sharp, int octave, int duration)
{
  n->key = key;
  n->sharp = sharp;
  n->octave = octave;
  n->duration = duration;
}

struct note* playJingleBells()
{
  struct note *song = new struct note[JINGLE_BELLS_LEN];
  
  int i = 0;
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 4);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 4);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 1, false, 4, 3);  // C
  populateNote(&song[i++], 2, false, 4, 1);  // D
  
  populateNote(&song[i++], 3, false, 4, 8);  // E
  
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 4, false, 4, 3);  // F
  populateNote(&song[i++], 4, false, 4, 1);  // F
  
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 1);  // E
  populateNote(&song[i++], 3, false, 4, 1);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 2, false, 4, 2);  // D
  populateNote(&song[i++], 2, false, 4, 2);  // D
  populateNote(&song[i++], 3, false, 4, 2);  // E
  
  populateNote(&song[i++], 2, false, 4, 4);  // D
  populateNote(&song[i++], 5, false, 4, 4);  // G
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 4);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 4);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 1, false, 4, 3);  // C
  populateNote(&song[i++], 2, false, 4, 1);  // D
  
  populateNote(&song[i++], 3, false, 4, 8);  // E
  
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 4, false, 4, 3);  // F
  populateNote(&song[i++], 4, false, 4, 1);  // F
  
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 1);  // E
  populateNote(&song[i++], 3, false, 4, 1);  // E
  
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 4, false, 4, 2);  // F
  populateNote(&song[i++], 2, false, 4, 2);  // D
  
  populateNote(&song[i++], 1, false, 4, 8);  // C
  
  return song;
}

struct note* playJoyToTheWorld()
{
  struct note *song = new struct note[JOY_TO_WRLD_LEN];
  
  int i = 0;
  
  populateNote(&song[i++], 8, false, 4, 4);  // C
  populateNote(&song[i++], 7, false, 4, 3);  // B
  populateNote(&song[i++], 6, false, 4, 1);  // A
  
  populateNote(&song[i++], 5, false, 4, 6);  // G
  populateNote(&song[i++], 4, false, 4, 2);  // F
  
  populateNote(&song[i++], 3, false, 4, 4);  // E
  populateNote(&song[i++], 2, false, 4, 4);  // D
  
  populateNote(&song[i++], 1, false, 4, 6);  // C
  populateNote(&song[i++], 5, false, 4, 2);  // G
  
  populateNote(&song[i++], 6, false, 4, 6);  // A
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 7, false, 4, 6);  // B
  populateNote(&song[i++], 7, false, 4, 2);  // B
  
  populateNote(&song[i++], 8, false, 4, 12);  // C
  populateNote(&song[i++], 8, false, 4, 2);  // C
  
  populateNote(&song[i++], 8, false, 4, 2);  // C
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  
  populateNote(&song[i++], 5, false, 4, 3);  // G
  populateNote(&song[i++], 4, false, 4, 1);  // F
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 8, false, 4, 2);  // C
  
  populateNote(&song[i++], 8, false, 4, 2);  // C
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  
  populateNote(&song[i++], 5, false, 4, 3);  // G
  populateNote(&song[i++], 4, false, 4, 1);  // F
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 3, false, 4, 1);  // E
  populateNote(&song[i++], 4, false, 4, 1);  // F
  
  populateNote(&song[i++], 5, false, 4, 6);  // G
  populateNote(&song[i++], 4, false, 4, 1);  // F
  populateNote(&song[i++], 3, false, 4, 1);  // E
  
  populateNote(&song[i++], 2, false, 4, 2);  // D
  populateNote(&song[i++], 2, false, 4, 2);  // D
  populateNote(&song[i++], 2, false, 4, 2);  // D
  populateNote(&song[i++], 2, false, 4, 1);  // D
  populateNote(&song[i++], 3, false, 4, 1);  // E
  
  populateNote(&song[i++], 4, false, 4, 6);  // F
  populateNote(&song[i++], 3, false, 4, 1);  // E
  populateNote(&song[i++], 2, false, 4, 1);  // D
  
  populateNote(&song[i++], 1, false, 4, 2);  // C
  populateNote(&song[i++], 8, false, 4, 4);  // C
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 5, false, 4, 3);  // G
  populateNote(&song[i++], 4, false, 4, 1);  // F
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 4, false, 4, 2);  // F
  
  populateNote(&song[i++], 3, false, 4, 4);  // E
  populateNote(&song[i++], 2, false, 4, 4);  // D

  populateNote(&song[i++], 1, false, 4, 8);  // C
  
  return song;
}

struct note* playGodRestYeMerryGents()
{
  // key - F-sharp
  struct note *song = new struct note[GOD_REST_GENTS_LEN];
  
  int i = 0;
  populateNote(&song[i++], 3, false, 4, 2);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 2, false, 4, 2);  // D
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  populateNote(&song[i++], 5, false, 4, 3);  // G
  populateNote(&song[i++], 6, false, 4, 1);  // A
  
  populateNote(&song[i++], 7, false, 4, 6);  // B
  populateNote(&song[i++], 3, false, 4, 2);  // E
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 2, false, 4, 2);  // D
  
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  populateNote(&song[i++], 5, false, 4, 3);  // G
  populateNote(&song[i++], 6, false, 4, 1);  // A
  
  populateNote(&song[i++], 7, false, 4, 4);  // B
  populateNote(&song[i++], 0, false, 4, 2);  // rest
  populateNote(&song[i++], 7, false, 4, 2);  // B
  
  populateNote(&song[i++], 8, false, 4, 2);  // C
  populateNote(&song[i++], 6, false, 4, 2);  // A
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 8, false, 4, 2);  // C
  
  populateNote(&song[i++], 2, false, 5, 2);  // D
  populateNote(&song[i++], 3, false, 5, 2);  // E
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 3, false, 4, 2);  // E
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  populateNote(&song[i++], 5, false, 4, 2);  // G
  
  populateNote(&song[i++], 6, false, 4, 4);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 6, false, 4, 2);  // A
  
  populateNote(&song[i++], 7, false, 4, 4);  // B
  populateNote(&song[i++], 8, false, 4, 2);  // C
  populateNote(&song[i++], 7, false, 4, 2);  // B
  
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  
  populateNote(&song[i++], 3, false, 4, 4);  // E
  populateNote(&song[i++], 5, false, 4, 1);  // G
  populateNote(&song[i++], 4, true, 4, 1);   // Fs
  populateNote(&song[i++], 3, false, 4, 2);  // E
  
  populateNote(&song[i++], 6, false, 4, 4);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 6, false, 4, 4);  // A
  
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 8, false, 4, 2);  // C
  populateNote(&song[i++], 2, false, 5, 2);  // D
  populateNote(&song[i++], 3, false, 5, 2);  // E
  
  populateNote(&song[i++], 7, false, 4, 2);  // B
  populateNote(&song[i++], 6, false, 4, 2);  // A
  populateNote(&song[i++], 5, false, 4, 2);  // G
  populateNote(&song[i++], 4, true, 4, 2);   // Fs
  
  populateNote(&song[i++], 3, false, 4, 6);  // E
  
  return song;
}

struct note *jingleBells;
struct note *joyToWrld;
struct note *godRestYeGents;

void setup() {
  // define the pins and hardware configs
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TREE_PIN, OUTPUT);
  pinMode(BTN_INPUT_PIN, INPUT);
  
  // allocate memory for all songs up front
  jingleBells = playJingleBells();
  joyToWrld = playJoyToTheWorld();
  godRestYeGents = playGodRestYeMerryGents();
}

void loop() {
  struct note *song;
  int songLen;
  if (songIdx == 0)
  {
    song = jingleBells;
    songLen = JINGLE_BELLS_LEN;
  }
  else if (songIdx == 1)
  {
    song = joyToWrld;
    songLen = JOY_TO_WRLD_LEN;
  }
  else if (songIdx == 2)
  {
    song = godRestYeGents;
    songLen = GOD_REST_GENTS_LEN;
  }

  // cycle through the current song
  for (int i = 0; i < songLen; i++)
  {
    // check to see if the user has selected to change songs
    if (checkButtonInterupt())
    {
      songIdx = (songIdx + 1) % SONG_COUNT; // cycle to the next song
      break;
    }
    
    // play the next note
    struct note *next = &song[i];
    playNote(next->key, next->sharp, next->octave, next-> duration);
  }
}

bool checkButtonInterupt()
{
  bool newPress = digitalRead(BTN_INPUT_PIN) == HIGH ? true : false;
  bool trigger = pressed && !newPress;  // only interupt on button release
  pressed = newPress;
  return trigger;
}

///
/// Play the provided note index where 1 = C4 up to 8 = C5.
///
void playNote(uint8_t noteIndex, bool sharp, int octave, int duration)
{
  int led = 0, freq = 0;
  bool shouldPlay = true;
  switch(noteIndex)
  {
    case 0:  // rest
      shouldPlay = false;
      break;
    case 1:
      led = C_LED;
      freq = (int) ((sharp ? CS_FREQ : C_FREQ) * pow(2, octave));
      break;
    case 2:
      led = D_LED;
      freq = (int) ((sharp ? DS_FREQ : D_FREQ) * pow(2.0, octave));
      break;
    case 3:
      led = E_LED;
      freq = (int) ((sharp ? ES_FREQ : E_FREQ) * pow(2.0, octave));
      break;
    case 4:
      led = F_LED;
      freq = (int) ((sharp ? FS_FREQ : F_FREQ) * pow(2.0, octave));
      break;
    case 5:
      led = G_LED;
      freq = (int) ((sharp ? GS_FREQ : G_FREQ) * pow(2.0, octave));
      break;
    case 6:
      led = A_LED;
      freq = (int) ((sharp ? AS_FREQ : A_FREQ) * pow(2.0, octave));
      break;
    case 7:
      led = B_LED;
      freq = (int) ((sharp ? BS_FREQ : B_FREQ) * pow(2.0, octave));
      break;
    case 8:
      led = C2_LED;
      // the next higher octave
      freq = (int) ((sharp ? CS_FREQ : C_FREQ) * pow(2.0, octave + 1));
      break;
  }
  
  if (shouldPlay)
  {
    playNote(led, freq);
    digitalWrite(TREE_PIN, HIGH);
  }
  delay(60 * duration);
  digitalWrite(TREE_PIN, LOW);
  delay(60 * duration);
  if (shouldPlay)
  {
    stopPlaying();
  }
  delay(10);
}

///
/// Play the provided frequency on the buzzer and turn on the
/// corresponding LED.
///
void playNote(int led, int freq)
{
  // play the tone of the note and turn on the LED
  tone(BUZZER_PIN, freq);
  
  // shift the value of the LED to turn on
  digitalWrite(LATCH_PIN, LOW); //ground latchPin and hold low for as long as you are transmitting
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, led);
  digitalWrite(LATCH_PIN, HIGH); //pull the latchPin to save the data
}

///
/// Stop playing any tone and turn off all LEDs
///
void stopPlaying()
{
  // stop playing the tone
  noTone(BUZZER_PIN);
  
  // shift the value to turn all LEDs off
  digitalWrite(LATCH_PIN, LOW); //ground latchPin and hold low for as long as you are transmitting
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  digitalWrite(LATCH_PIN,HIGH); //pull the latchPin to save the data
}

