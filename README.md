<!--
#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#  KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#
-->

# README 

Tadpole is the repository that hosts the core of the operating system distribution.  
This repository is the base skeleton on which all other OS distributions are created.

Tadpole is automatically created from Larva (https://github.com/mynewt/larva) using the 
"hatch\_tadpole.sh" script (larva/scripts/hatch\_tadpole.sh).

It contains the following components: 

 * libs/os: The core RTOS, and ports to all supported chip platforms. 
 * hw/hal:  The HAL API definitions that all BSP and MCU implementations must support
 * hw/mcu/native: A MCU implementation for the native platform
 * hw/bsp/native: A BSP implementation for the native platform 
 * compiler/native: The definition of compiler support for the native platform.

The native platform currently supports compilation on Mac OS X.

## Using Tadpole 

Tadpole is a skeleton repository that is used by the newt tool to create a 
new repository for development.  

By default, the newt tool will use the tadpool skeleton when creating a new 
repository: 

    $ newt create repo <your_project> 

This will create a new project with the name of your\_project, which has 
the layout of the tadpole repository. 

## Updating Tadpole 

Development of the core operating system is done on larva, which contains the 
core of the OS.  In order to update the tadpole repository, the hatch\_tadpole
script must be run: 

    $ cd larva
    $ ./scripts/hatch_tadpole.sh ~/dev/larva ~/dev/tadpole 

Where ~/dev/larva is your larva directory, and ~/dev/tadpole is your tadpole directory. 

## Discussion 

For discussion on tadpole, please use the stack-dev mailing list (dev@mynewt.incubator.apache.org).
