# Curs 5

# MODULES
# when you import a module, everything that its not in a function gets executed ONCE

# when executed directly -> __name__ = __main__
# when executed using import -> __name__ = name of the module
print(__name__)  # --> __main__ (executed directly)

# PACKAGES
# packages must be grouped in folder, and in each folder a __init__.py must exist

# to use "from <module> import *" use __all__ in __init__.py
# __all__ = ["name1", name2"..] (holds a list of all modules that belongs to this package)

