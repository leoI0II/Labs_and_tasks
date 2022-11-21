#ifndef TIMEEVENT_HPP
#define TIMEEVENT_HPP

#include<chrono>

template<int N>
class TimeEvent
{
public:
	bool operator()(std::chrono::seconds& secs);
};


#endif //TIMEEVENT_HPP

template<int N>
inline bool TimeEvent<N>::operator()(std::chrono::seconds& secs)
{
	return std::chrono::seconds(N) <= secs;
}
