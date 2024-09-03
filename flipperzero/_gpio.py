GPIO_PIN_PC0: int
'''
Constant identifier for GPIO pin PC0.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PC1: int
'''
Constant identifier for GPIO pin PC1.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PC3: int
'''
Constant identifier for GPIO pin PC3.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PB2: int
'''
Constant identifier for GPIO pin PB2.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PB3: int
'''
Constant identifier for GPIO pin PB3.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PA4: int
'''
Constant identifier for GPIO pin PA4.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PA6: int
'''
Constant identifier for GPIO pin PA6.
    
.. versionadded:: 1.2.0
'''

GPIO_PIN_PA7: int
'''
Constant identifier for GPIO pin PA7.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_INPUT: int
'''
Constant configuration value for the GPIO input mode.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_OUTPUT_PUSH_PULL: int
'''
Constant configuration value for the GPIO output as push-pull mode.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_OUTPUT_OPEN_DRAIN: int
'''
Constant configuration value for the GPIO output as open-drain mode.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_ANALOG: int
'''
Constant configuration value for the GPIO analog mode.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_INTERRUPT_RISE: int
'''
Constant configuration value for the GPIO interrupt on rising edges mode.
    
.. versionadded:: 1.2.0
'''

GPIO_MODE_INTERRUPT_FALL: int
'''
Constant configuration value for the GPIO interrupt on falling edges mode.
    
.. versionadded:: 1.2.0
'''

def gpio_init_pin(pin: int, mode: int) -> None:
    '''
    Initialize a GPIO pin.

    :param pin: The pin to initialize (e.g. :const:`GPIO_PIN_PA4`).
    :param mode: The mode to use (e.g. :const:`GPIO_MODE_OUTPUT_PUSH_PULL`).
    
    .. versionadded:: 1.2.0

    .. hint::

        The interrupt modes :const:`GPIO_MODE_INTERRUPT_RISE` and :const:`GPIO_MODE_INTERRUPT_FALL` can be combined using bitwise OR.
        This allows you to handle rising `and` falling edges.
    '''
    pass

def gpio_set_pin(pin: int, state: bool) -> None:
    '''
    Set the state of an output pin.

    :param pin: The pin to set (e.g. :const:`GPIO_PIN_PA4`).
    :param state: The state to set.
    
    .. versionadded:: 1.2.0

    .. hint::

        Don't forget to initialize the pin first.
    '''
    pass

def gpio_get_pin(pin: int) -> bool:
    '''
    Read the state of an input pin.

    :param pin: The pin to read (e.g. :const:`GPIO_PIN_PA4`).
    :returns: :const:`True` if the pin is high, :const:`False` on a low signal.
    
    .. versionadded:: 1.2.0

    .. hint::

        Don't forget to initialize the pin first.
    '''
    pass
