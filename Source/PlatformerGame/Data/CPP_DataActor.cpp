#include "CPP_DataActor.h"

const bool operator==(const FS_ItemInfo& left, const FS_ItemInfo& right)
{
	return left.ItemClass == right.ItemClass;
}