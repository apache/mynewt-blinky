/**
 * Copyright (c) 2015 Runtime Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef H_HAL_SPIM_H_
#define H_HAL_SPIM_H_

#include <inttypes.h>

/**
 *
 * hal_spim_init()
 *
 * Sets up a SPI master port ready for data transfer.
 * Mapping logical port number to pins is dictated by BSP.
 */
int hal_spim_init(int port, int mode, int speed);

/*
 * hal_spim_select()/hal_spim_deselect.
 * Assert and deassert chip select for the target, respectively.
 */
int hal_spim_select(int port);
int hal_spim_deselect(int port);

/**
 *
 * hal_spim_txrx()
 * Initiate data transfer. Specify TX data or RX data, or both.
 */
int hal_spim_txrx(int port, void *tx_buf, int tx_len, void *rx_buf, int rx_len);

#endif /* H_HAL_SPIM_H_ */
