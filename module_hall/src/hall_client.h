
/**
 *
 * \file hall_client.h
 *
 *	Hall Sensor Client
 *
 * Copyright (c) 2014, Synapticon GmbH
 * All rights reserved.
 * Author: Pavan Kanajar <pkanajar@synapticon.com>, Ludwig Orgler <lorgler@synapticon.com>
 *         & Martin Schwarz <mschwarz@synapticon.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Execution of this software or parts of it exclusively takes place on hardware
 *    produced by Synapticon GmbH.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the Synapticon GmbH.
 *
 */

#pragma once
#include <stdint.h>
#include <bldc_motor_config.h>
#include "hall_config.h"
#include <xs1.h>
#include <stdint.h>

/**
 * \brief Get position from Hall Server
 *
 *  Output channel
 * \channel c_hall for communicating with the Hall Server
 *
 *  Output
 * \return the position in the range [0 - 4095] which maps to [0 - 359]/pole-pairs
 */
int get_hall_position(chanend c_hall);

/**
 * \brief Get absolute position from Hall Server
 *
 * Output channel
 * \channel c_hall for communicating with the Hall Server
 *
 *  Output
 * \return the counted up position (compensates for pole-pairs and gear-ratio)
 * 		   in the range [0 - 4095] * pole-pairs * gear-ratio
 */
{int , int} get_hall_position_absolute(chanend c_hall);

/**
 * \brief Get Velocity from Hall Server
 *
 * Output channel
 * \channel c_hall for communicating with the Hall Server
 *
 *  Input
 * \param hall_params struct defines the pole-pairs and gear ratio
 *
 *  Output
 * \return the velocity in rpm from Hall Sensor
 */
int get_hall_velocity(chanend c_hall, hall_par &hall_params);

