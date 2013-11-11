
 /* System Calls
  Jesal Vyas and Reem Alhumaidan
*/
void printString(char* string);
void readString(char* string);
void readSector(char* buffer, int sector);
void handleInterrupt21(int ax, int bx, int cx, int dx);
int mod (int a, int b);
char line[80];
char buffer[512];

//~~~~~~~~~~~~~~~~~~~~~~~~ main function ~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {
  printString("Hello World\r\n\0");
  printString("Enter a line");
  printString("\r\n\0");
  readString(line);
  printString("\r\n\0");
  printString(line);
  printString("\r\n\0");
  readSector(buffer, 30);
  printString("\r\n\0");
    printString(buffer);
    printString("\r\n\0");
    makeInterrupt21(); 
    interrupt(0x21, 1, line, 0, 0);
    printString("\r\n\0");
    interrupt(0x21, 0, line, 0, 0);        
    
    while(1);
    return 0;
}

//~~~~~~~~~~~~~~~~~~ function for printing to screen ~~~~~~~~~~~~~~~~~~
void printString(char* string) {
  int index = 0;
  char c = string[index];
  while (c != 0) {
    interrupt(0x10, 0xE * 256 + c, 0, 0, 0);
    c = string[++index];
  }
}
// ~~~~~~~~~~~~~~~~ function to read from the keyboard ~~~~~~~~~~~~~~~~~
void readString(char* string) {
  int index = 0;
  char c = 0;
  while (1) {
    c = interrupt(0x16, 0, 0, 0, 0);
    interrupt(0x10, 0xE * 256 + c, 0, 0, 0);
    if (c == 0xD) break;
    string[index] = c;
    ++index;
  }
  string[index] = '\n';
  string[index + 1] = 0;
}
// ~~~~~~~~~~~~~~ function to read a sector from disk ~~~~~~~~~~~~~~~~~~
void readSector(char* buffer, int sector) {
  int CH = sector/36;
  int CL = mod (sector, 18);
  int DH = mod (sector/18, 2);
  interrupt(0x13, 2 * 256 + 1, buffer, CH * 256 + CL + 1, DH * 256 + 0);

}
// ~~~~~~~~~~~~~~ function to handle interrupt ~~~~~~~~~~~~~~~~~~~~~~~~
void handleInterrupt21(int ax, int bx, int cx, int dx) {
  printString("Hello there!");
  if (ax == 0) {
    printString(bx);
  } else if (ax == 1) {
        printString("Enter a line:");
        readString(bx);
  } else if (ax == 2) {
    readSector(bx, cx);
  } else {
    printString("Oops!...you've got it wrong bud!!");
  }
}
// ~~~~~~~~~~~~~~ function for calculating remainder ~~~~~~~~~~~~~~~~~~~
int mod (int a, int b) {
  while (a>=b) {
    a=a-b;
  }
  return a;
}


