//
// Created by moon on 25.08.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "HowManyCharIsDuplicated.h"

TEST(HowManyCharIsDuplicated, ReturnExceptionIfEmptyString) {
    ASSERT_THROW(HowManyCharIsDuplicated(""), EmptyStringException );
}

TEST(HowManyCharIsDuplicated, ZeroDupliactesForOneSizeString) {
    EXPECT_THAT(HowManyCharIsDuplicated("A"), testing::Eq(0) );
}

TEST(HowManyCharIsDuplicated, IgnoreNotAlphabeticCharacters) {
    EXPECT_THAT(HowManyCharIsDuplicated("#####"), testing::Eq(0) );
}

TEST(HowManyCharIsDuplicated, NotDistinguishCapitalAndSmallLetters) {
    EXPECT_THAT(HowManyCharIsDuplicated("Aa"), testing::Eq(1) );
}

TEST(HowManyCharIsDuplicated, CheckingIfReturnIsCorrect) {
    EXPECT_THAT(HowManyCharIsDuplicated("AAA"), testing::Eq(1) );
    EXPECT_THAT(HowManyCharIsDuplicated("ABCDAC"), testing::Eq(2) );
    EXPECT_THAT(HowManyCharIsDuplicated("C++ vs C"), testing::Eq(1) );
}
