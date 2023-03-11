/* 
 * File:   pid_controller.h
 * Author: Phil
 *
 * Created on 08 February 2023, 19:47
 */

#ifndef PID_CONTROLLER_H
#define	PID_CONTROLLER_H
#include <stdint.h>
typedef struct {

	/* Controller gains */
	int16_t Kp;
	int16_t Ki;
	int16_t Kd;

	/* Derivative low-pass filter time constant */
	int16_t tau;

	/* Output limits */
	int16_t limMin;
	int16_t limMax;
	
	/* Integrator limits */
	int16_t limMinInt;
	int16_t limMaxInt;

	/* Sample time (in seconds) */
	int16_t T;

	/* Controller "memory" */
	int16_t integrator;
	int16_t prevError;			/* Required for integrator */
	int16_t differentiator;
	int16_t prevMeasurement;		/* Required for differentiator */

	/* Controller output */
	int16_t out;

} PIDController;

#endif	/* PID_CONTROLLER_H */

