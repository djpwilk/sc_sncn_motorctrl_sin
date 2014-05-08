
/**
 * \file test_qei.xc
 * \brief Test illustrates usage of qei sensor to get position and velocity information
 * \author Pavan Kanajar <pkanajar@synapticon.com>
 * \author Martin Schwarz <mschwarz@synapticon.com>
 * \version 1.0
 * \date 10/04/2014
 */

#include <xs1.h>
#include <platform.h>
#include <print.h>
#include <ioports.h>
#include <qei_client.h>
#include <qei_server.h>
#include <refclk.h>
#include <xscope.h>
#include <bldc_motor_config.h>
//#define ENABLE_xscope

#define COM_CORE 0
#define IFM_CORE 3


void xscope_initialise_1()
{
	{
		xscope_register(2, XSCOPE_CONTINUOUS, "0 qei_position", XSCOPE_INT,	"n",
				           XSCOPE_CONTINUOUS, "1 qei_velocity", XSCOPE_INT,	"n");
	}
	return;
}

/* Test QEI Sensor Client */
void qei_test(chanend c_qei)
{
	int position;
	int velocity;
	int direction;
	int core_id = 1;
	timer t;
	int index_count;
	int count=0;
	qei_par qei_params;
	qei_velocity_par qei_velocity_params;  			// to compute velocity from qei
	init_qei_param(qei_params);
	init_qei_velocity_params(qei_velocity_params);

#ifdef ENABLE_xscope
	xscope_initialise_1();
#endif

	while(1)
	{
		/* get position from QEI Sensor */
		{position, direction} = get_qei_position_absolute(c_qei);

		/* calculate velocity from QEI Sensor position */
		velocity = get_qei_velocity(c_qei, qei_params, qei_velocity_params);

		wait_ms(1, core_id, t);
	#ifdef ENABLE_xscope
		xscope_core_int(0, position);
		xscope_core_int(1, velocity);
	#else
		printstr("Position: ");
		printint(position);
		printstr(" ");
		printstr("Velocity: "); // with print velocity information will be corrupt (use xscope)
		printintln(velocity);
	#endif
	}
}

int main(void)
{
	chan c_qei_p1, c_qei_p2, c_qei_p3, c_qei_p4, c_qei_p5, c_qei_p6;				// qei channels

	par
	{
		on tile[0]:
		{
			/* Test QEI Sensor Client */
			qei_test(c_qei_p1);
		}

		/************************************************************
		 * IFM_CORE
		 ************************************************************/
		on tile[IFM_CORE]:
		{
			/* QEI Server Loop */
			{
				qei_par qei_params;
				init_qei_param(qei_params);
				run_qei(c_qei_p1, c_qei_p2, c_qei_p3, c_qei_p4, c_qei_p5, c_qei_p6, p_ifm_encoder, qei_params);  		// channel priority 1,2..6
			}
		}
	}

	return 0;
}
