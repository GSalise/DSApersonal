#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char personalInfo;
/*Given 8 bits: 0000 0000

 Bits
 8    = Status:            0 - Inactive, 1 - Active
 7    = Nationality:       0 - Filipino, 1 - Foreigner
 6    = Enrollment Status: 0 - Regular, 1 - Irregular
 5    = Gender:            0 - Male, 1 - Female
 3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
 1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH

 For example:
 1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
*/

// Goal: Learn sets and how to use bitwise operators

int main()
{
    printf("\n----------------------------------------\n\n");

    personalInfo a = 12;
    personalInfo b = 25;

    /*

    bitwise &
    basically outputs a 1 if the corressponding bit is a 1

    12 = 00001100 (In Binary)
    25 = 00011001 (In Binary)

    Bit Operation of 12 and 25
    00001100
  & 00011001
    ________
    00001000  = 8 (In decimal)

    */

    printf("Bitiwise & output: %d", a & b);

    /*

    bitwise |
    outputs if 1 at least one of the corresponding bits is a 1

    12 = 00001100 (In Binary)
    25 = 00011001 (In Binary)

    Bitwise OR Operation of 12 and 25
    00001100
  | 00011001
    ________
    00011101  = 29 (In decimal)

    */

    printf("\nBitwise | ouput: %d", a | b);

    /*

     bitwise ^
     outputs 1 if the corresponding bits are opposite

     12 = 00001100 (In Binary)
     25 = 00011001 (In Binary)

     Bitwise XOR Operation of 12 and 25
     00001100
   ^ 00011001
     ________
     00010101  = 21 (In decimal)

    */

    printf("\nBitwise ^ output: %d", a ^ b);

    /*

    bitwise ~
    works on one operand only
    reverses the bits

    35 = 00100011 (In Binary)

    Bitwise complement Operation of 35
  ~ 00100011
    ________
    11011100  = 220 (In decimal)

    */
    personalInfo c = 35;
    printf("\nBitwise ~ output: %d", ~c);

    /*

     Right Shift
     Shifts all of the bits towards the right by a certain number of specified bits

     6 = 0000 0110 (In binary)
     6>>1 = 0000 0011
         - 6 is now 3
     3>>1 = 0000 0001
         - 3 is now 1

     A pattern can be noticed where everytune we right shift the value halves

    */

    personalInfo d = 6;
    personalInfo d1 = d >> 1;
    personalInfo d2 = d >> 2;
    printf("\n\nOriginal Value %d\n[1]Right Shift Output: %d\n[2]Right Shift Output: %d", d, d1, d2);

    /*
     Left Shift
     Shifts all of the bits towards the left by a certain number if specified bits
     The shifted bits will be replaced with 0

     6 = 0000 0110 (In binary)
     6<<1 = 0000 1100 (In binary) [Left shift by one bit]
         - 6 is now 12
     12<<2 = 0011 0000 (In binary)
         - 12 is now 48

     A pattern can be noticed where everytime we left shift the value doubles

    */

    personalInfo d3 = d << 1;
    personalInfo d4 = d << 3;
    printf("\n\nOriginal Value %d\n[1]Left Shift Output: %d\n[2]Left Shift Output: %d", d, d3, d4);

    printf("\n\n\n");
    // Let's apply what we learned

    /*Given 8 bits: 0000 0000

    Bits
    8    = Status:            0 - Inactive, 1 - Active
    7    = Nationality:       0 - Filipino, 1 - Foreigner
    6    = Enrollment Status: 0 - Regular, 1 - Irregular
    5    = Gender:            0 - Male, 1 - Female
    3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
    1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH

    For example:
    1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
    */

    //Create a code to generate the following:
    //Generate an Active Regular 3rd Year Filipino Female IT Student 1001 1001
    //Generate an Inactive Irregular 2nd Year Foreigner Male CS Student 0110 0100


    //Implement Bit Masking

    /*
        0x(hex)(hex)
        0x01 == 0000 0001
        0x02 == 0000 0010
        0x0A == 0000 1010
        0xF9 == 1111 1001
    */

    personalInfo mask, stud = 0;
    int input;

    printf("Enter Student Status: ");
    scanf("%d", &input);

    if(input == 1){
        stud ^= 0x80;
    }


    printf("Enter Student Nationality: ");
    scanf("%d", &input);

    if(input == 1){
        stud ^= 0x40;
    }

    printf("Enter Student Enrollment Status: ");
    scanf("%d", &input);

    if(input == 1){
        stud ^= 0x20;
    }

    printf("Enter Student Gender: ");
    scanf("%d", &input);

    if(input == 1){
        stud ^= 0x10;
    }

    printf("Enter Student Enrollment Year level: ");
    scanf("%d", &input);

    if(input == 2){
        stud ^= 0x04;
    }

    if(input == 3){
        stud ^= 0x08;
    }

    if(input == 4){
        stud ^= 0x0C;
    }

    printf("Enter Student Program: ");
    scanf("%d", &input);

    if(input == 2){
        stud ^= 0x01;
    }

    if(input == 3){
        stud ^= 0x02;
    }

    if(input == 4){
        stud ^= 0x03;
    }

    for(int i = 7; i>=0; i--){
        printf("[%d]", (stud & (1<<i)) ? 1 : 0);
    }

    printf("\n\n[%d]", stud);



    printf("\n\n----------------------------------------\n");
    return 0;
}