
/**
 * \file test_adc_external_input.xc
 * \brief Test illustrates usage of adc to get external potentiometer sensor values.
 *   By default the analog inputs are configured as differential only.
 * \author Pavan Kanajar <pkanajar@synapticon.com>
 * \author Martin Schwarz <mschwarz@synapticon.com>
 */

#include <xs1.h>
#include <platform.h>
#include <print.h>
#include <stdio.h>
#include <stdint.h>
#include <ioports.h>
#include <adc_server_ad7949.h>
#include <adc_client_ad7949.h>
#include <hall_server.h>
#include <pwm_service_inv.h>
#include <comm_loop_server.h>
#include <refclk.h>
#include <bldc_motor_config.h>
#include <drive_config.h>

#define TILE_ONE 0
#define IFM_TILE 3

on stdcore[IFM_TILE]: clock clk_adc = XS1_CLKBLK_1;
on stdcore[IFM_TILE]: clock clk_pwm = XS1_CLKBLK_REF;



/* ADC Client test function */
void adc_test(chanend c_adc)
{
	int external_input_1;
	int external_input_2;
	int core_id = 1;
	timer t;

	while(1)
	{
		/* Read external analog input */
		{external_input_1 , external_input_2} = get_adc_external_ad7949(c_adc);
		wait_ms(1, core_id, t);


		printstr(" Analog input 1: ");
		printint(external_input_1);
		printstr(" ");
		printstr(" Analog input 2: ");
		printintln(external_input_2);
	}
}

int main(void)
{
	chan c_adctrig, c_adc;													// adc channels
	chan c_hall_p1, c_hall_p2, c_hall_p3, c_hall_p4, c_hall_p5, c_hall_p6;	// hall channels
	chan c_commutation_p1, c_commutation_p2, c_commutation_p3, c_signal;	// commutation channels
	chan c_pwm_ctrl;														// pwm channels
	chan c_qei;																// qei channel
	chan c_watchdog;														// watchdog channel

	par
	{

		on stdcore[TILE_ONE]:
		{
			/* ADC Client test function */
			adc_test(c_adc);
		}



		/************************************************************
		 * IFM_CORE
		 ************************************************************/
		on stdcore[IFM_TILE]:
		{
			par
			{
				/* ADC loop (only if motor control is not used) */
		//		adc_ad7949( c_adc, clk_adc, p_ifm_adc_sclk_conv_mosib_mosia, p_ifm_adc_misoa, p_ifm_adc_misob );


				/* ADC triggered loop (only if motor control is used) */
				adc_ad7949_triggered(c_adc, c_adctrig, clk_adc,
						p_ifm_adc_sclk_conv_mosib_mosia, p_ifm_adc_misoa,
						p_ifm_adc_misob);

				/* PWM Loop */
				do_pwm_inv_triggered(c_pwm_ctrl, c_adctrig, p_ifm_dummy_port,\
						p_ifm_motor_hi, p_ifm_motor_lo, clk_pwm);

				/* Motor Commutation loop */
				{
					hall_par hall_params;
					qei_par qei_params;
					commutation_par commutation_params;
					init_hall_param(hall_params);
					init_qei_param(qei_params);
					init_commutation_param(commutation_params, hall_params, MAX_NOMINAL_SPEED); // initialize commutation params
					commutation_sinusoidal(c_hall_p1,  c_qei, c_signal, c_watchdog, 	\
							c_commutation_p1, c_commutation_p2, c_commutation_p3, c_pwm_ctrl,\
							p_ifm_esf_rstn_pwml_pwmh, p_ifm_coastn, p_ifm_ff1, p_ifm_ff2,\
							hall_params, qei_params, commutation_params);
				}

				/* Watchdog Server */
				run_watchdog(c_watchdog, p_ifm_wd_tick, p_ifm_shared_leds_wden);

				/* Hall Server */
				{
					hall_par hall_params;
					init_hall_param(hall_params);
					run_hall(c_hall_p1, c_hall_p2, c_hall_p3, c_hall_p4, c_hall_p5, c_hall_p6, p_ifm_hall, hall_params); // channel priority 1,2..4
				}
			}
		}

	}

	return 0;
}
