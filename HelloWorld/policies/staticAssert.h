#pragma once

template<bool>
class STATIC_CHECK_CLASS
{
public:
	STATIC_CHECK_CLASS(...){}
};

template<>
class STATIC_CHECK_CLASS <false>
{
public:
	STATIC_CHECK_CLASS() {}
};

#define STATIC_ASSERT(exp, msg)		\
{									\
	class ERROR_##msg				\
{									\
public:								\
	ERROR_##msg(){}					\
};									\
(void)(STATIC_CHECK_CLASS<(exp)>((ERROR_##msg())));	\
}									

// casting to void force compiler to treat this statement as variable declaration. otherwise compiler treats the statement as function prototype STATIC_CHECK_CLASS ERROR_##msg(void)

template<typename To, typename From>
To Safe_Cast(From from)
{
	STATIC_ASSERT(sizeof(To) >= sizeof(From), DEST_SIZE_IS_LESS);
	return (To)from;
}
