/* kernel.c
A simple kernel that displays a message.
Reem Alhumaidan
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
 
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
#define DiskName "File Name"
#define NUM_SIDES         2
#define TRACKS_PER_SIDE   80
#define SECTORS_PER_TRACK 18
#define SECTORS_PER_SIDE  (TRACKS_PER_SIDE * SECTORS_PER_TRACK)
#define bufferSize 5000000
 
//Function Declairation
void printString(char* chars);
void readString(char* chars, int size);
void readSector(char *buffer, int sector);
void handleInterrupt21(int ax, int bx, int cx, int dx); {
if (ax ==0) {
printString(bx);
} else if (ax = 1){
readString(bx);
} else if (ax ==2){
readSector (bx,cx);
} else {
printString("Durp!"); }}
 
int main (int argc, char *argv[]) {
 
makeInterrupt21();
 
    char chars[80];
    char buffer[bufferSize] = "";
    //Function Calling
    printString("Enter a line: \0");
    readString(chars, ARRAY_SIZE( chars ));
    printString(chars);
    printString("\n");
 
     printString("Hello World\n\0");
     printString("Wat?!");
     readString(line);
     printString(line);
     int x;
while (1); // mock idle
return 0; }
 
     readSector(buffer, 100);
    printString(buffer);
 
/*    makeInterrupt21();*/
/*    interrupt(0x21,0,0,0,0);*/
    return 0;
}
 
//Function Definition
void printString(char* chars) {
int index = 0;
char c= string[index];
while (c !=0){
interrupt(0x10, 0xF * 256 + c, 0, 0,0);
c= string[++index];
    while(*chars) {
        putchar(*chars);
        chars++;
    }
}
 
void readString(char* chars, int size) {
    char ch;
    int i;
/*    system ("/bin/stty raw");*/
    for (i = 0; i < size-2; ++i) {
        ch = getchar();
        if (ch == 10)
            break;
        chars[i] = ch;
    }
    chars[i] = '\n';
    chars[i] = '\0';
/*    system ("/bin/stty cooked");*/
}
 
void readSector(char *buffer, int sector) {
    size_t head;
    size_t track;
    size_t sectors;
    int size = 20;
    char localBuffer[size];
    for (head = 1; head <= NUM_SIDES; head++) {
            snprintf(localBuffer, size, "%d, ", head);
        for (track = 1; track <= TRACKS_PER_SIDE; track++) {
                    snprintf(localBuffer, size, "%d, ", track);
            for (sectors = 1*sector; sectors <= (SECTORS_PER_TRACK*sector); sectors++) {
                    snprintf(localBuffer, size, "%d, ", sectors);
                    if (strlen(buffer) < bufferSize)
                        buffer = strcat(buffer, localBuffer);
            }
        }
    }
}
 
void handleInterrupt21(int ax, int bx, int cx, int dx) {
/*    union REGS InReg;*/
/*    union REGS OutReg;*/
 
/*    struct SREGS SegReg;*/
 
/*    InReg.h.ah=0x09;*/
/*    InReg.x.dx=FP_OFF(String);*/
/*    SegReg.ds=FP_SEG(String);*/
    printString("Hello WOrld!!\0");
 
/*    int86x(0x21,&InReg,&OutReg,&SegReg);*/
}