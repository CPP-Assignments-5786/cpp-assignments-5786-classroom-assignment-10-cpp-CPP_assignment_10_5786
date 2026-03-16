/**
 * @file TextAnalyzer.hpp
 * @brief Class for text analysis using STL algorithms
 *
 * This class analyzes text using STL algorithms on strings and
 * vectors of strings/characters.
 *
 * Topics covered:
 * - for_each, transform on characters
 * - count, count_if on characters
 * - find, find_if on strings
 * - sort, unique on word lists
 * - copy_if, remove_if for filtering
 * - accumulate for string building
 */

#ifndef TEXTANALYZER_HPP
#define TEXTANALYZER_HPP

#include <string>
#include <vector>
#include <map>

namespace datatools {

    class TextAnalyzer {
    private:
        std::string text;

    public:
        // ============ Constructor ============

        /**
         * @brief Constructor
         * @param text The text to analyze
         */
        explicit TextAnalyzer(const std::string& text);

        // ============ Getter ============

        const std::string& getText() const;

        // ============ Character Analysis ============

        /**
         * @brief Count the number of vowels (a, e, i, o, u — case insensitive)
         */
        int countVowels() const;

        /**
         * @brief Count the number of consonants (alphabetic non-vowels)
         */
        int countConsonants() const;

        /**
         * @brief Count the number of digits
         */
        int countDigits() const;

        /**
         * @brief Count the number of whitespace characters
         */
        int countSpaces() const;

        /**
         * @brief Count occurrences of a specific character (case-sensitive)
         */
        int countChar(char ch) const;

        /**
         * @brief Check if all characters are alphabetic
         * Ignores spaces (returns true for strings with only letters and spaces).
         */
        bool isAlphaOnly() const;

        /**
         * @brief Check if the text contains any digit
         */
        bool hasDigits() const;

        // ============ Transformations ============

        /**
         * @brief Return the text converted to uppercase
         */
        std::string toUpper() const;

        /**
         * @brief Return the text converted to lowercase
         */
        std::string toLower() const;

        /**
         * @brief Return the text reversed
         */
        std::string reversed() const;

        /**
         * @brief Return the text with all digits removed
         */
        std::string removeDigits() const;

        /**
         * @brief Return the text with all vowels removed
         */
        std::string removeVowels() const;

        /**
         * @brief Replace all occurrences of a character with another
         */
        std::string replaceChar(char from, char to) const;

        // ============ Word Analysis ============

        /**
         * @brief Split text into words (split by whitespace)
         */
        std::vector<std::string> getWords() const;

        /**
         * @brief Get all unique words (sorted alphabetically, case-insensitive)
         * Words are compared in lowercase for uniqueness and sorting.
         * The returned words are stored in lowercase.
         */
        std::vector<std::string> getUniqueWords() const;

        /**
         * @brief Get word frequency map
         * Words are stored in lowercase.
         */
        std::map<std::string, int> getWordFrequency() const;

        /**
         * @brief Get the longest word
         * @return The longest word, or "" if no words
         */
        std::string longestWord() const;

        /**
         * @brief Get the shortest word
         * @return The shortest word, or "" if no words
         */
        std::string shortestWord() const;

        /**
         * @brief Sort words by length (ascending)
         * @return Vector of words sorted by length
         */
        std::vector<std::string> wordsSortedByLength() const;

        /**
         * @brief Get words that are longer than a given length
         * @param minLength Minimum length (exclusive)
         * @return Vector of words longer than minLength
         */
        std::vector<std::string> wordsLongerThan(int minLength) const;

        /**
         * @brief Join all words back into a string with a separator
         * @param separator The separator (default: " ")
         * @return The joined string
         */
        std::string joinWords(const std::string& separator = " ") const;
    };

} // namespace datatools

#endif // TEXTANALYZER_HPP