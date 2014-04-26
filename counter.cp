#line 1 "I:/Documents/Projects/Pic Tools/Active Projects/7-Seg Single Counter/counter.c"
#line 13 "I:/Documents/Projects/Pic Tools/Active Projects/7-Seg Single Counter/counter.c"
const unsigned int _pA=0b00000001;
const unsigned int _pB=0b00000010;
const unsigned int _pC=0b00000100;
const unsigned int _pD=0b00001000;
const unsigned int _pE=0b00010000;
const unsigned int _pF=0b00100000;
const unsigned int _pG=0b01000000;
const unsigned int _pH=0b10000000;

unsigned int i;




unsigned char Display(unsigned char no){
 unsigned char Pattern;
 unsigned char SEGMENT[]={
 0xFF&(~_pG)&(~_pH),
 _pB|_pC,
 0xFF&(~_pC)&(~_pF)&(~_pH),
 0xFF&(~_pE)&(~_pF)&(~_pH),
 _pB|_pC|_pF|_pG,
 0xFF&(~_pB)&(~_pE)&(~_pH),
 0xFF&(~_pB)&(~_pH),
 _pA|_pB|_pC,
 0xFF&(~_pH),
 0xFF&(~_pE)&(~_pH),
 };
 Pattern=SEGMENT[no];
 return(Pattern);
}


void main(){









 OSCCON=0x6E;






 CMCON=0x07;
#line 75 "I:/Documents/Projects/Pic Tools/Active Projects/7-Seg Single Counter/counter.c"
 ADCON1=0x8F;






 TRISB=0x00;




 while(1){
 for(i=0; i<=10; i++){
 PORTB=Display(i);
 Delay_ms(1000);
 }
 }
}
