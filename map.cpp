#include "map.h"
#include"config.h"

Map::Map()
{
    map1.load(MAP1_PATH);
    map2.load(MAP2_PATH);
    startmap.load(STARTMAP_PATH);
    map_posY=0;
}
