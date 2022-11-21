/*      operator -- in -- implemantation        */

#ifndef _OPERATOR_IN_
#define _OPERATOR_IN_

#define MANAGE_OP (side) \
    template <typename T> \
    class side##Operator \
    { \
        public: \
            typedef side##Operator ThisClass; \
            ThisClass (const T& _oper) : oper(_oper) {} \
            const T& oper; \
    }; \

class op_in_handler
{
public:
    op_in_handler() {}

    MANAGE_OP(Left);
    MANAGE_OP(Right);

    template<typename T>
    friend const T& operator *(const T& _left_op, const op_in_handler& handler)
    {

    }
};


#define in  *operator_in_handler()*


#endif