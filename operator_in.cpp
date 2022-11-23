/*      operator -- in -- implemantation        */

#ifndef _OPERATOR_IN_
#define _OPERATOR_IN_

class op_in_handler;

#define MANAGE_OPERATOR(side)										\
    template<typename T>											\
    struct side##Operator											\
    {																\
        typedef side##Operator ThisClass;							\
        ThisClass (const T& _oper) : oper(_oper) {}					\
        const T& oper;												\
    };																\
	void Set##side(void* __side)									\
	{																\
		__##side##_operator = __side;								\
	}																\
	void* __##side##_operator;										\
	template <typename T>											\
	friend const op_in_handler& operator *(const T& _##side##_op, const op_in_handler& handler) { handler.Set##side((void*) new side##Operator<T>(_left_op)); return handler; } \

class op_in_handler
{
private:
	
public:
	op_in_handler() {}

	MANAGE_OPERATOR(Left);
	MANAGE_OPERATOR(Right);

	operator bool() const
	{
		// for (const auto& __cont_element: static_cast<RightOperator<decltype()>*>(__Right_operator))
	}

	//template<typename T>
	//friend op_in_handler& operator *(const T& _left_op, const op_in_handler& handler)
	//{
	//	handler.SetLeft((void*) new LeftOperator<T>(_left_op));
	//	return handler;
	//}

	//template<typename T>
	//friend op_in_handler& operator *(const op_in_handler& handler, const T& _right_op)
	//{
	//	handler.__right_operator = (void*) new RightOperator<T>(_right_op);
	//	return handler;
	//}
};


#define in  *operator_in_handler()*


#endif