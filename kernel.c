/* kernel.c
A simple kernel that displays a message.
Reem Alhumaidan
*/


void printString(char* string);
void readString(char* string);
void readSector(char* buffer, int sector);
int mod (int a, int b);
int div (int a, int b);
void handleInterrupt21(int ax, int bx, int cx, int dx) {
    if (ax == 0) {
        printString(bx);
    } else if (ax == 1) {
        readString(bx);
    } else if (ax == 2) {
        readSector(bx, cx);
    } else {
        printString("Oops!");
    }
}

char line[80];
int main() {
    
makeInterrupt21();
    
    char buffer[512];
    readSector(buffer, 30);
    printString(buffer);

    
    printString("Hello World\r\n\0");
    
    printString("Enter a line");
    readString(line);
    printString(line);
        mod(a, b) {
            while (a>=b) {
                a = a - b;
                return a;
            }
        }
        div (a, b) {
            int q = 0;
            while (q*b < a) {
                q = q + 1;
                return q;
            }
        }

    while(1);
    
    return 0;
}
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

void printString(char* string) {
    int index = 0;
    char c = string[index];
    while (c != 0) {
        interrupt(0x10, 0xE * 256 + c, 0, 0, 0);
        c = string[++index];
    }
}