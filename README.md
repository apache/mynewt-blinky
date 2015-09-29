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
core of the OS.  In order to update the tadpole repository, the make\_tadpole
script must be run: 

    $ cd larva;
    $ ./scripts/hatch_tadpole.sh ~/dev/larva ~/dev/tadpole 

Where ~/dev/larva is your larva directory, and ~/dev/tadpole is your tadpole directory. 

## Discussion 

For discussion on tadpole, please use the stack-dev mailing list (stack-dev@googlegroups.org), 
or join the discussion on Slack (https://newt-os.slack.com/) 
