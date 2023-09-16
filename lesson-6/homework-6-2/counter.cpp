
    #include "counter.h"

    Counter::Counter()   
    {
        value = 1;
    }

    Counter::Counter(int num)
    {
        value = num;        
    }

    void Counter::inc_value()
    {
        ++value;
    }

    void Counter::dec_value()
    {
        --value;
    }

    int Counter::get_value()
    {
        return value;
    }
