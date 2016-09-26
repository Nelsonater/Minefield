/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, getInBoundsEmpty)
{
	Field minefield;
	
	ASSERT_EQ( EMPTY_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, getOutBounds)
{
	Field minefield;
	
	ASSERT_ANY_THROW( minefield.get(15,5) );
}

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, placeMineOutBounds)
{
	Field minefield;
	
	minefield.placeMine(11,5);
	ASSERT_ANY_THROW( minefield.get(11,5) );
}

TEST(FieldTest, safeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_FALSE( minefield.isSafe(4,5) );
}

TEST(FieldTest, safeEmptyInBounds)
{
	Field minefield;
	
	ASSERT_TRUE( minefield.isSafe(4,5) );
}

TEST(FieldTest, safeOutBounds)
{
	Field minefield;
	
	ASSERT_ANY_THROW( minefield.get(11,5) );
}

TEST(FieldTest, adjEmptyRevealed)
{
	Field minefield;
		
	minefield.revealAdjacent(5, 5);
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(4,5) );
}

TEST(FieldTest, notAdjRevealed)
{
	Field minefield;
		
	minefield.revealAdjacent(6, 7);
	ASSERT_EQ( EMPTY_HIDDEN, minefield.get(4,5) );
}