/*
                        Autor: Hyan C. Costa.
                        Descricao: o programa  abaixo tem a funcao de ligar os
                        leds do PORTB em sequencia somente quando precionado o botao PORTD
 */

#include <avr/io.h>
#include<util/delay.h>
int main(void)
{


    DDRD = 0x00;
    DDRB = 0x3F; //as portas de 0 a 5 estao como output, o resto, input.

    PORTB = 0x00; // zerando o byte PORTB
    PORTD = 0x04; // colocando o bit 02 como pullup
    char i;
    char b;


    for(;;){

        while (( ~PIND ) & 0b00000100){     //a conexão deve estar em pull up para q quando o botao for precionado, a condicao seja verdadeira.

            for(i=0;i<6;i++){               // liga as portas de 0 a 5 uma de cada vez
                PORTB = PORTB^(0x01<<i);
                _delay_ms(100);

            }
            for(b=6;b>=0;b--){              // desliga as portas de 0 a 5 uma de cada vez
                PORTB = PORTB ^(0x00>>b);
                _delay_ms(100);
            }
        }



    }

}
