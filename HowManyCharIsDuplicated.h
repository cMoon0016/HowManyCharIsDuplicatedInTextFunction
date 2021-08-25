//
// Created by moon on 25.08.2021.
//

#ifndef HOWMANYCHARISDUPLICATED_WITH_TESTS_HOWMANYCHARISDUPLICATED_H
#define HOWMANYCHARISDUPLICATED_WITH_TESTS_HOWMANYCHARISDUPLICATED_H

#include "string"
#include "exception"
#include "map"
#include "cctype"
#include "algorithm"

struct EmptyStringException : public std::exception {
    const char* what() const throw () {
        return "";
    }
};

void ReturnExceptionIfStringIsEmpty(const std::string& text) {
    if ( text.empty() )
        throw EmptyStringException();
}

void TextToUpper(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(), ::toupper );
}
void CountNumberOfEachLetter( std::map<char, int>& LettersInTextMap, std::string& text ) {
    TextToUpper(text);

    for(auto v: text) {
        if ( !isalpha(v) )
            continue;

        if( LettersInTextMap.find(v) == LettersInTextMap.end() )
            LettersInTextMap[v] = 1;
        else
            ++LettersInTextMap[v];
    }
}

int CountHowManyLetterInMapIsDuplicated( const std::map<char, int>& LettersInTextMap ) {
    int counter = 0;
    for (auto v: LettersInTextMap) {
        if ( v.second >= 2 )
            ++counter;
    }
    return counter;
}

int HowManyCharIsDuplicated( std::string text ) {
    ReturnExceptionIfStringIsEmpty(text);

    std::map<char, int> LettersInTextMap;
    CountNumberOfEachLetter(LettersInTextMap, text);

    return CountHowManyLetterInMapIsDuplicated(LettersInTextMap);
}

#endif //HOWMANYCHARISDUPLICATED_WITH_TESTS_HOWMANYCHARISDUPLICATED_H
