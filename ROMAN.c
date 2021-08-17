#include<stdio.h>
#include<string.h>


//Numerical string to number
int val(char r) {

//Roman Numeral input    
  if (r == 'I')

    return 1;

if (r == 'V')
return 5;

if (r == 'X')
return 10;

if (r == 'L')
return 50;

if (r == 'C')
return 100;

if (r == 'D')
return 500;

if (r == 'M')
return 1000;

    return -1;
}

//Roman Number To Decimal
int romannumToDecimal(char arr[]) {
    
int res = 0;

int i,len=strlen(arr);

for (i=0; i<len; i++) {
    
int s1 = val(arr[i]);

if (i+1 < len) {
    
int s2 = val(arr[i+1]);

if (s1 >= s2)
res = res + s1;

else
    
{
    
res = res + s2 - s1;

i++;

}

}

//repeat
else
    
{
res = res + s1;

i++;

}

}

return res;

}

//sub value
int subVal(char num1, char num2, int i, char *c) {
    
c[i++] = num1;

c[i++] = num2;

return i;

}

//
int value(char ch, int n, int i, char *c) {
    
int j;

for (j = 0; j < n; j++)
c[i++] = ch;

return i;
}

// Print Roman Numerals
   void printRoman(int num) {
   char c[10001];

  int i = 0;

  while (num != 0) {
    
if (num >= 1000) {
    
i = value('M', num/1000, i, c);

num = num%1000;

}

   else if (num >= 500)
    
{
    
if (num < 900) {
i = value('D', num/500, i, c);

num = num%500;

}
else
{
i = subVal('C', 'M', i, c);

num = num%100 ;

}

}

   else if (num >= 100) {
    
if (num < 400) {
    
i = value('C', num/100, i, c);

num = num%100;

}

else {
i = subVal('C','D',i,c);

num = num%100;

}

}

   else if (num >= 50 ) {
    
if (num < 90) {
    
i = value('L', num/50,i,c);

num = num%50;

}

     else {
i = subVal('X','C',i,c);

num = num%10;

}

}

else if (num >= 10)
    
{

if (num < 40) {
    
    
i = value('X', num/10,i,c);

num = num%10;

}

else
    
{
    
i = subVal('X','L',i,c);

num = num%10;

}

}

else if (num >= 5)
    
{
    
if (num < 9) {
    
i = value('V', num/5,i,c);

num = num%5;

}

else {
    
i = subVal('I','X',i,c);

num = 0;

}

}

else if (num >= 1) {
    
if (num < 4) {
    
i = value('I', num,i,c);

num = 0;

}

else {
    
i = subVal('I', 'V', i, c);

num = 0;

}

}

}

//
int j;

for (j = 0; j < i; j++)
    
printf("%c", c[j]);

}

//
    int main() {
    
    
  char arr1[100];

  char arr2[100];

scanf("%s %s",arr1,arr2);

int val1=romannumToDecimal(arr1); 

int val2=romannumToDecimal(arr2);

  printRoman(val1+val2);
 //Call input file and ouput file
 FILE *ifp, *ofp;
char *mode = "w";
char outputFilename[] = "ROMAN.TXT";

ifp = fopen("ROMAN.TXT", mode);

if (ifp == NULL) {
  fprintf(stderr, "Can't open input file ROMAN.TXT!\n");
  exit(1);
}

ofp = fopen(outputFilename, "w");

if (ofp == NULL) {
  fprintf(stderr, "Can't open output file %s!\n",
          outputFilename);
  exit(1);
}

fclose(ifp);
fclose(ofp);

    return 0;

}
