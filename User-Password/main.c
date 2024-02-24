/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Hassan abdelazeam abdelsalam
 */

#include <util/delay.h>
#include "std_types.h"
#include "dio.h"
#include "led.h"
#include "button.h"

int main()
{
	/* intiallize the LED */
	led_init(led_red);


	/* intiallize the BUZZER */
	dio_vidConfigChannel(DIO_PORTC, DIO_PIN6, OUTPUT);

	/* intiallize the three buttons */
	button_init(BUTTON1);
	button_init(BUTTON2);

	button_init(BUTTON3);

	/* intiallize the the counter of the three buttons and it's sum with 0
	 * @breif	use each counter to count the no.of pressed switches each
	 * 			and the sum to accept the password if only 6-digit password
	 */
	u8 counter1 = 0, counter2 = 0, counter3 = 0, sum = 0 ;

	/* intiallize the button state as RELEASED */
	button_status_t state1 = RELEASED;
	button_status_t state2 = RELEASED;
	button_status_t state3 = RELEASED;

	while (1)
	{
		/* get the switch state */
		state1 = button_getStatus(BUTTON1);
		state2 = button_getStatus(BUTTON2);
		state3 = button_getStatus(BUTTON3);

		/* in each condition if sw1,2,3 pressed count up the counter 1,2,3 and sum*/
		if (state1 == PRESSED)
		{
			counter1 ++;
			sum ++;
		}
		else if (state2 == PRESSED)
		{
			counter2 ++;
			sum ++;
		}
		else if (state3 == PRESSED)
		{
			counter3 ++;
			sum ++;
		}

		/*when the user pressed the switches 6 times randomly, it check if
		 * the password valid or not */
		while (sum == 6)
		{
			/*if the password valid turn on the led of 500 ms sec*/
			if ((counter1 == 2) && (counter2 == 1) && (counter3 == 3))
			{
				led_on(led_red);
				_delay_ms(500);
				led_off(led_red);
			}
			/* if the password was Invalid buzzer will beep for 500 ms*/
			else
			{
				dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_HIGH);
				_delay_ms(500);
				dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
			}

			/*reset all the counters to accept new passwords */
			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			sum = 0 ;
		}
	}
}
