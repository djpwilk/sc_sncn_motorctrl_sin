/*
 * write.c
 *
 *  Created on: May 2, 2012
 *      Author: pkanajar @ Synapticon
 *              30.01.2013 orgler
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test.h"


int input_torq(in_data *d )
{
	int torque;
	printf("enter torque\n");
	scanf("%d", &torque);
	d->set_torque = torque;
	return 1;
}


int input_pos(in_data *d)
{
	int position;
	printf("enter position\n");
	scanf("%d", &position);
	d->set_position = position;
	return 1;
}
int input_vel(in_data *d)
{
	int velocity;
	printf("enter velocity\n");
	scanf("%d", &velocity);
	d->set_velocity = velocity;
	return 1;
}

