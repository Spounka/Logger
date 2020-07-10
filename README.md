# SE-Logger
SE-Logger is a small C++ class written for logging data to files

## Why another logging library ?
Because I'm writing a game for fun. I'm doing mostly 
everything myself for learning purposes and I'm making everything 
I think is needed by other people **Open Source** 
under **MIT-License**

### How does it Work ?
It's as simple as:
```c++
#include <Logger/logger.hpp>

void foo()
{
    SE::Util::Logger logger();
    logger.LogMessage("This is a logging test");
    logger.LogError("This is an Error in file");

    // Stuff goes here
    
    // Don't forget to destroy the instance after
    // finishing to free memory
    logger.Destroy();
}
```

This will create two files in the executable's directory:

*info.log* and *error.log* and ***append*** to them accordingly

## What doesn't it support ?
The TODO list:

- [ ] Outputting to custom file
- [ ] Outputting to custom directory
- [ ] Outputting to console

## Contact
Feel Free to contact me at:

[Facebook](https://facebook.com/spounka346)

[Twitter](https://twitter.com/boudaakkar)

Mail: boudaakkarnazih@gmail.com