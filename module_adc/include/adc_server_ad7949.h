/**
 * \file adc_server_ad7949.h
 * \brief ADC Server
 * \authors Martin Schwarz <mschwarz@synapticon.com>, Ludwig Orgler <lorgler@synapticon.com> 
 */

#pragma once
#include <xs1.h>
#include <xclib.h>
#include "adc_common.h"

/**
 * \brief Non triggered ADC server
 *
 *
 * This server should be used if the somanet node is not used for motor
 * drive/control. This is the interface to AD7949 ADC devices. It controls
 * two devices so that two channels can be sampled simultaneously.
 *
 * \param c_adc channel to receive ADC output
 * \param clk clock for the ADC device serial port
 * \param p_sclk_conv_mosib_mosia 4-bit port for ADC control interface
 * \param p_data_a 1-bit port for ADC data channel 0
 * \param p_data_b 1-bit port for ADC data channel 1
 *
 */
void adc_ad7949( chanend c_adc,
			     clock clk,
			     buffered out port:32 p_sclk_conv_mosib_mosia,
			     in buffered port:32 p_data_a,
			     in buffered port:32 p_data_b );


/**
 * \brief Triggered ADC server
 *
 * This server should be used if the somanet node is used for motor
 * drive/control. This is the interface to AD7949 ADC devices.
 * It controls two devices so that two channels can be sampled
 * simultaneously.
 *
 * \param	c_adc channel to receive ADC output
 * \param	c_trig channel to trigger adc from the PWM modules
 *
 * \param clk clock for the ADC device serial port
 *
 * \param p_sclk_conv_mosib_mosia 4-bit port for ADC control interface
 * \param p_data_a 1-bit port for ADC data channel 0
 * \param p_data_b 1-bit port for ADC data channel 1
 *
 */
void adc_ad7949_triggered( chanend c_adc,
			   	   	   	   chanend c_trig,
			   	   	   	   clock clk,
			   	   	   	   buffered out port:32 p_sclk_conv_mosib_mosia,
			   	   	   	   in buffered port:32 p_data_a,
			   	   	   	   in buffered port:32 p_data_b );
