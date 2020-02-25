#include <msp430.h> 
#include <lcd.h>


/**
 * main.c
 */
void play(void);
void win(void);
int i,b,c,a,d,e,f,g,h,j;

void main(void)
{
      WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    setupLCD(); //see lcd.h

    P2DIR &=~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);

    P2REN |= (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);
    P2OUT |= (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);

    P2IE  |= (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);
    P2IES |= (BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);
    P2IFG &=~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);


    P1DIR |= (BIT2+BIT3+BIT4+BIT6);
    P1OUT &=~(BIT2+BIT3+BIT4+BIT6);

   _EINT();



   clearLCD(); {


       setAddr(10,2);
          writeStringToLCD("TIC TAC TOE");
          __delay_cycles(2000000);



      clearLCD();
      __delay_cycles(200000);
      {
   setAddr(10, 0);
   writeStringToLCD("   |   |");

   setAddr(10, 1);
   writeStringToLCD("---|---|---");
   setAddr(10, 2);
   writeStringToLCD("   |   |");

   setAddr(10, 3);
   writeStringToLCD("---|---|---");
   setAddr(10, 4);
   writeStringToLCD("   |   |");
   setAddr(6, 5);
              writeStringToLCD("~tic tac toe~");


   __delay_cycles(2000000000);
   }
}
}
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{


    __delay_cycles(20000);

    win();
    play();

    P2IFG &= ~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5);

}

 void play (void)
{
      for ( j =0 ; j <4 ;j++)
    {
        switch(j)
        {

        case 0: //1.sütun

           P1OUT &=~BIT2;
           P1OUT |= BIT3;
           P1OUT |= BIT4;
           P1OUT |= BIT6;

        if((P2IN & BIT0)==0)//1
        {
            if((P2IN & BIT5)==0)
                   {

            setAddr(15,0);
            writeStringToLCD("X");       //Button 1 ve "X"e basılma durumu
           a = 3;
                   }

            else if ((P2IN &BIT4)==0)    //Button  1 ve "O" ya basılma durumu
            {
                setAddr(15,0);
                writeStringToLCD("O");
            a = 4;
            }
        }

        if((P2IN & BIT1)==0) //4
        {
            if((P2IN & BIT4)==0)        //Button  4 ve "O" ya basılma durumu
            {
                setAddr(15,2);
                writeStringToLCD("O");
                b=4;
            }

            else if((P2IN & BIT5)==0)     //Button  4 ve "X"e basılma durumu
            {
                setAddr(15,2);
                writeStringToLCD("X");
                b=3;
            }
        }

        if((P2IN & BIT2)==0) //7
        {
            if((P2IN & BIT5)==0)     //Button  7 ve "X"e basılma durumu
            {
                setAddr(15,4);
            writeStringToLCD("X");
                c=3;
            }
            else if((P2IN & BIT4)==0)   //Button  7 ve "O" ya basılma durumu
            {
                            setAddr(15,4);
                        writeStringToLCD("O");
                            c=4;

            }

        }
        break;

       case 1:              //2. sütun

        P1OUT |= BIT2;
        P1OUT &= ~BIT3;
        P1OUT |= BIT4;
        P1OUT |= BIT6;

        if((P2IN &BIT0)==0) //2
        {
            if((P2IN & BIT5)==0)          //Button  2 ve "X"e basılma durumu
            {
                     setAddr(40,0);
                       writeStringToLCD("X");
                       d = 3;
            }
            else if((P2IN & BIT4)==0)     //Button  2 ve "O" ya basılma durumu
            {
                     setAddr(40,0);
                       writeStringToLCD("O");
                      d = 4;
       }

        }

        if((P2IN &BIT1)==0) //5
        {
            if((P2IN & BIT5)==0)  //Button 5 ve "X"e basılma durumu
            {
                setAddr(40,2);
                writeStringToLCD("X");
                e=3;
            }

            else if((P2IN & BIT4)==0)   //Button  5 ve "O" ya basılma durumu
            {
                setAddr(40,2);
                writeStringToLCD("O");
                e=4;

            }
        }

        else if ((P2IN &BIT2)==0) //8
        {
            if((P2IN & BIT5)==0)  //Button 8 ve "X"e basılma durumu
                        {
                            setAddr(40,4);
                            writeStringToLCD("X");
                            f=3;
                        }

                        else if((P2IN & BIT4)==0)   //Button  8 ve "O" ya basılma durumu
                        {
                            setAddr(40,4);
                            writeStringToLCD("O");
                            f=4;

        }
        }


        break;



        case 2: //3.sütun

        P1OUT |= BIT2;
        P1OUT |= BIT3;
        P1OUT &=~BIT4;
        P1OUT |= BIT6;

       if((P2IN &BIT0)==0)//3
       {


           if((P2IN & BIT5)==0)  //Button 3 ve "X"e basılma durumu
                                  {
                                     setAddr(65,0);
                                      writeStringToLCD("X");
                                      g=3;
                                  }

                                  else if((P2IN & BIT4)==0)   //Button  3 ve "O" ya basılma durumu
                                  {
                                      setAddr(65,0);
                                      writeStringToLCD("O");
                                      g=4;

                                  }

       }


       if((P2IN &BIT1)==0)//6
       {

           if((P2IN & BIT5)==0)  //Button 6 ve "X"e basılma durumu
                      {
                          setAddr(65,2);
                          writeStringToLCD("X");
                          h=3;
                      }

                      else if((P2IN & BIT4)==0)   //Button  6 ve "O" ya basılma durumu
                      {
                          setAddr(65,2);
                          writeStringToLCD("O");
                          h=4;

                      }

       }

       if((P2IN &BIT2)==0)//9
       {

           if((P2IN & BIT5)==0)  //Button 5 ve "X"e basılma durumu
                      {
                          setAddr(65,4);
                          writeStringToLCD("X");
                          i=3;
                      }

                      else if((P2IN & BIT4)==0)   //Button  5 ve "O" ya basılma durumu
                      {
                          setAddr(65,4);
                          writeStringToLCD("O");
                          i=4;

                      }

       }

    P1OUT &=~(BIT2+BIT3+BIT4+BIT6);


}}
        }
void win(void)//kazanan kontrol

{
     if (a+b+c==9 | d+e+f==9 | g+h+i==9 | c+e+g==9 | a+e+i==9 | a+d+g==9 | b+e+h==9 | c+f+i==9)
     {

     clearLCD();
     {
     setAddr(5,2);
     writeStringToLCD("Player 1 Won!");
     }
 }

     else if (a+b+c==12 | d+e+f==12 | g+h+i==12 | c+e+g==12 | a+e+i==12 | a+d+g==12 | b+e+h==12 | c+f+i==12)
          {

          clearLCD();
          {
          setAddr(5,2);
          writeStringToLCD("Player 2 Won!");
          }
      }
     else if ((a+b+c+d+e+f+g+h+i)==31 | (a+b+c+d+e+f+g+h+i)==32){
     clearLCD();
     {

         setAddr(29,2);
         writeStringToLCD("DRAW!");
}
}
}
