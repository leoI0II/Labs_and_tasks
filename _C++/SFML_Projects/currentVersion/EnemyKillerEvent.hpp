#ifndef ENEMYKILLEREVENT_HPP
#define ENEMYKILLEREVENT_HPP

template<int N>
class EnemyKillerEvent
{
public:
	bool operator()(int);
};


#endif //ENEMYKILLEREVENT_HPP

template<int N>
inline bool EnemyKillerEvent<N>::operator()(int kills)
{
	return N == kills;
}
