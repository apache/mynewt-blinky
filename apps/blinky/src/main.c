/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#include "os/os.h"
#include "bsp/bsp.h"
#include "hal/hal_gpio.h"
#include <assert.h>
#include <string.h>
#ifdef ARCH_sim
#include <mcu/mcu_sim.h>
#endif

/* Init all tasks */
volatile int tasks_initialized;
int init_tasks(void);

/* Task 1 */
#define BLINKY_TASK_PRIO (1)
#define BLINKY_STACK_SIZE    OS_STACK_ALIGN(256)

struct os_task blinky_task;
os_stack_t blinky_stack[BLINKY_STACK_SIZE];
static volatile int g_task1_loops;

/* For LED toggling put all the LED PINS in an array */
int g_led_pins[8] = {LED_BLINK_PIN_1, LED_BLINK_PIN_2, LED_BLINK_PIN_3, LED_BLINK_PIN_4, LED_BLINK_PIN_5, LED_BLINK_PIN_6, LED_BLINK_PIN_7, LED_BLINK_PIN_8};


void
blinky_task_handler(void *arg)
{
    struct os_task *t;

    /* initialize all LED pins as output */
    int x;
    for(x = 0; x < 8; x++){
        hal_gpio_init_out(g_led_pins[x], 1);
    }
    int f = 0;

    while (1) {
        t = os_sched_get_current_task();
        assert(t->t_func == blinky_task_handler);

        ++g_task1_loops;

        /* Wait one hundred m-seconds */
        os_time_delay(100);

        /* Toggle the LED */
        hal_gpio_toggle(g_led_pins[f++]);
        f = (f > 7) ? 0 : f;
    }
}

/**
 * init_tasks
 *
 * Called by main.c after os_init(). This function performs initializations
 * that are required before tasks are running.
 *
 * @return int 0 success; error otherwise.
 */
int
init_tasks(void)
{
    os_task_init(&blinky_task, "blinky", blinky_task_handler, NULL,
            BLINKY_TASK_PRIO, OS_WAIT_FOREVER, blinky_stack, BLINKY_STACK_SIZE);

    tasks_initialized = 1;

    return 0;
}

/**
 * main
 *
 * The main function for the project. This function initializes the os, calls
 * init_tasks to initialize tasks (and possibly other objects), then starts the
 * OS. We should not return from os start.
 *
 * @return int NOTE: this function should never return!
 */
int
main(int argc, char **argv)
{
    int rc;

#ifdef ARCH_sim
    mcu_sim_parse_args(argc, argv);
#endif

    os_init();

    rc = init_tasks();
    os_start();

    /* os start should never return. If it does, this should be an error */
    assert(0);

    return rc;
}

