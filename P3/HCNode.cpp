#include "HCNode.hpp"
/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 *  
 * HCNode.cpp
 */


bool HCNode::operator<(const HCNode& other)
{
	return other.count < count;
}

bool comp(HCNode* one, HCNode* other)
{
	return other->count < one->count;
}
